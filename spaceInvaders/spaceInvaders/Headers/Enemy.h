#pragma once

#include "Entity.h"

#include <vector>
#include <random>
#include <memory>

// I created the Enemy class to increase readable of my program
class Enemy : public Entity
{
	sf::Vector2f screenSize;
	float initY;
	short direction, downLevel; 
	int health;
	static int enemyCounter;

public:

	Enemy(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, int iHealth);
	virtual ~Enemy() = default;

	void update();
	void move();
	virtual void shoot() = 0;
	virtual int getPoints() = 0;

	sf::IntRect getHitbox();
	int getHealth();
	bool killHit();


	int getDirection();
	int getEnemyCounter();
	
	
};

