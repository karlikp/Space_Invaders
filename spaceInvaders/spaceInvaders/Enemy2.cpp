#include "Headers/Enemy2.h"

Enemy2::Enemy2(float x, float y, float scale)
    : Enemy(x, y) {

	entityBulletTexture.loadFromFile("Resources/enemyBullet2.png");
	entityTexture.loadFromFile("Resources/Enemy2.png");

	entityBulletSprite.setTexture(entityBulletTexture);
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);
}

void Enemy2::update()
{
	this->entitySprite.setPosition(this->position);
}

void Enemy2::shoot()
{//TO DO
}

void Enemy2::draw()
{//TO DO
}
