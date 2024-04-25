#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;

	

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Private function
	void initVariables();
	void initWindow();
	void initEnemies();

public:

	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//function
	void spawnEnemy();
	void pollEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};

