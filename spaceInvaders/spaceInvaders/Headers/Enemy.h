#pragma once

#include "Entity.h"

#include <vector>
#include <random>
#include <memory>

class Enemy : public Entity
{
	short direction;
	int health;
	static int enemyCounter;
	bool isDead;

public:

	sf::Sprite enemyBulletSprite;
	sf::Sprite enemySprite;

	sf::Texture enemyBulletTexture;
	sf::Texture enemyTexture;

	Enemy();
	Enemy(float x, float y);
	virtual ~Enemy() = default;

	// Wirtualna metoda do nadpisania w klasach pochodnych
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

