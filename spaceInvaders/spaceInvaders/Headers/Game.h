#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
	//Variables
	unsigned int screenWidth;
	unsigned int screenHight;

	//Window
	sf::RenderWindow* window;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	sf::FloatRect textureBounds;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Game logic
	bool endGame;
	unsigned points;
	short health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	bool mouseHeld;

	//Private function
	void initVariables();
	void initWindow();
	void initGameGround();
	void initPlayer();
	void initEnemies();
	void initObstacles();
	void initUFO();

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

	void renderGameGround();
	void renderEnemies();
	void render();
};

