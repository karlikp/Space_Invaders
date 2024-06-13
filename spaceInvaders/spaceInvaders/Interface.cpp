#include "Headers/Interface.h"

const float OPTION_WIDTH = 200.0f;
const float OPTION_HEIGHT = 50.0f;
const float OPTION_GAP = 20.0f;
const int OPTION_CHARACTER_SIZE = 40;
const bool WITHOUT_MESSAGE = false;
const bool WITH_MESSAGE = true;
const float CELL_WIDTH = 400.0f;
const float CELL_HEIGHT = 50.0f;
const float CELL_GAP = 10.0f;

//windows initialisation 
Interface::Interface() {
    showPatternNameMessage = false;
    close = false;
    successCreating = false;
    readyToStart = false;
    showUniqueNameMessage = false;

    if (!font.loadFromFile("Resources/ARIAL.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    window.create(videoMode, "Menu", sf::Style::Fullscreen);

    loadResources();
    setupBackground();
    setupMenuOptions();
    setupBackground();

    // Set message communication inside background
    sf::Vector2f center(
        window.getSize().x / 2.0f,
        window.getSize().y / 2.0f
    );

    setupText(enterNameText, "Enter a unique name, which include:", 50, sf::Color::Yellow,
        center.x, center.y - 200);
    setupText(patternText, "- one lowercase and one uppercase,\n- from 4 to 12 characters",
        30, sf::Color::Yellow, center.x, center.y - 130);
    setupRectangle(playerNameBox, sf::Vector2f(400, 60), sf::Color::White, 2, sf::Color::Black,
        center.x, center.y - 50);
    setupRectangle(saveButtonWindow, sf::Vector2f(200, 60), sf::Color::White, 2,
        sf::Color::Black, center.x, center.y + 50);
    setupText(saveButtonText, "Play", 40, sf::Color::Black,
        center.x, center.y + 60);
    setupText(uniqueNameText, "Type in a unique player name!", 30, sf::Color::Red,
        center.x, center.y + 150);
    setupText(patternNameText, "Type in name correct with pattern!", 30, sf::Color::Red,
        center.x, center.y + 250);
    setupText(playerNotFoundText, "Type in name of an existing player!", 30, sf::Color::Red,
        center.x, center.y + 150);
    setupText(instructionText, "", 30, sf::Color::Yellow, OPTION_GAP, OPTION_GAP);

    //Exeption in set position
    playerInputNameText.setFont(font);
    playerInputNameText.setCharacterSize(40);
    playerInputNameText.setFillColor(sf::Color::Black);
    playerInputNameText.setPosition(
        (window.getSize().x - playerNameBox.getSize().x) / 2.0f,
        window.getSize().y / 2.0f - 40
    );

    setupScoreTableWindow();
    
    setupBackButton();
}

void Interface::setupText(sf::Text& text, const std::string& content, int charSize, const sf::Color& color, float centerX, float posY) {
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(charSize);
    text.setFillColor(color);
    text.setPosition(centerX - text.getGlobalBounds().width / 2.0f , posY);
}

void Interface::setupRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, float centerX, float posY) {
    rectangle.setSize(size);
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setPosition(centerX - rectangle.getGlobalBounds().width / 2.0f, posY);
}
void Interface::loadResources() {
    if (!backgroundTexture.loadFromFile("Resources/Menu.jpg")) {
        std::cerr << "Failed to load image 'Resources/Menu.jpg'" << std::endl;
    }
}

void Interface::loadInstructions()
{
    instructionText.setString("");

    std::ifstream file("Resources/Instruction.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            instructionText.setString(instructionText.getString() + line + "\n");
        }
        file.close();
    }
    else {
        instructionText.setString("Failed to load instructions.");
    }
}

void Interface::setupBackground() {
    backgroundSprite.setTexture(backgroundTexture);

    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    float scale = std::min(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    sf::FloatRect spriteBounds = backgroundSprite.getGlobalBounds();
    backgroundSprite.setPosition(
        (window.getSize().x - spriteBounds.width) / 2.0f,
        (window.getSize().y - spriteBounds.height) / 2.0f
    );

}

void Interface::setupMenuOptions() {
    float startX = (window.getSize().x - OPTION_WIDTH) / 2;
    float startY = (window.getSize().y - (OPTION_HEIGHT + OPTION_GAP) * 5) / 2;

    addOption("New player", startY);
    addOption("Continue", startY + OPTION_HEIGHT + OPTION_GAP);
    addOption("Score table", startY + 2 * (OPTION_HEIGHT + OPTION_GAP));
    addOption("Rules", startY + 3 * (OPTION_HEIGHT + OPTION_GAP));
    addOption("Exit", startY + 4 * (OPTION_HEIGHT + OPTION_GAP));
}

void Interface::setupScoreTableWindow()
{

    float width = CELL_WIDTH;
    float height = (CELL_HEIGHT + CELL_GAP) * playerNames.size();
    setupRectangle(scoreTableWindow, sf::Vector2f(width, height), sf::Color::White, 2,
        sf::Color::Black, window.getSize().x / 2.0f, OPTION_GAP);

    for (size_t i = 0; i < playerNames.size(); ++i) {
        sf::Text playerOutputNameText;
        playerOutputNameText.setFont(font);
        playerOutputNameText.setString(playerNames[i]);
        playerOutputNameText.setCharacterSize(40);
        playerOutputNameText.setFillColor(sf::Color::Black);
        playerOutputNameText.setPosition(
            (window.getSize().x - CELL_WIDTH) / 2,
            (CELL_HEIGHT + CELL_GAP) * i + OPTION_GAP
        );

        playerNamesText.push_back(playerOutputNameText);
    }
}

void Interface::addOption(const std::string& text, float y) {
    sf::RectangleShape optionWindow;
    sf::Text optionText;

    optionText.setFont(font);
    optionText.setString(text);
    optionText.setCharacterSize(OPTION_CHARACTER_SIZE);
    optionText.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = optionText.getLocalBounds();
    optionText.setPosition((window.getSize().x - textBounds.width) / 2, y + (OPTION_HEIGHT - textBounds.height) / 2);

    optionWindow.setSize(sf::Vector2f(textBounds.width + 20, OPTION_HEIGHT));
    optionWindow.setPosition((window.getSize().x - textBounds.width - 20) / 2, y);
    optionWindow.setFillColor(sf::Color::White);
    optionWindow.setOutlineThickness(2);
    optionWindow.setOutlineColor(sf::Color::Black);

    optionWindows.push_back(optionWindow);
    optionTexts.push_back(optionText);
}

void Interface::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (currentState) {
        case State::MainMenu:
            handleMainMenuEvents(event);
            break;
        case State::NewPlayer:
            handleNewPlayerEvents(event);
            break;
        case State::ContinuePlayer:
            handleContinuePlayerEvents(event);
            break;
        case State::ScoreTable:
            handleScoreTableEvents(event);
            break;
        case State::Rules:
            handleRulesEvents(event);
            break;
        }
    }
    
}

void Interface::render() {
    window.clear();
    switch (currentState) {
    case State::MainMenu:
        renderMainMenu();
        break;
    case State::NewPlayer:
        renderNewPlayer();
        break;
    case State::ContinuePlayer:
        renderContinuePlayer();
        break;
    case State::ScoreTable:
        renderScoreTable();
        break;
    case State::Rules:
        renderRules();
        break;
    }
    window.display();
}


void Interface::handleMainMenuEvents(sf::Event& event) {
    switch (event.type) {
    case sf::Event::Closed:
        window.close();
        break;
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            checkOptionClicked(mousePos);
        }
        break;
    default:
        break;
    }
}

void Interface::handleNewPlayerEvents(sf::Event& event) {
    switch (event.type) {
    case sf::Event::Closed:
        window.close();
        break;
    case sf::Event::TextEntered:
        if (event.text.unicode == 8) { // Backspace
            if (!playerName.empty()) {
                playerName.pop_back();
            }
        }
        else if (event.text.unicode < 128) { // Regular ASCII characters
            playerName += static_cast<char>(event.text.unicode);
        }
        playerInputNameText.setString(playerName);
        break;
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (saveButtonWindow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                createPlayer();
            }
            else if (isBackButtonClicked(mousePos)) 
                currentState = State::MainMenu;
        }
        break;
    default:
        break;
    }
}

void Interface::handleContinuePlayerEvents(sf::Event& event) {
    switch (event.type) {
    case sf::Event::Closed:
        window.close();
        break;
    case sf::Event::TextEntered:
        if (event.text.unicode == 8) { // Backspace
            if (!playerName.empty()) {
                playerName.pop_back();
            }
        }
        else if (event.text.unicode < 128) { // Regular ASCII characters
            playerName += static_cast<char>(event.text.unicode);
        }
        playerInputNameText.setString(playerName);
        break;
    case sf::Event::MouseButtonPressed:
       if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (saveButtonWindow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (playerExists(playerName)) {
                    readyToStart = true;
                }
                else {
                    showUniqueNameMessage = true;
                }
            }
            else if (isBackButtonClicked(mousePos)) 
                currentState = State::MainMenu;
        }
        break;      
    default:
        break;
    }
}

void Interface::handleScoreTableEvents(sf::Event& event) {
   
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (backButtonWindow.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            currentState = State::MainMenu;
        }
    }

}

void Interface::handleRulesEvents(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (isBackButtonClicked(mousePos)) {
            currentState = State::MainMenu;
        }
    }
    else if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            // Scroll up
            scrollOffset += 10; 
        }
        else if (event.mouseWheelScroll.delta < 0) {
            // Scroll down
            scrollOffset -= 10; 
        }

        // Limiting scrolling to area of text
        scrollOffset = std::max(scrollOffset, -instructionText.getGlobalBounds().height + window.getSize().y - 200);
        scrollOffset = std::min(scrollOffset, 0.0f);
    }
}


void Interface::checkOptionClicked(sf::Vector2i& mousePos) {
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        if (optionWindows[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            switch (i) {
            case 0:
                currentState = State::NewPlayer;
                break;
            case 1:
                currentState = State::ContinuePlayer;
                break;
            case 2:
                loadPlayerNames();
                currentState = State::ScoreTable;
                break;
            case 3:
                loadInstructions();
                currentState = State::Rules;
                break;
            case 4:
                window.close();
                close = true;
                break;
            default:
                break;
            }
        }
    }
}


void Interface::renderMainMenu() {
    window.draw(backgroundSprite);
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        window.draw(optionWindows[i]);
        window.draw(optionTexts[i]);
    }
}

void Interface::renderNewPlayer() {
    window.draw(backgroundSprite);
    window.draw(enterNameText);
    window.draw(patternText);
    window.draw(playerNameBox);
    window.draw(playerInputNameText);
    window.draw(saveButtonWindow);
    window.draw(saveButtonText);

    if (showUniqueNameMessage)
        window.draw(uniqueNameText);
    if (showPatternNameMessage)
        window.draw(patternNameText);

    window.draw(backButtonWindow); 
    window.draw(backButtonText);
}

void Interface::renderContinuePlayer() {
    window.draw(backgroundSprite);
    window.draw(enterNameText);
    window.draw(playerNameBox);
    window.draw(playerInputNameText);
    window.draw(saveButtonWindow);
    window.draw(saveButtonText);

    if (showUniqueNameMessage)
        window.draw(playerNotFoundText);

    window.draw(backButtonWindow); 
    window.draw(backButtonText);
}

bool Interface::playerExists(const std::string& playerName) {
    std::ifstream file("PlayerData/name.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line == playerName) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void Interface::renderScoreTable() {
    window.draw(backgroundSprite);
    window.draw(scoreTableWindow);
    for (const auto& playerNameText : playerNamesText) {
        window.draw(playerNameText);
    }
    window.draw(backButtonWindow);
    window.draw(backButtonText);
}

void Interface::renderRules()
{
    window.draw(backgroundSprite); // Clear the window with white color
    window.draw(instructionText);   // Draw the instructions text
    window.draw(backButtonWindow);
    window.draw(backButtonText);

    instructionText.setPosition(50, 50 + scrollOffset);

}

void Interface::loadPlayerNames() {

    playerNames.clear();
    std::ifstream inFile("PlayerData/name.txt");
    std::string playerName;
    while (inFile >> playerName) {
        playerNames.push_back(playerName);
    }
    inFile.close();
    setupScoreTableWindow();
}

void Interface::setupBackButton()
{
    backButtonWindow.setSize(sf::Vector2f(200, 60));
    backButtonWindow.setFillColor(sf::Color::White);
    backButtonWindow.setOutlineThickness(2);
    backButtonWindow.setOutlineColor(sf::Color::Black);

    backButtonText.setFont(font);
    backButtonText.setString("Back");
    backButtonText.setCharacterSize(40);
    backButtonText.setFillColor(sf::Color::Black);

    sf::Vector2f center(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    backButtonWindow.setPosition(
        center.x - backButtonWindow.getSize().x / 2.0f,
        window.getSize().y - 100
    );
    backButtonText.setPosition(
        center.x - backButtonText.getGlobalBounds().width / 2.0f,
        window.getSize().y - 90
    );
}

bool Interface::isBackButtonClicked(sf::Vector2i mousePos)
{
    return backButtonWindow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Interface::createPlayer() {

        std::ifstream file("PlayerData/name.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line == playerName) {
                    showUniqueNameMessage = true;
                    file.close();
                    return;
                }
            }
            file.close();
        }
        
        std::regex reg("(?=\.*[a-z])(?=\.*[A-Z])(?=\.*\\d)\.{4,12}"); 

        auto isNameValid = std::regex_match(playerName, reg);
        if (not isNameValid) {
            showPatternNameMessage = true;
            return;
        }

        std::ofstream outfile("PlayerData/name.txt", std::ios_base::app);
        if (outfile.is_open()) {
            outfile << playerName << std::endl;
            outfile.close();
            showUniqueNameMessage = false;
            readyToStart = true; //success creating
        }   
}

void Interface::run() {
    while (window.isOpen() and not readyToStart) {
        handleEvents();
        render();
    }
}

bool Interface::getClose()
{
    return close;
}

