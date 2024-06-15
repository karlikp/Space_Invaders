#pragma once

#include "Entity.h"

class UFO : public Entity
{
	bool isOnScreen;
	unsigned short powerupType;
	bool duringDestruction;

public:

	UFO() = default;
	UFO(float x, float y, float scale);
	~UFO() = default;
	void update() /*override*/;
	void draw() /*override*/;
	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

