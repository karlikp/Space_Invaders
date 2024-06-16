#pragma once

#include "Entity.h"

class UFO : public Entity
{
	bool isOnScreen;
	unsigned short powerupType;
	bool duringDestruction;

public:

	UFO(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~UFO() = default;
	void update() /*override*/;
	void draw() /*override*/;
	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

