#include <random>

#include "../headers/EntityManager.h"
#include "../headers/Enemy.h"
#include "../headers/Global.h"

int Enemy::enemyCounter = 0;

Enemy::Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, int iHealth )
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {
	initY = iPosY;
	downLevel = 0;
	enemyCounter++;
	screenSize = iScreenSize;
	health = iHealth;
	direction = RIGHT_MOVE;
}

void Enemy::update()
{

	std::random_device rd;
	std::mt19937_64 randomEngine(rd());
	std::bernoulli_distribution shootPossibility = getPossibility();

	//shoots generator
	if (shootPossibility(randomEngine) == true) {
		shoot();
	}

	move();
	
	setEntityPosition();
}

void Enemy::move()
{
	if (direction != DOWN_MOVE)
	{
		if ((direction == RIGHT_MOVE && getX() >= screenSize.x - (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y) || (direction == LEFT_MOVE && getX() <= GAP_RATIO * screenSize.y))
		{
			direction = DOWN_MOVE;
			downLevel++;

			setY(getY()+ getStepY());
		}
		else
		{
			//restrice value, down scope, up scope
			setX(std::clamp<short>(getX() + getStepX() * direction, GAP_RATIO * screenSize.y, screenSize.x -  (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y));
		}
	}
	else
	{
		setY(std::min<short>(getY() + getStepY(), initY + (downLevel * ENEMY_OFFSET_RATIO * screenSize.y) ));

		if (int(getY()) == int(initY + downLevel * ENEMY_OFFSET_RATIO * screenSize.y))
		{
			//Moving in a snake pattern. We use the modulo operator to decide whether to move left or right.
			direction = 0 == downLevel % 2 ? 1 : -1;
		}
	}
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

short Enemy::getDownLevel()
{
	return downLevel;
}
