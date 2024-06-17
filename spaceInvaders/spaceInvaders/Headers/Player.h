#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Global.h"
//#include "EntityManager.h"

#include <string>

class Player : public Entity
{	
	int currentDamage, reloadTimer, powerupTimer, activePower,
		powerupType;
	std::string name;
	unsigned health, points;




public:

	Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	Player(float iPosX, float iPosY, float iStepX, float iStepY, EntityManager* manager);
	~Player() = default;

	void update() /*override*/;
	void draw() /*override*/;

	sf::IntRect getHitbox() ;
	//void reset();
	/*void moveInputs();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();*/
};

