#pragma once

#include "Enemy.h"


class Enemy2 : public Enemy
{
public:

	Enemy2(short x, short y);
	~Enemy2() = default;

	void update() override;
	void shoot() override;
	void rendering() override;
};

