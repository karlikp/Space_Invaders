#include "Headers/Enemy3.h"
#include "Headers/Global.h"
#include "Headers/EntityManager.h"

Enemy3::Enemy3(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Enemy(iPosX, iPosY, iStepX, iStepY, iScreenSize, LOT_OF_HEALTH) {

	points = 30;
	float enemySize = ENEMY_SIZE_RATIO * iScreenSize.y;
	float scale = enemySize / ENEMY_DEFAULT_HEIGHT;

	setPossibility(0.0005);
	setEntitySprite("Resources/Textures/Enemy3.png");
	setEntityBulletSprite("Resources/Textures/enemyBullet3.png");
	setEntityScale(scale);
}

void Enemy3::shoot()
{
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), MOTIONLESS_X, -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (0.25f * BULLET_SPEED), -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
	EntityManager::addEnemyBullet
	(std::make_unique<Bullet>(getX(), getY(), (-0.25f * BULLET_SPEED), -BULLET_SPEED, getScreenSize(), getEntityBulletSprite(), ENEMY_SIZE_RATIO));
}

void Enemy3::move()
{
	//old version
	if (downLevel < 2) {
		firstPath();
	}
	else
		secondPath();
}

void Enemy3::firstPath()
{
	if (direction == LEFT_MOVE or direction == RIGHT_MOVE)
	{
		if ((direction == RIGHT_MOVE && getX() >= screenSize.x - (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y))
		{
			direction = DOWN_MOVE;
			downLevel++;

			setY(getY() + getStepY());
		}
		else if (direction == LEFT_MOVE && getX() <= GAP_RATIO * screenSize.y)
		{

			direction = UP_MOVE;
			downLevel++;
			setY(getY() - getStepY());
		}
		else
		{
			//restrice value, down scope, up scope
			setX(std::clamp<short>(getX() + getStepX() * direction, GAP_RATIO * screenSize.y, screenSize.x - (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y));
		}
	}
	else
	{
		setY(std::min<short>(getY() + getStepY(), initY + (downLevel * ENEMY_OFFSET_RATIO * screenSize.y)));

		if (int(getY()) == int(initY + downLevel * ENEMY_OFFSET_RATIO * screenSize.y))
		{
			//Moving in a snake pattern. We use the modulo operator to decide whether to move left or right.
			direction = 0 == downLevel % 2 ? 1 : -1;
		}
	}
}

void Enemy3::secondPath()
{
	if (direction == RIGHT_MOVE or direction == LEFT_MOVE)
	{
		if ((direction == RIGHT_MOVE && getX() >= screenSize.x - (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y))
		{
			direction = DOWN_MOVE;
			setY(getY() + getStepY());
		}
		else if (direction == LEFT_MOVE && getX() <= GAP_RATIO * screenSize.y)
		{
			direction = UP_MOVE;
			setY(getY() - getStepY());
		}
		else
		{
			//restrice value, down scope, up scope
			setX(std::clamp<short>(getX() + getStepX() * direction, GAP_RATIO * screenSize.y, screenSize.x - (ENEMY_SIZE_RATIO + GAP_RATIO) * screenSize.y));
		}
	}
		//vertical
	else {
			short newY = getY() + (getStepY() * 0.5f * direction);
			short upperBound = NEW_PATH_LOW_BORDER * screenSize.y;
			short lowerBound = NEW_PATH_UP_BORDER * screenSize.y;

			newY = std::clamp<short>(newY, lowerBound, upperBound);
			setY(newY);

			if (int(getY()) == int(NEW_PATH_UP_BORDER * screenSize.y))
				direction = RIGHT_MOVE;
			else if (int(getY()) == int(NEW_PATH_LOW_BORDER * screenSize.y))
				direction = LEFT_MOVE;
	}
}

int Enemy3::getPoints()
{
	return points;
}
