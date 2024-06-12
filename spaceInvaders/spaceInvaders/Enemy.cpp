#include "Headers/Enemy.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy(short x, short y) : Entity(x, y) {
	enemyCounter++;
};
