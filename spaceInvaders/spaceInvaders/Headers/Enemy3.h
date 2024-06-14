#pragma once

#include "Enemy.h"


class Enemy3 : public Enemy
{
public:

	Enemy3(float x, float y);
	~Enemy3() = default;

	void update() /*override*/;
	void shoot() /*override*/;
	void draw() /*override*/;
};

