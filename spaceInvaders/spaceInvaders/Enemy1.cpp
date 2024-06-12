#include "Headers/Enemy1.h"

Enemy1::Enemy1(short x, short y)
    : Enemy(x, y) {

	enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy1.png");

	enemyBulletSprite.setTexture(enemyBulletTexture);
	enemySprite.setTexture(enemyTexture);
}

void Enemy1::update()
{ //TO DO
}
void Enemy1::shoot()
{//TO DO
}
void Enemy1::rendering()
{//TO DO
}
;