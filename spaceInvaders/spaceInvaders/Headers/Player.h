#pragma once

#include <SFML/Graphics.hpp>

#include"Entity.h"
#include"structs.h"

#include <string>

class Player : Entity
{
	unsigned points;
	bool isDead;
	unsigned short current_damage;
	unsigned short reload_timer;
	unsigned short powerup_timer;
	std::string name;

	std::vector<Bullet> bullets;

	sf::Sprite bulletSprite;
	sf::Sprite shipSprite;

	sf::Texture bulletTexture;
	sf::Texture shipTexture;

public:

	Player();
	~Player();
	void reset();
	void moveInputs();
	void updatePlayer();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();
};

