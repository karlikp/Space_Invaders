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

	Entity();

	Entity(int x, int y) : currentX(x), currentY(y) {};

	// Konstruktor kopiuj¹cy
	Entity(const Entity& other)
		: currentX(other.currentX), currentY(other.currentY) {}

	~Entity();
	virtual void update();
	virtual short getRealX();
	virtual short getRealY();
	virtual short getStepX();
	virtual short getStepY();
	virtual void rendering();
};



