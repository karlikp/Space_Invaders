#include "Headers/EntityManager.h"
#include "Headers/Enemy.h"
#include "Headers/Global.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, int iHealth )
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {
	enemyCounter++;
	health = iHealth;
	direction = RIGHT_MOVE;
}

void Enemy::update()
{
	/*auto randomEngine = *getRandomEnginePtr();
	auto shootPossibility = getShootPossibility();

	for (auto& const enemy : EntityManager::getEnemies())
	{
		if (shootPossibility(randomEngine) == true)
			enemy->shoot();
	}*/
	
}


sf::IntRect Enemy::getHitbox()
{
	return sf::IntRect(getX() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		getY() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		(ENEMY_SIZE_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(ENEMY_SIZE_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

int Enemy::getHealth()
{
	return health;
}

bool Enemy::killHit()
{
	health--;
	if (health <= 0) {
		return true;
	}
	return false;
}
