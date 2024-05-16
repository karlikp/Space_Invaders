#include <string>

#pragma once

class Player
{
	unsigned points;
	bool isDead;
	unsigned short current_damage;
	unsigned short reload_timer;
	unsigned short powerup_timer;
	std::string name;

public:

	Player();
	~Player();
	void moveInputs();
	void updatePlayer();
	void updateLives();
	void updatePoints();
	void renderPlayer();
	bool bulletCollision();
};

