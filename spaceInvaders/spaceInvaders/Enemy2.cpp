#include "Headers/Enemy2.h"

Enemy2::Enemy2(float x, float y)
    : Enemy(x, y) {

	entityBulletTexture.loadFromFile("Resources/enemyBullet2.png");
	entityTexture.loadFromFile("Resources/Enemy2.png");

	entityBulletSprite.setTexture(entityBulletTexture);
	entitySprite.setTexture(entityTexture);
}

void Enemy2::update()
{//TO DO
}

void Enemy2::shoot()
{//TO DO
}

void Enemy2::draw()
{//TO DO
}
