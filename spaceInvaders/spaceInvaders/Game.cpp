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

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); //scale size from original
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(5.f);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
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

void Game::updateMousePosition()
{
	/*
		@ return void

		Update the mouse positions:
		- Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update()
{
	this->pollEvents();

	//this->updateMousePosition();

	//Update mouse position
	/*std::cout << "Mouse pos:" 
		<< sf::Mouse::getPosition().x << " " 
		<< sf::Mouse::getPosition().y << "\n";*/

	//position relative to window
	std::cout << "Mouse pos:" 
		<< sf::Mouse::getPosition(*this->window).x << " "  
		<< sf::Mouse::getPosition(*this->window).y << "\n";


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
	this->window->clear();

	//Draw game objects
	this->window->draw(this->enemy);

	this->window->display();
}
