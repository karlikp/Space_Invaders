#pragma once

#include "SFML/Graphics.hpp"

#include "Enemy.h"
#include "Entity.h"
#include "Global.h"

#include <list>
#include <random>

class EntityManager
{
	//float widthWindow, highWindow;

	std::uniform_int_distribution <unsigned short> shootPossibility;
	
	static std::vector<std::unique_ptr<Entity>> entities;
	static std::vector<std::unique_ptr<Enemy>> enemies;

	static std::vector<std::unique_ptr<Bullet>> enemyBullets;
	static std::vector<std::unique_ptr<Bullet>> playerBullets;

	static sf::RenderWindow* window;

public:

	EntityManager(sf::RenderWindow* windowI);
	EntityManager() = default;
	~EntityManager() = default;

	void addEnemy(std::unique_ptr<Enemy> enemy);
	void addEntity(std::unique_ptr<Entity> entity);
	static void addPlayerBullet(std::unique_ptr<Bullet> bullet);

	void updateEnemies();
	void updateEntities();

	void drawEnemies();
	void drawEntities();

	std::vector<std::unique_ptr<Bullet>>& getEnemyBullets();

	std::vector<Enemy>& getEnemies();
};



