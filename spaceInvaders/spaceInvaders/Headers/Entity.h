#pragma once

#include "Game.h"

#include <vector>


class Entity
{
	
	//texture - picture

public:

	short posX;
	short posY;
	short stepX;
	short stepY;
	sf::RenderWindow* window;

	Entity() = default;
	Entity(short x, short y);

	// Konstruktor kopiuj¹cy
	Entity(const Entity& other)
		: posX(other.stepX), posY(other.posY) {}

	~Entity() = default;
	virtual void update() = 0;
	virtual void rendering() = 0;

	short getCurrentX();
	short getCurrentY();
	short getStepX();
	short getStepY();
};



