#include "Headers/Enemy2.h"
#include "Headers/Global.h"
#include "Headers/EntityManager.h"

Enemy2::Enemy2(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LITTLE_HEALTH) {

	points = 20;
	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	//setShootPossibility(0.04);
	setEntitySprite("Resources/Enemy2.png");
	setEntityBulletSprite("Resources/enemyBullet2.png");
	setEntityScale(scale);
}

void Enemy2::update()
{
	setEntityPosition();
}

void Enemy2::shoot()
{
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (0.125f* BULLET_SPEED_Y), BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (-0.125f * BULLET_SPEED_Y), BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
}

void Enemy2::draw()
{//TO DO
}

int Enemy2::getPoints()
{
	return points;
}
