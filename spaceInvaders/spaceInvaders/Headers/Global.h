#pragma once

#include<iostream>
#include <random>

constexpr short ENEMY_DEFAULT_HEIGHT = 100;
constexpr short PLAYER_DEFAULT_HEIGHT = 100;
constexpr short OBSTACLE_DEFAULT_WIDTH = 300;
constexpr short UFO_DEFAULT_HEIGHT = 84;
constexpr short BULLET_DEFAULT_HEIGHT = 37;

//I set the elements based on the proportions in relation to the screen height
// P = PROPORTIONS:
constexpr float GAP_RATIO = 0.025; //between enemies, enemy to screen border
constexpr float POWERUP_RATIO = 0.03;
constexpr float BULLET_RATIO = 0.02;
constexpr float ENEMY_SIZE_RATIO = 0.05;
constexpr float ENEMY_OFFSET_RATIO = 0.075;
constexpr float PLAYER_SIZE_RATIO = 0.075;
constexpr float OBSTACLE_HEIGHT_RATIO = 0.075;
constexpr float OBSTACLE_WIDTH_RATIO = 0.15;
constexpr float OBSTACLE_OFFSET_RATIO = 0.225;
constexpr float UFO_HEIGHT_RATIO = 0.075;
constexpr float HITBOX_MARGIN_RATIO = 0.01;
constexpr float SMALL_HITBOX_MARGIN_RATIO = 0.005;


constexpr short ENEMY_SHOOT_CHANCE = 4096;
constexpr short ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr short ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr short POWERUP_DURATION = 512;

constexpr short RIGHT_MOVE = 1;
constexpr short LEFT_MOVE = -1;
constexpr short DOWN_MOVE = 0;

constexpr short LITTLE_HEALTH = 1;
constexpr short LOT_OF_HEALTH = 2;

constexpr short int FAST_RELOAD_TIME = 2;
constexpr short int RELOAD_TIME = 128;

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

