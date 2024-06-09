#pragma once

#include "Entity.h"


#include <random>

class Enemy : public Entity
{
	short direction;
	int health;
	static int enemyCounter;
	bool isDead;
	

public:
	Enemy(int x, int y);
	virtual ~Enemy() = default;

	// Wirtualna metoda do nadpisania w klasach pochodnych
	virtual void update() = 0;
	virtual void shoot() = 0;
	virtual void rendering() = 0;

	bool bulletCollision();
	int getDirection();
	int getHealth();
	int getEnemyCounter();
	int move();
	void hit();
};

