#include "Headers/Player.h"
#include "Headers/UFO.h"
#include "Headers/Global.h"
#include "Headers/Game.h"

bool Player::isDead;
short Player::points;

Player::Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, std::unique_ptr<UFO>** iUfo)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize),
	ufo(iUfo){

	float scale = (0.075 * iScreenSize.y) / PLAYER_DEFAULT_HEIGHT;

	setEntitySprite("Resources/playerShip1_blue.png");
	setEntityBulletSprite("Resources/playerBullet1.png");
	setEntityScale(scale);

	if ((**ufo) == nullptr) {
		std::cout << "nullptr\n";
	}

	isDead = false;
	points = 0;
	health = 3;
	currentDamage = 1;
	reloadTimer = RELOAD_TIME;
	activePower = NORMAL_STATE;
	powerupTimer = 0;
	powerupType = 0;
}

void Player::update()
{

	if (getIsDead() == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setX(std::max<int>(getX() - getStepX(), GAP_RATIO * getScreenSize().y/*screenHeight*/));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			setX(std::min<int>(getX() + getStepX(), (getScreenSize().x - ((0.075 + GAP_RATIO) * getScreenSize().y))));
		}
	}

	if (reloadTimer == 0)
	{
		
		if (activePower == FASTER_RELOAD)
		{
			reloadTimer = FAST_RELOAD_TIME;
		}
		else
		{
			reloadTimer = RELOAD_TIME;
		}
			
		EntityManager::addPlayerBullet
		(std::make_unique<Bullet>(getX(), getY(), MOTIONLESS_X, BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));


		float bulletOffset = (BULLET_RATIO * getScreenSize().y) / BULLET_DEFAULT_HEIGHT;

		if (activePower == TRIPLE_SHOOT)
		{
			EntityManager::addPlayerBullet
			(std::make_unique<Bullet>(getX() - bulletOffset, getY(), MOTIONLESS_X, BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));
			EntityManager::addPlayerBullet
			(std::make_unique<Bullet>(getX() + bulletOffset, getY(), MOTIONLESS_X, BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));
			
		}
	}
	else
	{
		reloadTimer--;
	}
	//Check enemy hit
	
	for (auto& const enemyBullet : EntityManager::getEnemyBullets())
	{
		if (getHitbox().intersects(enemyBullet->getHitbox()))
		{
			health--;
			enemyBullet->setIsDead(true);
		}
		if (health == 0) {
			setIsDead(true);
			break;
		}
	}

	auto getHitboxPtr = getHitbox();

	powerupType = (**ufo)->checkPowerupReach(&getHitboxPtr);

	if (powerupType > 0)
	{
		activePower = powerupType;
		powerupTimer = POWERUP_DURATION;
	}

	if (0 == powerupTimer)
	{
		activePower = 0;
	}
	else
	{
		powerupTimer--;
	}
	//Hit UFO 
	for (auto& const bullet : EntityManager::getPlayerBullets())
	{
		if (getIsDead() == false)
		{		
			if ((*ufo) == nullptr)
			{
				std::cerr << "WskaŸnik UFO jest null!" << std::endl;
			}
			 auto bulletHitbox = bullet->getHitbox();

			if ((**ufo)->checkBulletColision(&bulletHitbox))
			{
				bullet->setIsDead(true);
			}
		}
	}

	for (auto& const enemy : EntityManager::getEnemies())
	{
		for (auto& const bullet : EntityManager::getPlayerBullets())
		{
			if (bullet->getIsDead() == 0 && enemy->getHealth() > 0 && enemy->getHitbox().intersects(getHitbox()))
			{
				setIsDead(true);
			}
			if (bullet->getIsDead() == 0 && enemy->getHealth() > 0 && enemy->getHitbox().intersects(bullet->getHitbox()))
			{
				bullet->setIsDead(true);

				if (enemy->killHit()) {

					enemy->setIsDead(true);
					points += enemy->getPoints();
				}
				break;
			}
		}
	}

	

	setEntityPosition();
}

void Player::setIsDead(bool state)
{
	isDead = state;
}

bool Player::getIsDead()
{
	return isDead;
}

short Player::getPoints()
{
	return points;
}

sf::IntRect Player::getHitbox() 
{
	return sf::IntRect(	
		getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

