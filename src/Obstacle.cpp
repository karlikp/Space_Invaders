#include "../headers/Obstacle.h"
#include "../headers/Entity.h"
#include "../headers/EntityManager.h"
#include "../headers/Global.h"

Obstacle::Obstacle(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	float scale = OBSTACLE_WIDTH_RATIO * iScreenSize.y / OBSTACLE_DEFAULT_WIDTH;

	health = 20;
	setEntitySprite("../resources/textures/obstacle.png");
	setEntityScale(scale);
}

void Obstacle::update()
{
	for (const auto& enemy : EntityManager::getEnemies())
	{
		if (getHitbox().intersects(enemy->getHitbox()))
		{
			enemy->setIsDead(true);
			setIsDead(true);
			break;
		}
	}

	for (const auto& enemyBullet : EntityManager::getEnemyBullets())
	{
		if (getHitbox().intersects(enemyBullet->getHitbox()))
		{
			health--;
			enemyBullet->setIsDead(true);
		}
		if (health == 0) {
			setIsDead(true);
			break;
		}
	}

	for (const auto& playerBullet : EntityManager::getPlayerBullets())
	{
		if (getHitbox().intersects(playerBullet->getHitbox()))
		{
			health--;
			playerBullet->setIsDead(true);
		}
		if (health == 0) {
			setIsDead(true);
			break;
		}
	}

	setEntityPosition();
}

sf::IntRect Obstacle::getHitbox()
{
	return sf::IntRect(getX() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		getY() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		(OBSTACLE_WIDTH_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(OBSTACLE_HEIGHT_RATIO) * getScreenSize().y);
}
