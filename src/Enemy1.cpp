#include "../headers/Enemy1.h"
#include "../headers/Global.h"
#include "../headers/EntityManager.h"

Enemy1::Enemy1(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LITTLE_HEALTH) {

	points = 10;
	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setPossibility(0.0009);
	setEntitySprite("../resources/textures/enemy1.png");
	setEntityBulletSprite("../resources/textures/enemyBullet1.png");
	setEntityScale(scale);

}

void Enemy1::shoot()
{
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), MOTIONLESS_X, -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
}

int Enemy1::getPoints()
{
	return points;
}
;