#pragma once

#include "SFML/Graphics.hpp"

#include "Enemy.h"
#include "Entity.h"

#include <list>
#include <random>

class EntityManager
{
	float widthWindow, highWindow;

	std::uniform_int_distribution <unsigned short> shootPossibility;
	
	std::vector<std::unique_ptr<Entity>> entities;
	std::vector<std::unique_ptr<Enemy>> enemies;

	std::vector<Bullet> enemyBullets;

	static sf::RenderWindow* window;

	sf::Sprite enemyBulletSprite;

	sf::Texture enemyBulletTexture;
public:

	EntityManager(sf::RenderWindow* windowI);
	EntityManager() = default;
	~EntityManager() = default;

	void addEnemy(std::unique_ptr<Enemy> enemy);
	void addEntity(std::unique_ptr<Entity> entity);

	void updateEnemies();
	void updateEntities();

	void drawEnemies();
	void drawEntities();

	bool catchedPlayer(short playerY);

	void draw(sf::RenderWindow& window);

	void reset(short level);

	void update(std::mt19937_64& randomFunction);

	//std::vector<Bullet>& getEnemyBullets();

	//std::vector<Enemy>& getEnemies();
};



