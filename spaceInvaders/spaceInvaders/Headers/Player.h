#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Global.h"
#include "UFO.h"

#include <string>

class Player : public Entity
{	
	int currentDamage, reloadTimer, powerupTimer, activePower,
		powerupType;
	std::string name;
	int health, points;

	std::unique_ptr<UFO>** ufo;





public:

	Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, std::unique_ptr<UFO>** ufo);
	~Player() = default;

	void update() override;

	sf::IntRect getHitbox();

	//void reset();
	/*void moveInputs();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();*/
};

