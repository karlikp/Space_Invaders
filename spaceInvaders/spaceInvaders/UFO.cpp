#include "Headers/UFO.h"

UFO::UFO(float x, float y) : Entity(x, y) {

	entityTexture.loadFromFile("Resources/UFO.png");
	entitySprite.setTexture(entityTexture);
}

void UFO::update()
{//TO DO
}

void UFO::draw()
{//TO DO
}
