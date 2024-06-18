#include "Headers/Enemy1.h"
#include "Headers/Global.h"

Enemy1::Enemy1(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LITTLE_HEALTH) {

	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setEntitySprite("Resources/Enemy1.png");
	setEntityBulletSprite("Resources/enemyBullet1.png");
	setEntityScale(scale);

}

void Enemy1::update()
{
	setEntityPosition();
}
void Enemy1::shoot()
{//TO DO
}
void Enemy1::draw()
{//TO DO
}
;