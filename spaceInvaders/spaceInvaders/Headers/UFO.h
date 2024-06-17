#pragma once

#include "Entity.h"

class UFO : public Entity
{
	bool isOnScreen;
	unsigned short powerupType;
	bool duringDestruction;

public:

	UFO(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~UFO() = default;
	void update() /*override*/;
	void draw() /*override*/;

	static float checkPowerupReach(sf::IntRect* i_player_hitbox);
	static bool checkBulletCollision(sf::IntRect* i_player_hitbox);
	static sf::IntRect getHitbox();
	bool randomArrived();
	int randomPowerup();
	bool bulletCollision();
	void destruction();
};

