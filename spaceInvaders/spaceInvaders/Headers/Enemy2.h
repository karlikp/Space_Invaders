#pragma once

#include "Enemy.h"


class Enemy2 : public Enemy
{
public:

	Enemy2(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Enemy2() = default;

	void update() /*override*/;
	void shoot() /*override*/;
	void draw() /*override*/;
};

