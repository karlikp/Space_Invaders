#pragma once

//#include "Game.h"

#include <vector>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Entity
{
	
	//texture - picture

public:

	sf::Sprite entityBulletSprite;
	sf::Sprite entitySprite;

	sf::Texture entityBulletTexture;
	sf::Texture entityTexture;

	float stepX;
	float stepY;

	sf::Vector2f position;

	Entity();
	Entity(float x, float y);

	// Konstruktor kopiuj¹cy
	Entity(const Entity& other) : position(other.position){}

	virtual ~Entity() = default;
	virtual void update() = 0;
	virtual void draw() = 0;

	short getCurrentX();
	short getCurrentY();
	short getStepX();
	short getStepY();

	friend class EntityManager;
};

struct Bullet : public Entity
{


	Bullet() = default;
};

struct Powerup : public Entity
{


	Powerup() = default;
};



