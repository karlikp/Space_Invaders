#include <vector>

#pragma once
class Entity
{
	unsigned short realX;
	unsigned short realY;
	short stepX;
	short stepY;
	//texture - picture

public:

	Entity();
	~Entity();
	virtual void update();
	virtual unsigned short getRealX();
	virtual unsigned short getRealY();
	virtual short getStepX();
	virtual short getStepY();
	virtual void rendering();
};



