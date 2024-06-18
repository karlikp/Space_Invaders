#pragma once

#include "Enemy.h"


class Enemy3 : public Enemy
{
	int points;

public:

	Enemy3(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Enemy3() = default;

	void update() /*override*/;
	void shoot() override;
	void draw() /*override*/;
	int getPoints() override;
};

