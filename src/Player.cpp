#include <random>

#include "../headers/Player.h"
#include "../headers/UFO.h"
#include "../headers/Global.h"
#include "../headers/Game.h"

bool Player::isDead;
bool Player::ufoInProgress;
short Player::points;
UFO* Player::tempUfo;
short Player::lives;


Player::Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, UFO* iUfo)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize),
	ufo(iUfo){

	
	float scale = (0.075 * iScreenSize.y) / PLAYER_DEFAULT_HEIGHT;
	initTempUfo();
	setEntitySprite("../resources/textures/playerShip1_blue.png");
	setEntityBulletSprite("../resources/textures/playerBullet1.png");
	setEntityScale(scale);;


	ufoInProgress = false;
	isDead = false;
	points = 0;
	lives = 3;
	currentDamage = 1;
	reloadTimer = RELOAD_TIME;
	activePower = NORMAL_STATE;
	powerupTimer = 0;
	powerupType = 0;
}

void Player::update()
{
	updateUfo();

	if (getIsDead() == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setX(std::max<int>(getX() - getStepX(), GAP_RATIO * getScreenSize().y));
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
		(std::make_unique<Bullet>(getX(), getY(), MOTIONLESS_X, BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));


		float bulletOffset = (BULLET_RATIO * getScreenSize().y);

		if (activePower == TRIPLE_SHOOT)
		{
			EntityManager::addPlayerBullet
			(std::make_unique<Bullet>(getX() - bulletOffset, getY(), MOTIONLESS_X, BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));
			EntityManager::addPlayerBullet
			(std::make_unique<Bullet>(getX() + bulletOffset, getY(), MOTIONLESS_X, BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), PLAYER_SIZE_RATIO));
			
		}
	}
	else
	{
		reloadTimer--;
	}
	//Check enemy hit
	
	for (const auto& enemyBullet : EntityManager::getEnemyBullets())
	{

		if (getHitbox().intersects(enemyBullet->getHitbox()))
		{
			lives--;
			enemyBullet->setIsDead(true);
		}
		if (lives == 0) {
			setIsDead(true);
			break;
		}
	}

	auto getHitboxPtr = getHitbox();

	powerupType = ufo->checkPowerupCollision(&getHitboxPtr);
	
	if (powerupType == 3) {
		if (lives < 3) {
			lives++;
			powerupType = 0;
		}
		else 
		powerupType = 2;
	}
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
	for (const auto& bullet : EntityManager::getPlayerBullets())
	{
		if (getIsDead() == false)
		{		
			if (ufo->checkBulletCollision(bullet->getHitbox()))
			{
				bullet->setIsDead(true);
				points += 100;
				
			}
		}
	}

	for (const auto& enemy : EntityManager::getEnemies())
	{
		for (const auto& bullet : EntityManager::getPlayerBullets())
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

void Player::updateUfo()
{
	std::random_device rd;
	std::mt19937_64 randomEngine(rd());
	std::bernoulli_distribution possibility = getPossibility();
	setPossibility(0.0003);

	//shoots generator
	if (ufoInProgress == false && possibility(randomEngine) == true) {
		ufoInProgress = true;
	}
	if (ufoInProgress == true) {
		ufo->update();
	}
	
}

void Player::initTempUfo()
{
	tempUfo = ufo;
}

UFO* Player::getUfo()
{
	return tempUfo;
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

short Player::getLives()
{
	return lives;
}

bool Player::getUfoInProgress()
{
	return ufoInProgress;
}

void Player::setUfoInProgress(bool state)
{
	ufoInProgress = state;
}

sf::IntRect Player::getHitbox() 
{
	return sf::IntRect(	
		getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(PLAYER_SIZE_RATIO - 2*HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

