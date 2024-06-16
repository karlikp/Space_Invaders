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
