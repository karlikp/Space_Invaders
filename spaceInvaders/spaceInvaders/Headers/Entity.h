#pragma once

#include <vector>


class Entity
{
	
	//texture - picture

public:

	short currentX;
	short currentY;
	short stepX;
	short stepY;

	Entity() = default;

	Entity(int x, int y) : currentX(x), currentY(y) {};

	// Konstruktor kopiuj¹cy
	Entity(const Entity& other)
		: currentX(other.currentX), currentY(other.currentY) {}

	~Entity() = default;
	virtual void update() = 0;
	short getCurrentX();
	short getCurrentY();
	short getStepX();
	short getStepY();
	virtual void rendering() = 0;
};



