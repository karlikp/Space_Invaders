#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Global.h"

#include <string>

class Player : public Entity
{	
	int currentDamage, reloadTimer, powerupTimer, activePower;
	std::string name;
	unsigned health, points;




public:

	Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	~Player() = default;

	void update() /*override*/;
	void draw() /*override*/;

	sf::IntRect getHitbox();
	//void reset();
	/*void moveInputs();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();*/
};

