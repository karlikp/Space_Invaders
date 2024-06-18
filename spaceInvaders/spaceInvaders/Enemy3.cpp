#include "Headers/Enemy3.h"
#include "Headers/Global.h"
#include "Headers/EntityManager.h"

Enemy3::Enemy3(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LOT_OF_HEALTH) {

	points = 30;
	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setShootPossibility(0.0005);
	setEntitySprite("Resources/Enemy3.png");
	setEntityBulletSprite("Resources/enemyBullet3.png");
	setEntityScale(scale);
}

void Enemy3::shoot()
{
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), MOTIONLESS_X, -BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (0.25f * BULLET_SPEED_Y), -BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (-0.25f * BULLET_SPEED_Y), -BULLET_SPEED_Y, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
}

int Enemy3::getPoints()
{
	return points;
}
