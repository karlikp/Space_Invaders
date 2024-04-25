#pragma once

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

	void initVariables();
	void initWindow();

public:

	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	void pollEvents();
	void update();
	void render();
};

