#pragma once

#include "Entity.h"

class Obstacle : public Entity
{
	int health;
public:
	Obstacle() = default;
	Obstacle(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Obstacle() = default;

	void update() override;
	sf::IntRect getHitbox();
};

