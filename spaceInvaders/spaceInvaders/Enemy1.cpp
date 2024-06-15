#include "Headers/Enemy1.h"

Enemy1::Enemy1(){
	/*enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy1.png");

	enemyBulletSprite.setTexture(entityBulletTexture);
	enemySprite.setTexture(entityTexture);*/
}

Enemy1::Enemy1(float x, float y, float scale)
    : Enemy(x, y) {

	entityBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	entityTexture.loadFromFile("Resources/Enemy1.png");

	entityBulletSprite.setTexture(entityBulletTexture);
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);

}

void Enemy1::update()
{
	this->entitySprite.setPosition(this->position);
}
void Enemy1::shoot()
{//TO DO
}
void Enemy1::draw()
{//TO DO
}
;