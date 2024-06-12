#pragma once

#include "SFML/Graphics.hpp"

#include "Enemy.h"
#include "structs.h"


#include <random>

class EntityManager
{
	std::uniform_int_distribution <unsigned short> shootPossibility;

	std::vector<Bullet> enemyBullets;

	std::vector<std::unique_ptr<Enemy>> enemies;

	std::vector<Entity> obstacleVector;

	sf::Sprite enemyBulletSprite;

	sf::Texture enemyBulletTexture;
public:

	EntityManager();

	~EntityManager() = default;

	void initEnemies();

	bool catchedPlayer(short playerY);

	void draw(sf::RenderWindow& window);

	void reset(short level);

	void update(std::mt19937_64& randomFunction);

	std::vector<Bullet>& getEnemyBullets();

	std::vector<Enemy>& getEnemies();
};