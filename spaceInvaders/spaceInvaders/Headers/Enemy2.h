#pragma once

#include "Enemy.h"


class Enemy2 : public Enemy
{
	int points;
public:

	Enemy2(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Enemy2() = default;

	void shoot() override;
	int getPoints() override;
};

