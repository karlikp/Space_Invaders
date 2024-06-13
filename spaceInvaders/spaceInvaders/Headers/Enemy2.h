#pragma once

#include "Enemy.h"


class Enemy2 : public Enemy
{
public:

	Enemy2(float x, float y);
	~Enemy2() = default;

	void update() override;
	void shoot() override;
	void rendering() override;
};

