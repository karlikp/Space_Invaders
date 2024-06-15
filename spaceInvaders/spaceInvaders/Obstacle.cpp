#include "Headers/Obstacle.h"
#include "Headers/Entity.h"

Obstacle::Obstacle(float x, float y, float scale)
	: Entity(x, y) {

	entityTexture.loadFromFile("Resources/Obstacle.png");
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);
}

void Obstacle::update()
{
	this->entitySprite.setPosition(this->position);
}

void Obstacle::draw()
{//TO DO
}
