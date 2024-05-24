#pragma once

#include "Enemy.h"


class Enemy1 : public Enemy
{
public:
	Enemy1(int x, int y);
	
	~Enemy1();

	void update() override;
};

