#pragma once

constexpr short ENEMY_DEFAULT_HEIGHT = 100;
constexpr short PLAYER_DEFAULT_HEIGHT = 100;
constexpr short OBSTACLE_DEFAULT_WIDTH = 300;
constexpr short UFO_DEFAULT_HEIGHT = 84;
constexpr short BULLET_DEFAULT_HEIGHT = 37;
constexpr short POWERUP_DEFAULT_HEIGHT = 37;
constexpr short LIFE_DEFAULT_HEIGHT = 26;

//I set the elements based on the proportions in relation to the screen height
// P = PROPORTIONS:
constexpr float GAP_RATIO = 0.025; //between enemies, enemy to screen border
constexpr float POWERUP_RATIO = 0.03;
constexpr float BULLET_RATIO = 0.02;
constexpr float ENEMY_SIZE_RATIO = 0.05;
constexpr float ENEMY_OFFSET_RATIO = 0.075;
constexpr float PLAYER_SIZE_RATIO = 0.075;
constexpr float LIFE_SIZE_RATIO = 0.050;
constexpr float OBSTACLE_HEIGHT_RATIO = 0.075;
constexpr float OBSTACLE_WIDTH_RATIO = 0.15;
constexpr float OBSTACLE_OFFSET_RATIO = 0.225;
constexpr float UFO_HEIGHT_RATIO = 0.075;
constexpr float UFO_WIDTH_RATIO = 0.121;
constexpr float HITBOX_MARGIN_RATIO = 0.01;
constexpr float SMALL_HITBOX_MARGIN_RATIO = 0.005;


constexpr short ENEMY_SHOOT_CHANCE = 4096;
constexpr short ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr short ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr short POWERUP_DURATION = 512;

constexpr short RIGHT_MOVE = 1;
constexpr short LEFT_MOVE = -1;
constexpr short UP_MOVE = -2;
constexpr short DOWN_MOVE = 2;
constexpr float NEW_PATH_LOW_BORDER = 0.725;
constexpr float NEW_PATH_UP_BORDER = 0.2;

constexpr short LITTLE_HEALTH = 1;
constexpr short LOT_OF_HEALTH = 2;

constexpr short FAST_RELOAD_TIME = 16;
constexpr short RELOAD_TIME = 128;

constexpr short NORMAL_STATE = 0;
constexpr short FASTER_RELOAD = 1;
constexpr short TRIPLE_SHOOT = 2;
constexpr short BETTER_DAMAGE = 3;

constexpr short UFO_MOVE_SPEED = 2;
constexpr short BULLET_SPEED = 5;
constexpr short POWERUP_SPEED = 4;
constexpr short PLAYER_MOVE_SPEED = 4;
constexpr short INVADER_MOVE_SPEED_X = 2;
constexpr short INVADER_MOVE_SPEED_Y = 2;
constexpr short MOTIONLESS_X = 0;
constexpr short MOTIONLESS_Y = 0;

