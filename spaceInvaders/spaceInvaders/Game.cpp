#include "Headers/Game.h"


sf::RenderWindow Game::window;

void Game::initGame()
{
    std::unique_ptr<EntityManager> entityManager(new EntityManager(&window));
    videoMode = sf::VideoMode::getDesktopMode();

    window.create(videoMode, "Space Invaders", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
}

Game::Game()
{ 
    //EntityManager create every object in constuctor
    initGame();

    entityManager -> initEnemies();          //adding to enemies vector             
    entityManager -> initPlayer();           //another entity adding to entity vector
    entityManager -> initObstacle();
    entityManager -> initUFO();
}

Game::~Game()
{
    //delete entityManager;
    //entityManager = NULL;
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
       //równoleg³e aktualizowanie
    }

    // End game condition
}


void Game::draw()
{
 
    window.clear();

    window.draw(backgroundSprite);

    entityManager->drawEnemies();
    entityManager->drawEntities();

    window.display();
}