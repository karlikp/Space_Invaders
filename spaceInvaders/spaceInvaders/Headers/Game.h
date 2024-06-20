#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
//#include <mutex>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "EntityManager.h"
#include "UFO.h"


class Game
{
    sf::Vector2f screenSize;
   
    //Game logic
    bool endGame, victory;
    short points;

   // std::mutex mtx;

    //Private function
    void initGame();
    void initBackground();
    void initEnemies();
    void initObstacle();
    void initUfo();
    void initPlayer();
    void initPoints();

public:

    sf::Font font;
    sf::Text pointsLabel;
    sf::Text pointsText;

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::FloatRect textureBounds;
    sf::VideoMode videoMode;
    sf::Event ev;

    static sf::RenderWindow window;
    static sf::RenderWindow* getWindow();
 
    EntityManager* manager;
    UFO* ufo;

    Game();
    ~Game();

    void update();
    void updatePoints();
    void draw();
    void drawUfo();
    void interruptEvents();
    void endGameplay();

    bool getPlayerIsDead();
    const bool getWindowIsOpen() const;
    const bool getEndGame() const;
  
    friend class Entity;
};
