#pragma once

#include "Enemy.h"


class Enemy3 : public Enemy
{
public:

	Enemy3(short x, short y);
	~Enemy3() = default;

	void update() override;
	void shoot() override;
	void rendering() override;
};

