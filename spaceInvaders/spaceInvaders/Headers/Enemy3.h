#pragma once

#include "Enemy.h"


class Enemy3 : Enemy
{
	Enemy3();
	~Enemy3();

	void update() override;
	void shoot() override;
	void rendering() override;
};

