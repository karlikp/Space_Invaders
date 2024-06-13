#pragma once

#include "Game.h"
#include "EntityManager.h"

#include <vector>


class Entity
{
	
	//texture - picture

public:

	//float posX;
	//float posY;
	float stepX;
	float stepY;

	sf::Vector2f position;

	Entity();
	Entity(float x, float y);

	// Konstruktor kopiuj¹cy
	Entity(const Entity& other) : position(other.position){}

	~Entity() = default;
	virtual void update() = 0;
	virtual void rendering() = 0;

	short getCurrentX();
	short getCurrentY();
	short getStepX();
	short getStepY();

	friend class EntityManager;
};



