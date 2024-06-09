#pragma once

#include "Entity.h"

class Obstacle : Entity
{
public:
	Obstacle();
	~Obstacle();

	void update() override;
	void rendering() override;
};

