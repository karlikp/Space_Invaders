#include "../headers/Enemy2.h"
#include "../headers/Global.h"
#include "../headers/EntityManager.h"

Enemy2::Enemy2(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LITTLE_HEALTH) {

	points = 20;
	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setPossibility(0.0008);
	setEntitySprite("../resources/textures/enemy2.png");
	setEntityBulletSprite("../resources/textures/enemyBullet2.png");
	setEntityScale(scale);
}

void Enemy2::shoot()
{
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (0.125f* BULLET_SPEED), -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (-0.125f * BULLET_SPEED), -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
}

int Enemy2::getPoints()
{
	return points;
}
