#include "Game.h"


void Game::initVariables()
{
	this->window = nullptr;
	
	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;



}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Space Invaders",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

	this->window->setFramerateLimit(60);
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

void Game::spawnEnemy()
{
	/*
		@return void

		Spawn enemies and sets their colors and position.
		-Sets a random position.
		-Sets a random color.
		-Adds enemy to the vector.
	*/

	// rzutowanie na float oraz int 

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 
		0.f		//start y position
	);

	this->enemy.setFillColor(sf::Color::Green);

	//Spawn the enemy
	this->enemies.push_back(this->enemy);

	//Remove enemies at end of screen

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

void Game::updateEnemies()
{
	/*
		@return void

		Update the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller then the maximum.
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/
	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Move the enemies
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePosition();

	this->updateEnemies();

}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
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
	this->renderEnemies();

	this->window->display();
}
