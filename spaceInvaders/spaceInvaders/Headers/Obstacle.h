#pragma once

#include "Entity.h"

class Obstacle : public Entity
{
public:
	Obstacle() = default;
	Obstacle(float x, float y, float scale);
	~Obstacle() = default;

	void update() /*override*/;
	void draw() /*override*/;
};

