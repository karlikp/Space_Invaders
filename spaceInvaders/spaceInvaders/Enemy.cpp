#include "Headers/Enemy.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {
	enemyCounter++;
};
