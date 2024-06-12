#include "Headers/Enemy3.h"

Enemy3::Enemy3(short x, short y)
    : Enemy(x, y) {

	enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy3.png");

	enemyBulletSprite.setTexture(enemyBulletTexture);
	enemySprite.setTexture(enemyTexture);
}

void Enemy3::update()
{//TO DO
}

void Enemy3::shoot()
{//TO DO
}

void Enemy3::rendering()
{//TO DO
}
