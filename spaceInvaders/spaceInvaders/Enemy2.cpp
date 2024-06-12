#include "Headers/Enemy2.h"

Enemy2::Enemy2(short x, short y)
    : Enemy(x, y) {

	enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy2.png");

	enemyBulletSprite.setTexture(enemyBulletTexture);
	enemySprite.setTexture(enemyTexture);
}

void Enemy2::update()
{//TO DO
}

void Enemy2::shoot()
{//TO DO
}

void Enemy2::rendering()
{//TO DO
}
