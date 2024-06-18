#pragma once

#include "Enemy.h"


class Enemy1 : public Enemy
{
	int points;
public:
	Enemy1(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Enemy1() = default;

	void update() /*override*/;
	void shoot() override;
	void draw() /*override*/;
	int getPoints() override;
};

