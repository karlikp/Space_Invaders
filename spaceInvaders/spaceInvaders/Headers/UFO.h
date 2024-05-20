#include "Entity.h"

#pragma once

class UFO : public Entity
{
	bool isOnScreen;
	unsigned short powerupType;
	bool duringDestruction;

public:

	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

