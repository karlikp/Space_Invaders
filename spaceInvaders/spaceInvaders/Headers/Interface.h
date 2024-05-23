#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

class Interface {

    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::RectangleShape> optionWindows;
    std::vector<sf::Text> optionTexts;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    Interface();
    // Metoda dodaj¹ca opcjê do menu
    void addOption(const std::string& text, float y);

    void handleEvents();

    void checkOptionClicked(sf::Vector2i mousePos);

    void render();

    void run();
};