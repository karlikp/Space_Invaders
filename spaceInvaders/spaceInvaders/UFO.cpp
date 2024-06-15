#include "Headers/UFO.h"

UFO::UFO(float x, float y, float scale) : Entity(x, y) {

	entityTexture.loadFromFile("Resources/UFO.png");
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);
}

void UFO::update()
{
	this->entitySprite.setPosition(this->position);
}

void UFO::draw()
{//TO DO
}
