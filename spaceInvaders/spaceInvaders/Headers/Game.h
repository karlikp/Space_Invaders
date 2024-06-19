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
const short BASIC_SIZE = 50;

class Game
{

    sf::Vector2f screenSize;
   
    //Game logic
    bool endGame;
    bool mouseHeld;
    bool victory;

   // std::mutex mtx;

    //Private function
    void initGame();
    void initBackground();
    void initEnemies();
    void initPlayer(std::unique_ptr<UFO>* ufo);
    void initObstacle();
    std::unique_ptr<UFO>* initUFO();

public:

    //Window
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::FloatRect textureBounds;
    sf::VideoMode videoMode;
    sf::Event ev;

    static sf::RenderWindow window;
    static sf::RenderWindow& getWindow();
 
    EntityManager* manager;

    Game();
    ~Game();

    void update();
    void draw();
    void interruptEvents();
    void endGameplay();

    bool getPlayerIsDead();
    const bool getWindowIsOpen() const;
    const bool getEndGame() const;
  
    friend class Entity;
};
