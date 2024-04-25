#pragma once

#include <iostream>

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
	sf::RectangleShape enemy;

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

	void pollEvents();
	void updateMousePosition();
	void update();
	void render();
};

