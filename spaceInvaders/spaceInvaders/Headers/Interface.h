#pragma once

#include <thread>
#include <mutex>

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ranges>
#include <algorithm>
#include <filesystem>


class Interface {

    enum class State { MainMenu, NewPlayer, ContinuePlayer, ScoreTable, Rules, SummaryGame, Exit}
    currentState = State::MainMenu;

    bool readyToStart, noRecord, showUniqueNameMessage, showPatternNameMessage,
        successCreating, exitProgram, finishPoints, win;
    float scrollOffset;

    int points;
    std::string playerName;
   
    
    std::vector<std::pair<std::string, int>> records;

    std::mutex mutex;
  
    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2f center;

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
    sf::Text instructionText;
    sf::Text backButtonText;
    sf::Text exitButtonText;
    sf::Text summaryScoreText;
    sf::Text summaryPointsText;
    sf::Text summaryBackText;
    sf::Text summaryExitText;

    sf::RectangleShape playerNameWindow;
    sf::RectangleShape saveButton;
    sf::RectangleShape scoreTableWindow;
    sf::RectangleShape backButton;
    sf::RectangleShape exitButton;
    sf::RectangleShape summaryBackButton;
    sf::RectangleShape summaryExitButton;

    void checkOptionClicked(sf::Vector2i& mousePos);
    void addOption(const std::string& text, float y);
    void initSummaryGame();

    void loadResources();
    void loadInstructions();
    void loadPlayerNames();

    void setupText(sf::Text& text, const std::string& content, int charSize, const sf::Color& color, float posX, float posY);
    void setupRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size,
        const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, float posX, float posY);
    void setupBackground();
    void setupMenuOptions();
    void setupScoreTableWindow();
    void setupBackButton();

    void handleEvents();
    void handleMainMenuEvents(sf::Event& event);
    void handleNewPlayerEvents(sf::Event& event);
    void handleContinuePlayerEvents(sf::Event& event);
    void handleScoreTableEvents(sf::Event& event);
    void handleRulesEvents(sf::Event& event);
    void handleSummaryGameEvents(sf::Event& event);
    void handleExit();

    void render();
    void renderMainMenu();
    void renderNewPlayer();
    void renderContinuePlayer();
    void renderScoreTable();
    void renderRules();
    void renderSummaryGame();

    void createPlayer();
    bool playerExists(const std::string& playerName);
    bool isBackButtonClicked(sf::Vector2i mousePos);
    bool isExitButtonClicked(sf::Vector2i mousePos);

    void loadData();
    void sortData();
    void recordData();

public:

    Interface();
    ~Interface() = default;

    void run();
    void getGameInfo();

    bool getExitProgram();
};