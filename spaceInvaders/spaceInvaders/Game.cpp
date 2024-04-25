#include "Game.h"


void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Space Invaders",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	
		while (this->window->pollEvent(this->ev))
		{
			switch (this->ev.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			}
		}
}

void Game::update()
{
	this->pollEvents();

}
void Game::render()
{
	/*
	return
		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects
	*/
	this->window->clear(sf::Color::Green);
	this->window->display();
}
