#include "Headers/Enemy2.h"
#include "Headers/Global.h"

Enemy2::Enemy2(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LITTLE_HEALTH) {

	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setEntitySprite("Resources/Enemy2.png");
	setEntityBulletSprite("Resources/enemyBullet2.png");
	setEntityScale(scale);
}

void Enemy2::update()
{
	setEntityPosition();
}

void Enemy2::shoot()
{//TO DO
}

void Enemy2::draw()
{//TO DO
}
