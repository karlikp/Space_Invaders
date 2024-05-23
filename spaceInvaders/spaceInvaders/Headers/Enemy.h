#pragma once
class Enemy
{
	short direction;
	int health;
	static int enemyCounter;
	bool isDead;
	

public:

	virtual bool bulletCollision();
	virtual int getDirection();
	virtual int getHealth();
	virtual int getEnemyCounter();
	virtual int move();
	virtual void shoot();
	virtual void hit();
};

