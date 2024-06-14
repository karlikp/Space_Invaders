#pragma once

#include "Enemy.h"


class Enemy1 : public Enemy
{
public:
	Enemy1();
	Enemy1(float x, float y);
	~Enemy1() = default;

	void update() /*override*/;
	void shoot() /*override*/;
	void draw() /*override*/;
};

