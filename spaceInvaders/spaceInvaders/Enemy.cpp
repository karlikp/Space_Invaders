#include "Headers/Enemy.h"
#include "Headers/Global.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, int iHealth )
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {
	enemyCounter++;
	health = iHealth;
	direction = RIGHT_MOVE;
};

sf::IntRect Enemy::getHitbox()
{
	return sf::IntRect(getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(ENEMY_SIZE_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(ENEMY_SIZE_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

int Enemy::getHealth()
{
	return health;
}
