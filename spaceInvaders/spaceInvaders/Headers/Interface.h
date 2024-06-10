#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Interface {

    enum class State { MainMenu, NewPlayer, ContinuePlayer, ScoreTable}
    currentState = State::MainMenu;

    bool readyToStart, noRecord, showUniqueNameMessage, showPatternNameMessage,
        successCreating;
  
    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::vector<sf::RectangleShape> optionWindows;
    std::vector<sf::Text> optionTexts;
    std::vector<sf::Text> playerNamesText;
    std::vector<std::string> playerNames;

    sf::Text enterNameText;
    sf::Text patternText;
    sf::Text playerInputNameText;
    sf::Text saveButtonText;
    sf::Text uniqueNameText;
    sf::Text patternNameText;
    sf::Text playerNotFoundText;

    sf::RectangleShape playerNameBox;
    sf::RectangleShape saveButtonWindow;
    sf::RectangleShape scoreTableWindow;

    std::string playerName;

    sf::RectangleShape backButtonWindow;
    sf::Text backButtonText;

    void loadResources();
    void setupText(sf::Text& text, const std::string& content, int charSize, const sf::Color& color, float posX, float posY);
    void setupRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size,
        const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, float posX, float posY);
    void setupBackground();
    void setupMenuOptions();
    void setupScoreTableWindow();
    void addOption(const std::string& text, float y);
    void handleEvents();
    void handleMainMenuEvents(sf::Event& event);
    void handleNewPlayerEvents(sf::Event& event);
    void handleContinuePlayerEvents(sf::Event& event);
    void handleScoreTableEvents(sf::Event& event);
    void checkOptionClicked(sf::Vector2i& mousePos);
    void render();
    void renderMainMenu();
    void renderNewPlayer();
    void renderContinuePlayer();
    void renderScoreTable();
    void createPlayer();
    bool playerExists(const std::string& playerName);
    void loadPlayerNames();
    void setupBackButton();
    bool isBackButtonClicked(sf::Vector2i mousePos);

public:

    bool close;

    Interface();
    void run();
    bool getClose();
};