#pragma once

constexpr short ENEMY_DEFAULT_HEIGHT = 100;
constexpr short PLAYER_DEFAULT_HEIGHT = 100;
constexpr short OBSTACLE_DEFAULT_WIDTH = 300;
constexpr short UFO_DEFAULT_HEIGHT = 84;
constexpr short BULLET_DEFAULT_HEIGHT = 37;

//I set the elements based on the proportions in relation to the screen height
// P = PROPORTIONS:
constexpr float GAP_RATIO = 0.025; //between enemies, enemy to screen border
constexpr float BULLET_RATIO = 0.02;
constexpr float ENEMY_SIZE_RATIO = 0.05;
constexpr float ENEMY_OFFSET_RATIO = 0.075;
constexpr float PLAYER_SIZE_RATIO = 0.075;
constexpr float OBSTACLE_HEIGHT_RATIO = 0.075;
constexpr float OBSTACLE_WIDTH_RATIO = 0.15;
constexpr float OBSTACLE_OFFSET_RATIO = 0.225;
constexpr float UFO_HEIGHT_RATIO = 0.075;
constexpr float HITBOX_MARGIN_RATIO = 0.01;


constexpr short int FAST_RELOAD_TIME = 2;
constexpr short int RELOAD_TIME = 4;

constexpr short int NORMAL_STATE = 0;
constexpr short int FASTER_RELOAD = 1;
constexpr short int TRIPLE_SHOOT = 2;
constexpr short int BETTER_DAMAGE = 3;


constexpr float BULLET_SPEED_Y = 5;
constexpr float PLAYER_MOVE_SPEED = 3;
constexpr float INVADER_MOVE_SPEED_X = 2;
constexpr float INVADER_MOVE_SPEED_Y = 2;
constexpr float MOTIONLESS_X = 0;
constexpr float MOTIONLESS_Y = 0;

struct Bullet : public Entity
{
	Bullet(float iPosX, float iPosY, float iStepY, sf::Sprite iBulletSprite, sf::Vector2f iScreenSize) : Entity(iPosX, iPosY, iStepY, iBulletSprite, iScreenSize) {
		
		float scale = (BULLET_RATIO * getScreenSize().y) / BULLET_DEFAULT_HEIGHT;
		setEntityScale(scale);
	}

	~Bullet() = default;

	void update() {};

	void draw() {};

};

struct Powerup : public Entity
{
	Powerup(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize) : Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {}
	~Powerup() = default;

	void update() {};

	void draw() {};

};