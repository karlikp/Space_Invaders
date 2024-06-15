#include "Headers/Enemy3.h"

Enemy3::Enemy3(float x, float y, float scale)
    : Enemy(x, y) {

	entityBulletTexture.loadFromFile("Resources/enemyBullet3.png");
	entityTexture.loadFromFile("Resources/Enemy3.png");

	entityBulletSprite.setTexture(entityBulletTexture);
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);
}

void Enemy3::update()
{
	this->entitySprite.setPosition(this->position);
}

void Enemy3::shoot()
{//TO DO
}

void Enemy3::draw()
{//TO DO
}
