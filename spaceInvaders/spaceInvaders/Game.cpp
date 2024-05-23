#include "Headers/Game.h"
#include "Headers/EnemyManager.h"


void Game::initVariables()
{
	this->videoMode = sf::VideoMode::getDesktopMode();
	this->window = nullptr;
	
	//Game logic
	this->endGame = false;
	this->points = 0;
	this->health = 10;

}

void Game::initWindow()
{

	this->window = new sf::RenderWindow(this->videoMode, "Space Invaders",
		sf::Style::Fullscreen);


	//60 frames per second
	this->window->setFramerateLimit(60);
}

void Game::initGameGround()
{
	// calculate width and height where proportions are 2:1
	unsigned int screenWidth = std::min(this->videoMode.height * 2, this->videoMode.width);
	unsigned int screenHeight = screenWidth / 2;

	// read texture
	if (not this->backgroundTexture.loadFromFile("Resources/Background.png"))
		std::cerr << "Failed to load image 'Resources/Background.png'" << std::endl;

	this->backgroundSprite.setTexture(backgroundTexture);

	// Texture scale
	float scaleX = static_cast<float>(screenWidth) / this->backgroundTexture.getSize().x;
	float scaleY = static_cast<float>(screenHeight) / this->backgroundTexture.getSize().y;
	this->backgroundSprite.setScale(scaleX, scaleY);

	// centre of texture
	this->backgroundSprite.setPosition(
		float(this->videoMode.width - screenWidth) / 2.0f,
		float(this->videoMode.height - screenHeight) / 2.0f
	);
	// Calculate texture bounds
	this->textureBounds = backgroundSprite.getGlobalBounds();
}

void Game::initPlayer()
{
	//TODO
}

void Game::initEnemies()
{
	EnemyManager enemyManager; //w konstruktorze zostaj¹ zainicjowani wrogowie
}

void Game::initObstacles()
{
	//TODO
}

void Game::initUFO()
{
	//TODO
}

Game::Game()
{
	this->initVariables();  //potencjalne u¿ycie wielow¹tkowoœci
	this->initWindow();
	this->initGameGround();
	this->initPlayer();
	this->initEnemies();
	this->initObstacles();
	this->initUFO();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
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

void Game::interruptEvents()
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
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

	if (this->mousePosWindow.x < this->textureBounds.left) {
		this->mousePosWindow.x = static_cast<int>(this->textureBounds.left);
	}
	if (this->mousePosWindow.x > this->textureBounds.left + this->textureBounds.width) {
		this->mousePosWindow.x = static_cast<int>(this->textureBounds.left + this->textureBounds.width);
	}
	if (this->mousePosWindow.y < this->textureBounds.top) {
		this->mousePosWindow.y = static_cast<int>(this->textureBounds.top);
	}
	if (this->mousePosWindow.y > this->textureBounds.top + this->textureBounds.height) {
		this->mousePosWindow.y = static_cast<int>(this->textureBounds.top + this->textureBounds.height);
	}

	// Ustawienie pozycji kursora w oknie na ograniczon¹ wartoœæ
	sf::Mouse::setPosition(this->mousePosWindow, *this->window);
}

void Game::updateEnemies()
{

	//Moving and updating enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i].move(0.f, 5.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "Health: " << this->health << "\n";
		}
	}

	//check if clicked upon
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	
		for (size_t i = 0; i < this->enemies.size(); i++)
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{

			
			}
		}

	}
}

void Game::update()
{
	this->interruptEvents();

	if (this->endGame == false)
	{
		this->updateMousePosition();

		this->updateEnemies();
	}
	//End game condition
	if (this->health <= 0)
		this->endGame = true;
}


void Game::renderGameGround()
{
	auto gameGround = (this->backgroundSprite);
	this->window->draw(this->backgroundSprite);
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
	//this->renderGameGround();
	this->window->draw(this->backgroundSprite);
	//this->renderEnemies();

	this->window->display();
}
