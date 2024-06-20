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
	static short lives;
	static short points;
	static bool isDead;
	static bool ufoInProgress;
	UFO* ufo;
	static UFO* tempUfo;
	//static std::unique_ptr<UFO> tempUfo;
	

public:

	Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, UFO* ufo);
	~Player() = default;

	void update() override;
	void updateUfo();
	
	void initTempUfo();
	static UFO* getUfo();

	void setIsDead(bool state);
	static bool getIsDead();
	static short getPoints();
	static short getLives();
	
	static bool getUfoInProgress();
	static void setUfoInProgress(bool state);

	sf::IntRect getHitbox();

};

