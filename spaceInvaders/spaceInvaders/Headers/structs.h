#include "Entity.h"

#pragma once

std::vector<Entity> enemiesVector;
std::vector<Bullet> enemiesBulletsVector;
std::vector<Entity> obstacleVector;
std::vector<Bullet> playerBullets;

struct Bullet : public Entity
{

};

struct Powerup : public Entity
{

};