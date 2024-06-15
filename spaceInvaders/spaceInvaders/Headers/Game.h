#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "EntityManager.h"

const short BASIC_SIZE = 50;

class Game
{
    //Variables
    

    //Game logic
    bool endGame;
    bool mouseHeld;

    //Private function
    void initGame();

public:

    static float screenWidth;
    static float screenHeight;
    //Window
    static sf::RenderWindow window;
 
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::FloatRect textureBounds;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Initialization objects
    void initBackground();
    void initEnemies();
    void initPlayer();
    void initObstacle();
    void initUFO();

    void update();
    void draw();
    
    EntityManager* manager;
    //Entity* entity;

    Game();
    ~Game();

    //Accessors
    static std::pair<float, float> getWindowSize();
    const bool getWindowIsOpen() const;
    const bool getEndGame() const;

    void interruptEvents();

    

    friend class Entity;
};
