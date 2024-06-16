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

    sf::Vector2f screenSize;
   
    //Game logic
    bool endGame;
    bool mouseHeld;

    //Private function
    void initGame();

public:

    
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
    const bool getWindowIsOpen() const;
    const bool getEndGame() const;
   /* static float& getScreenWidth();
    static float& getScreenHeight();*/
    static sf::RenderWindow& getWindow();

    void interruptEvents();

    

    friend class Entity;
};
