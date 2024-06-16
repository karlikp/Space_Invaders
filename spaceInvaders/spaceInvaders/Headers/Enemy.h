#pragma once

#include "Entity.h"

#include <vector>
#include <random>
#include <memory>

// I created the Enemy class to increase readable of my program
class Enemy : public Entity
{
	short direction;
	int health;
	static int enemyCounter;
	bool isDead;

public:

	Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	virtual ~Enemy() = default;

	virtual void update() = 0;
	virtual void shoot() = 0;
	virtual void draw() = 0;

	bool bulletCollision();
	int getDirection();
	int getHealth();
	int getEnemyCounter();
	int move();
	void hit();
};

