#include <iostream>

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

Game::Game()
{
    initGame();
    initBackground();
    initEnemies();
    initObstacle();
    initUfo();
    initPlayer();
    initPoints();
}

Game::~Game()
{
    delete manager;
    manager = NULL;
}

void Game::initGame()
{
    points = 0;
    victory = false;
    manager = new EntityManager(&window);
    videoMode = sf::VideoMode::getDesktopMode();

    window.create(videoMode, "Space Invaders", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    screenSize.x = window.getSize().x;
    screenSize.y = window.getSize().y;
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
    float startX = GAP_RATIO * screenSize.y;
    float startY = 0.2 * screenSize.y;
    float offsetX = ENEMY_OFFSET_RATIO * screenSize.y;
    float offsetY = ENEMY_OFFSET_RATIO * screenSize.y;
    float enemySize = ENEMY_SIZE_RATIO * screenSize.y;

    //  Tworzenie wierszy przeciwników
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 14; ++j) {
            if (i == 0) {
                manager->addEnemy(std::make_unique<Enemy3>(startX + j * offsetX, startY + i * offsetY, INVADER_MOVE_SPEED_X, INVADER_MOVE_SPEED_Y, screenSize));
            }
            else if (i == 1 or i == 2) {
                manager->addEnemy(std::make_unique<Enemy2>(startX + j * offsetX, startY + i * offsetY, INVADER_MOVE_SPEED_X, INVADER_MOVE_SPEED_Y, screenSize));
            }
            else {
                manager->addEnemy(std::make_unique<Enemy1>(startX + j * offsetX, startY + i * offsetY, INVADER_MOVE_SPEED_X, INVADER_MOVE_SPEED_Y, screenSize));
            }
        }
    }
}

void Game::initPlayer()
{   
    float newShipSize = PLAYER_SIZE_RATIO * screenSize.y;
    float posX = (screenSize.x - newShipSize) / 2;
    float posY = screenSize.y - (0.1 * screenSize.y);
   
    manager->addEntity(std::make_unique<Player>(posX, posY, PLAYER_MOVE_SPEED, MOTIONLESS_Y, screenSize, ufo));
}

void Game::initPoints()
{
    if (!font.loadFromFile("Resources/ARIAL.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    pointsLabel.setFont(font);
    pointsLabel.setString("POINTS: ");
    pointsLabel.setCharacterSize(24); 
    pointsLabel.setFillColor(sf::Color::White);
    pointsLabel.setPosition(GAP_RATIO * screenSize.y, GAP_RATIO * screenSize.y);

   
    pointsText.setFont(font);
    pointsText.setCharacterSize(24); 
    pointsText.setFillColor(sf::Color::White);
    pointsText.setPosition(pointsLabel.getLocalBounds().width + GAP_RATIO * screenSize.y, GAP_RATIO * screenSize.y);

}

void Game::initObstacle()
{
    float tempWidth = screenSize.x;
    float offsetX = OBSTACLE_HEIGHT_RATIO * screenSize.y;
    float obstacleWidth = OBSTACLE_WIDTH_RATIO * screenSize.y;

    int obstacleCount = 0;    //How many obstacles is possible
    float offsetCount = 0;

    float posY = screenSize.y - 0.2 * screenSize.y;
    float leftPosX, rightPosX;
    
    if (tempWidth >= 0.3 * screenSize.y) { //first obstacle is possible
        
        do {
            obstacleCount++;
            tempWidth -= OBSTACLE_OFFSET_RATIO * screenSize.y;

        } while (tempWidth >= 0.3 * screenSize.y);
    }

    while (obstacleCount > 1) {
        leftPosX = (OBSTACLE_HEIGHT_RATIO + (OBSTACLE_OFFSET_RATIO * offsetCount)) * screenSize.y;
        //left obstacles
        manager->addEntity(std::make_unique<Obstacle>(leftPosX, posY, MOTIONLESS_X, MOTIONLESS_Y, screenSize));
        
        rightPosX = screenSize.x - ((OBSTACLE_OFFSET_RATIO + (OBSTACLE_OFFSET_RATIO * offsetCount)) * screenSize.y);
        //right obstacles
        manager->addEntity(std::make_unique<Obstacle>(rightPosX, posY, MOTIONLESS_X, MOTIONLESS_Y, screenSize));
        obstacleCount -= 2;
        offsetCount++;
    };

    if (obstacleCount == 1) {
        manager->addEntity(std::make_unique<Obstacle>((screenSize.x - obstacleWidth) / 2, posY, MOTIONLESS_X, MOTIONLESS_Y, screenSize));
    }  
}

void Game::initUfo()
{
    float posX = screenSize.x + (2 * UFO_WIDTH_RATIO * screenSize.y);
    float posY = 0.1 * screenSize.y;
    ufo = new UFO(posX, posY, INVADER_MOVE_SPEED_X, MOTIONLESS_Y, screenSize);
}

bool Game::getPlayerIsDead()
{
    return Player::getIsDead();
}

const bool Game::getWindowIsOpen() const
{
    return window.isOpen();
}

const bool Game::getEndGame() const
{
    return endGame;
}

sf::RenderWindow* Game::getWindow()
{
    return &window;
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

void Game::endGameplay()
{
    endGame = true;
    window.clear();
    window.close();
}

void Game::update()
{
    interruptEvents();

    if (!endGame)
    {
        manager->updateEnemies();
        manager->updateEntities();
        manager->updatePlayerBullets();
        manager->updateEnemyBullets();
        manager->updatePowerups();
        updatePoints();

        if (manager->getEnemies().empty()) {
            victory = true;
            endGameplay();
        }
        else if (getPlayerIsDead()) {
            endGame = true;
            endGameplay();
        }
    }

    // End game condition
}

void Game::updatePoints()
{
    points = Player::getPoints();
    pointsText.setString(std::to_string(points));
}


void Game::draw()
{
 
    window.clear();

    
    window.draw(backgroundSprite);

    drawUfo();
    manager->drawEnemies(); 
    manager->drawEntities();
    manager->drawPlayerBullets();
    manager->drawEnemyBullets();
    manager->drawPowerups();
    window.draw(pointsLabel);
    window.draw(pointsText);

    window.display();
}

void Game::drawUfo()
{
    if (ufo->getIsDead() == false) {
        auto ufoPtr = Player::getUfo();
        window.draw(ufo->entitySprite);
    }
}

//void Game::drawUfo()
//{
//   
//    auto ufo = Player::moveOutUFO();
//    
//    window.draw(ufo->entitySprite);
//
//    Player::moveInUFO(std::move(ufo));
//}
