#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

#include <string>

class Player : public Entity
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

	Player(sf::RenderWindow* window);
	Player(float x, float y);
	~Player() = default;

	void update() /*override*/;
	void draw() /*override*/;

	//void reset();
	void moveInputs();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();
};

