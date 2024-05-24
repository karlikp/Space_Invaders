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
	virtual bool bulletCollision();
	virtual int getDirection();
	virtual int getHealth();
	virtual int getEnemyCounter();
	virtual int move();
	virtual void shoot() = 0;
	virtual void hit();
};

