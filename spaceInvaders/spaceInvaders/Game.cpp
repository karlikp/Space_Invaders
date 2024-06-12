#include "Headers/Game.h"
#include "Headers/Player.h"
#include "Headers/EntityManager.h"

void Game::initVariables()
{
    videoMode = sf::VideoMode::getDesktopMode();

    // Game logic
    endGame = false;
    points = 0;
    health = 10;
}

void Game::initWindow()
{
    window.create(videoMode, "Space Invaders", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
}

void Game::initGameGround()
{
    // Calculate width and height where proportions are 2:1
    unsigned int screenWidth = std::min(videoMode.height * 2, videoMode.width);
    unsigned int screenHeight = screenWidth / 2;

    // Read texture
    if (!backgroundTexture.loadFromFile("Resources/Background.png"))
        std::cerr << "Failed to load image 'Resources/Background.png'" << std::endl;

    backgroundSprite.setTexture(backgroundTexture);

    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    float scale = std::min(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    sf::FloatRect spriteBounds = backgroundSprite.getGlobalBounds();
    backgroundSprite.setPosition(
        (window.getSize().x - spriteBounds.width) / 2.0f,
        (window.getSize().y - spriteBounds.height) / 2.0f);
}

void Game::initPlayer()
{
    Player player;
}

void Game::initEnemies()
{
    EntityManager enemyManager; // Enemies initialized in constructor
}

void Game::initObstacles()
{
    // TODO
}

void Game::initUFO()
{
    // TODO
}

Game::Game()
{
    initVariables();
    initWindow();
    initGameGround();
    initPlayer();
    initEnemies();
    initObstacles();
    initUFO();
}

Game::~Game()
{
    // No need to delete window, it is now a stack object
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

void Game::updateEnemies()
{
    // Moving and updating enemies
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(0.f, 5.f);

        if (enemies[i].getPosition().y > window.getSize().y)
        {
            enemies.erase(enemies.begin() + i);
            health -= 1;
            std::cout << "Health: " << health << "\n";
        }
    }

    // Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].getGlobalBounds().contains(mousePosView))
            {
                // Implement enemy click handling logic here
            }
        }
    }
}

void Game::update()
{
    interruptEvents();

    if (!endGame)
    {
        updateEnemies();
    }

    // End game condition
    if (health <= 0)
        endGame = true;
}

void Game::renderGameGround()
{
    window.draw(backgroundSprite);
}

void Game::renderEnemies()
{
    for (auto& enemy : enemies)
    {
        window.draw(enemy);
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
    window.clear();

    // Draw game objects
    renderGameGround();
    renderEnemies();

    window.display();
}