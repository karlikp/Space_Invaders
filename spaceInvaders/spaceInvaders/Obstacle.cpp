#include "Headers/Obstacle.h"
#include "Headers/Entity.h"
#include "Headers/Global.h"

Obstacle::Obstacle(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	float scale = OBSTACLE_WIDTH_RATIO * iScreenSize.y / OBSTACLE_DEFAULT_WIDTH;

	setEntitySprite("Resources/Obstacle.png");
	setEntityScale(scale);
}

void Obstacle::update()
{
	setEntityPosition();
}

void Obstacle::draw()
{//TO DO
}

sf::IntRect Obstacle::getHitbox()
{
	return sf::IntRect(getX() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		getY() + SMALL_HITBOX_MARGIN_RATIO * getScreenSize().y,
		(OBSTACLE_HEIGHT_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(OBSTACLE_HEIGHT_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y);
}
