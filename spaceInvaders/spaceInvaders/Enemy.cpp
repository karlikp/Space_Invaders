#include "Headers/Enemy.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy()
{
	enemyCounter++;
}

Enemy::Enemy(float x, float y) : Entity(x, y) {
	enemyCounter++;
};
