#pragma once

#include "Enemy.h"


class Enemy3 : public Enemy
{
	int points;

public:

	Enemy3(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Enemy3() = default;

	void shoot() override;
	int getPoints() override;
};

