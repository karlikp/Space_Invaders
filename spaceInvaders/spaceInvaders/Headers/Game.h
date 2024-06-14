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
    unsigned int screenWidth;
    unsigned int screenHeight;

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

    //Mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Game objects
    
    EntityManager* entityManager;
    //Entity* entity;

    Game();
    ~Game();

    //Accessors
    const bool getWindowIsOpen() const;
    const bool getEndGame() const;

    void interruptEvents();

    void update();
    void draw();

    friend class Entity;
};
