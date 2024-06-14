#include "Headers/Enemy1.h"

Enemy1::Enemy1(){
	enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy1.png");

	enemyBulletSprite.setTexture(entityBulletTexture);
	enemySprite.setTexture(entityTexture);
}

Enemy1::Enemy1(float x, float y)
    : Enemy(x, y) {

	enemyBulletTexture.loadFromFile("Resources/enemyBullet1.png");
	enemyTexture.loadFromFile("Resources/Enemy1.png");

	enemyBulletSprite.setTexture(entityBulletTexture);
	enemySprite.setTexture(entityTexture);
}

void Enemy1::update()
{ //TO DO
}
void Enemy1::shoot()
{//TO DO
}
void Enemy1::draw()
{//TO DO
}
;