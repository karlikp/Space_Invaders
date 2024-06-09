#pragma once

#include "Enemy.h"


class Enemy2 : Enemy
{
public:
	Enemy2();
	~Enemy2();

	void update() override;
	void shoot() override;
	void rendering() override;
};

