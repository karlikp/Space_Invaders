#include "Entity.h"

#pragma once
class Bullet : public Entity 
{
	bool isDestruct;

public:
	bool bulletCollision();
	bool isBehindMap();
};

