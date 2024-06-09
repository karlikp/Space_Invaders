#pragma once

#include "Entity.h"

class UFO : public Entity
{
	bool isOnScreen;
	unsigned short powerupType;
	bool duringDestruction;

public:

	void update() override;
	void rendering() override;
	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

