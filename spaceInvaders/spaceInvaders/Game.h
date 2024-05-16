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
	/*sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;*/
	

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Private function
	void initVariables();
	void initWindow();
	void initEnemies();

public:

	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;
	const bool getEndGame() const;

	//function
	void spawnEnemy();
	void interruptEvents();
	void updateMousePosition();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};

