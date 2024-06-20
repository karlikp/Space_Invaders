#pragma once

#include "Entity.h"

class UFO : public Entity
{
	bool isOnScreen;
	short powerupType;
	bool duringDestruction;
	float x, y, stepX, stepY;
	sf::Vector2f screenSize;

	std::bernoulli_distribution shootPossibility;

public:

	UFO(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~UFO() = default;
	void update() override;


	short checkPowerupCollision(sf::IntRect* i_player_hitbox);
	bool checkBulletCollision(sf::IntRect i_player_hitbox);
	sf::IntRect getHitbox();
	short getPowerupType();


	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

