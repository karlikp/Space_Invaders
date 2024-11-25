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

    bool successCreating, exitProgram;
    static bool gameIsFinish, readyToStart, isRecord, win,
        uniqueMessageWasShow, patternMessageWasShow, tableWasSet;
         
    float scrollOffset;

    std::string playerName;
    int previousPoints;
    static int newPoints;
    
    std::vector<std::pair<std::string, int>> records;

    std::mutex mutex;
  
    static sf::RenderWindow window;
    static sf::RenderWindow* windowPtr;
    sf::VideoMode videoMode;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2f center;

    std::vector<sf::RectangleShape> optionWindows;
    std::vector<sf::Text> optionTexts;
    std::vector<sf::Text> playerNamesText;
    std::vector<std::string> playerNames;

    sf::Text uniqueNameText;
    sf::Text existNameText;
    sf::Text patternText;
    sf::Text playerInputNameText;
    sf::Text saveButtonText;
    sf::Text uniqueInfoText;
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
    sf::RectangleShape playButton;
    sf::RectangleShape scoreTableWindow;
    sf::RectangleShape backButton;
    sf::RectangleShape exitButton;
    sf::RectangleShape summaryBackButton;
    sf::RectangleShape summaryExitButton;

    void chooseVideoMode();
    void updateLastScore();
    void checkOptionClicked(sf::Vector2i& mousePos);
    void addOption(const std::string& text, float y);
    void initSummaryGame();
    void newPlayerActions();
    void playContinueActions();
    void playerErase(const std::string& playerName);

    void loadBackground();
    void loadInstructions();
    void loadScoreTable();

    void sortScoreTable();
    void recordScoreTable();

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
    void renderInstruction();
    void renderSummaryGame();

    void checkPattern();
    bool playerExists(const std::string& playerName);
    bool isBackButtonClicked(sf::Vector2i mousePos);
    bool isExitButtonClicked(sf::Vector2i mousePos);
    bool isPlayButtonClicked(sf::Vector2i mousePos);
  
   
public:

    Interface();
    ~Interface() = default;

    void run();
    void reset();

    bool getExitProgram();
    static sf::RenderWindow* getWindowPtr();

    static void setGameIsFinish(bool newState);
    static void setWin(bool newState);
    static void setNewPoints(int iNewPoints);
    static void setReadyToStart(bool newState);
    static void setIsRecord(bool newState);
    static void setPatternMessageWasShow(bool newState);
    static void setUniqueMessageWasShow(bool newState);
    static void setTableWasSet(bool newState);
};