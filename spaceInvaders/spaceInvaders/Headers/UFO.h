#pragma once

#include "Entity.h"

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

