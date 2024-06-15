#include "Headers/Game.h"
#include "Headers/Global.h"
#include "Headers/Player.h"
#include "Headers/Obstacle.h"
#include "Headers/UFO.h"
#include "Headers/Enemy1.h"
#include "Headers/Enemy1.h"
#include "Headers/Enemy2.h"
#include "Headers/Enemy3.h"


sf::RenderWindow Game::window;
float Game::screenHeight;
float Game::screenWidth;

void Game::initGame()
{
   manager = new EntityManager(&window);
    videoMode = sf::VideoMode::getDesktopMode();

    window.create(videoMode, "Space Invaders", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    screenHeight = window.getSize().y;
    screenWidth = window.getSize().x;
}

void Game::initBackground()
{
    if (!backgroundTexture.loadFromFile("Resources/Background.png")) {
        std::cerr << "Failed to load image 'Resources/Background.png'" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    float scale = std::min(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    sf::FloatRect spriteBounds = backgroundSprite.getGlobalBounds();
    backgroundSprite.setPosition(
        (window.getSize().x - spriteBounds.width) / 2.0f,
        (window.getSize().y - spriteBounds.height) / 2.0f
    );
}

void Game::initEnemies()
{
    float startX = GAP * screenHeight;
    float startY = 0.2 * screenHeight;
    float offsetX = 0.075 * screenHeight;
    float offsetY = 0.075 * screenHeight;
    float enemySize = 0.05 * screenHeight;

    float scale = enemySize / ENEMY_DEFAULT_HEIGHT;




    //  Tworzenie wierszy przeciwników
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 14; ++j) {
            if (i == 0) {
                manager->addEnemy(std::make_unique<Enemy3>(startX + j * offsetX, startY + i * offsetY, scale));
            }
            else if (i == 1 or i == 2) {
                manager->addEnemy(std::make_unique<Enemy2>(startX + j * offsetX, startY + i * offsetY, scale));
            }
            else {
                manager->addEnemy(std::make_unique<Enemy1>(startX + j * offsetX, startY + i * offsetY, scale));
            }
        }
    }
}

void Game::initPlayer()
{   
    float shipSize = 0.075 * screenHeight;
    float posX = (screenWidth - shipSize) / 2;
    float posY = screenHeight - (0.1 * screenHeight);

    float scale = (0.075 * screenHeight) / PLAYER_DEFAULT_HEIGHT;

    manager->addEntity(std::make_unique<Player>(posX, posY, scale));
}

void Game::initObstacle()
{
    float tempWidth = screenWidth;
    float offsetX = 0.075 * screenHeight;
    float obstacleWidth = 0.15 * screenHeight;

    int obstacleCount = 0;    //How many obstacles is possible
    float offsetCount = 0;

    float posY = screenHeight - 0.2 * screenHeight;
    float leftPosX, rightPosX;

    //scaling
    float scale = obstacleWidth / OBSTACLE_DEFAULT_WIDTH;

    
    if (tempWidth >= 0.3 * screenHeight) { //first obstacle is possible
        
        do {
            obstacleCount++;
            tempWidth -= 0.225 * screenHeight;

        } while (tempWidth >= 0.3 * screenHeight);
    }

    while (obstacleCount > 1) {
        leftPosX = (0.075 + (0.225 * offsetCount)) * screenHeight;
        //left obstacle
        manager->addEntity(std::make_unique<Obstacle>(leftPosX, posY, scale));
        
        rightPosX = screenWidth - ((0.225 + (0.225 * offsetCount)) * screenHeight);
        //right obstacle
        manager->addEntity(std::make_unique<Obstacle>(rightPosX, posY, scale));
        obstacleCount -= 2;
        offsetCount++;
    };

    if (obstacleCount == 1) {
        manager->addEntity(std::make_unique<Obstacle>((screenWidth - obstacleWidth) / 2, posY, scale));
    }  
}

void Game::initUFO()
{
    float tempPosX = screenWidth - 150;
    float posY = 0.1 * screenHeight;

    float scale = (0.075 * screenHeight) / UFO_DEFAULT_HEIGHT;

    manager->addEntity(std::make_unique<UFO>(tempPosX, posY, scale));
}

Game::Game()
{ 
    //EntityManager create every object in constuctor
    initGame();
    initBackground();

    initEnemies();//adding to enemies vector
    initUFO();
    initPlayer();
    initObstacle();
    
}

Game::~Game()
{
    delete manager;
    //entityManager = NULL;
}

std::pair<float, float> Game::getWindowSize()
{
    return {screenWidth, screenHeight};
}

const bool Game::getWindowIsOpen() const
{
    return window.isOpen();
}

const bool Game::getEndGame() const
{
    return endGame;
}

void Game::interruptEvents()
{
    while (window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                window.close();
            break;
        }
    }
}

void Game::update()
{
    interruptEvents();

    if (!endGame)
    {
        manager->updateEnemies();
        manager->updateEntities();
    }

    // End game condition
}


void Game::draw()
{
 
    window.clear();

    window.draw(backgroundSprite);

    manager->drawEnemies(); 
    manager->drawEntities();

    window.display();
}