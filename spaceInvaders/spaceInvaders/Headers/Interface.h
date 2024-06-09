#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Interface {

    enum class State { MainMenu, NewPlayerNoMess, NewPlayerWithMess }
    currentState = State::MainMenu;

    sf::RenderWindow window;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<sf::RectangleShape> optionWindows;
    std::vector<sf::Text> optionTexts;

    sf::Text enterNameText;
    sf::Text playerNameText;
    sf::RectangleShape playerNameBox;
    std::string playerName;

    sf::RectangleShape saveButtonWindow;
    sf::Text saveButtonText;
    sf::Text uniqueNameText;

    bool startGame, noRecord;

    void loadResources();
    void setupBackground();
    void setupMenuOptions();
    void addOption(const std::string& text, float y);
    void handleEvents();
    void handleMainMenuEvents(sf::Event& event);
    void handleNewPlayerEvents(sf::Event& event);
    void checkOptionClicked(sf::Vector2i mousePos);
    void render();
    void renderMainMenu();
    void renderNewPlayer(bool showUniqueNameMessage);

    void playGame();
    void savePlayerName();

public:
    Interface();
    void run();
};