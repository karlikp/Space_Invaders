#include "Headers/Enemy3.h"
#include "Headers/Global.h"

Enemy3::Enemy3(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LOT_OF_HEALTH) {

	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setEntitySprite("Resources/Enemy3.png");
	setEntityBulletSprite("Resources/enemyBullet3.png");
	setEntityScale(scale);
}

void Enemy3::update()
{
	setEntityPosition();
}

void Enemy3::shoot()
{//TO DO
}

void Enemy3::draw()
{//TO DO
}
