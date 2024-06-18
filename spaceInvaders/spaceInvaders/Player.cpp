#include "Headers/Player.h"
#include "Headers/UFO.h"
#include "Headers/Global.h"
#include "Headers/Game.h"


Player::Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, std::unique_ptr<UFO>* iUfo)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	float scale = (0.075 * iScreenSize.y) / PLAYER_DEFAULT_HEIGHT;

	setEntitySprite("Resources/playerShip1_blue.png");
	setEntityBulletSprite("Resources/playerBullet1.png");
	setEntityScale(scale);

	ufo = iUfo;
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
	//auto enemyBullets = EntityManager::getEnemyBullets();

	for (auto& const enemy_bullet : EntityManager::getEnemyBullets())
	{
		if (getHitbox().intersects(enemy_bullet->getHitbox()))
		{
			health--;
		}
		if (health == 0) {
			setIsDead(true);
			break;
		}
	}


	
	auto getHitboxPtr = getHitbox();

	powerupType = (*ufo)->UFO::checkPowerupReach(&getHitboxPtr);

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
	//Hit UFO !TO DO!
	for (auto& const bullet : EntityManager::getPlayerBullets())
	{
		if (getIsDead() == false)
		{		
			 auto bulletHitbox = bullet->getHitbox();

			if ((*ufo)->checkBulletColision(&bulletHitbox))
			{
				bullet->setIsDead(true);
			}
		}
	}

	for (auto& const enemy : EntityManager::getEnemies())
	{
		for (auto& const bullet : EntityManager::getPlayerBullets())
		{
			if (bullet->getIsDead() == 0 && enemy->getHealth() > 0 && enemy->getHitbox().intersects(bullet->getHitbox()))
			{
				bullet->setIsDead(true);
				enemy->setIsDead(true);
				break;
			}
		}
	}

	setEntityPosition();
}

void Player::draw()
{
	
}

sf::IntRect Player::getHitbox() 
{
	return sf::IntRect(	
		getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

//void Player::reset()
//{//TO DO
//}
