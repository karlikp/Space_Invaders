#include "../headers/Interface.h"
#include "../headers/Player.h"

const float OPTION_WIDTH = 200.0f;
const float OPTION_HEIGHT = 50.0f;
const float OPTION_GAP = 20.0f;
const int OPTION_CHARACTER_SIZE = 40;
const bool WITHOUT_MESSAGE = false;
const bool WITH_MESSAGE = true;
const float CELL_WIDTH = 400.0f;
const float CELL_HEIGHT = 50.0f;
const float CELL_GAP = 10.0f;

sf::RenderWindow Interface::window;
sf::RenderWindow* Interface::windowPtr;

bool Interface::gameIsFinish, Interface::readyToStart, Interface::isRecord,Interface::win, 
Interface::uniqueMessageWasShow, Interface::patternMessageWasShow, Interface::tableWasSet;
int Interface::newPoints;

//windows initialisation 
Interface::Interface() {
    scrollOffset = 0;
    previousPoints = 0;
    newPoints = 0;
    gameIsFinish = false;
    isRecord = false;
    win = false;
    patternMessageWasShow = false;
    successCreating = false;
    readyToStart = false;
    uniqueMessageWasShow = false;
    exitProgram = false;

    if (!font.loadFromFile("../resources/texts/ARIAL.TTF")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    chooseVideoMode();

    window.create(videoMode, "Space Invaders", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

 
    loadBackground();
    loadScoreTable();
    setupBackground();
    setupMenuOptions();
    setupBackground();

    // Set message communication inside background
    center = { window.getSize().x / 2.0f, window.getSize().y / 2.0f };

    std::thread thread1(&Interface::setupText, this, std::ref(uniqueNameText), "Enter a unique name, which include:", 50, sf::Color::Yellow,
        center.x, center.y - 200);
    std::thread thread2(&Interface::setupText, this, std::ref(patternText), "- lowercase, uppercase and digit\n- from 4 to 12 signs without special characters",
        30, sf::Color::Yellow, center.x, center.y - 130);
    std::thread thread3([&]() {
        this->setupRectangle(std::ref(playerNameWindow), sf::Vector2f(400, 60), sf::Color::White, 2, sf::Color::Black,
        center.x, center.y - 50);
        });
    std::thread thread4([&]() {
        this->setupRectangle(std::ref(playButton), sf::Vector2f(200, 60), sf::Color::White, 2,
        sf::Color::Black, center.x, center.y + 50);
        });
    std::thread thread5(&Interface::setupText, this, std::ref(saveButtonText), "Play", 40, sf::Color::Black,
        center.x, center.y + 60);
    std::thread thread6(&Interface::setupText, this, std::ref(uniqueInfoText), "Type in a unique player name!", 30, sf::Color::Red,
        center.x, center.y + 150);
    std::thread thread7(&Interface::setupText, this, std::ref(patternNameText), "Type in name correct with pattern!", 30, sf::Color::Red,
        center.x, center.y + 250);
    std::thread thread8(&Interface::setupText, this, std::ref(playerNotFoundText), "Type in name of an existing player!", 30, sf::Color::Red,
        center.x, center.y + 150);
    std::thread thread9(&Interface::setupText, this, std::ref(instructionText), "", 30, sf::Color::Yellow, 50, 50 + scrollOffset);
    std::thread thread10(&Interface::setupText, this, std::ref(existNameText), "Enter the name of an existing player", 50, sf::Color::Yellow,
        center.x, center.y - 200);
        
    // Wait for synch
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();
    thread9.join();
    thread10.join();

    //Exeption in set position
    playerInputNameText.setFont(font);
    playerInputNameText.setCharacterSize(40);
    playerInputNameText.setFillColor(sf::Color::Black);
    playerInputNameText.setPosition(
        (window.getSize().x - playerNameWindow.getSize().x) / 2.0f,
        window.getSize().y / 2.0f - 40
    );

    setupScoreTableWindow();
    
    setupBackButton();

    loadInstructions();
}

void Interface::initSummaryGame()
{
    if (win) {
        setupText(summaryScoreText, "Victory!", 60, sf::Color::Yellow, center.x, center.y - 200);
    }
    else {
        setupText(summaryScoreText, "Failure", 60, sf::Color::Yellow, center.x, center.y - 200);
    }
    

    std::thread summaryThread2(&Interface::setupText, this, std::ref(summaryPointsText), "Points: " + std::to_string(newPoints),
        30, sf::Color::Yellow, center.x, center.y - 130);    

    std::thread summaryThread3([&]() {
        this->setupRectangle(std::ref(summaryBackButton), sf::Vector2f(300, 60), sf::Color::White, 2,
        sf::Color::Black, center.x - 300, center.y + 50);
        });
    std::thread summaryThread4(&Interface::setupText, this, std::ref(summaryBackText), "Main menu", 40, sf::Color::Black,
        center.x - 310, center.y + 60);

    std::thread summaryThread5([&]() {
        this->setupRectangle(std::ref(summaryExitButton), sf::Vector2f(300, 60), sf::Color::White, 2,
        sf::Color::Black, center.x + 300, center.y + 50);
        });
    std::thread summaryThread6(&Interface::setupText, this, std::ref(summaryExitText), "Exit", 40, sf::Color::Black,
        center.x + 300, center.y + 60);

    summaryThread2.join();
    summaryThread3.join();
    summaryThread4.join();
    summaryThread5.join();
    summaryThread6.join();
}

void Interface::newPlayerActions()
{
    if (not playerExists(playerName)) {
        checkPattern();
    }
    else {
        uniqueMessageWasShow = true;
    }
    return;
}

void Interface::playContinueActions()
{
    if (playerExists(playerName)) {

        playerErase(playerName);
        readyToStart = true;
        currentState = State::SummaryGame;
    }
    else {
        uniqueMessageWasShow = true;
    }
}

sf::RenderWindow* Interface::getWindowPtr()
{
    return &window;
}

void Interface::setGameIsFinish(bool newState)
{
    gameIsFinish = newState;
}

void Interface::setWin(bool newState)
{
    win = newState;
}

void Interface::setNewPoints(int iNewPoints)
{
    newPoints = iNewPoints;
}

void Interface::setReadyToStart(bool newState)
{
    readyToStart = newState;
}

void Interface::setIsRecord(bool newState)
{
    isRecord = newState;
}

void Interface::setPatternMessageWasShow(bool newState)
{
    patternMessageWasShow = newState;
}

void Interface::setUniqueMessageWasShow(bool newState)
{
    uniqueMessageWasShow = newState;
}

void Interface::setTableWasSet(bool newState)
{
    tableWasSet = newState;
}

void Interface::setupText(sf::Text& text, const std::string& content, int charSize, const sf::Color& color, float centerX, float posY) {

    std::lock_guard<std::mutex> lock(mutex);
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(charSize);
    text.setFillColor(color);
    text.setPosition(centerX - text.getGlobalBounds().width / 2.0f , posY);
}

void Interface::setupRectangle(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Color& fillColor, float outlineThickness, const sf::Color& outlineColor, float centerX, float posY) {
   
    
    std::lock_guard<std::mutex> lock(mutex); 
    rectangle.setSize(size);
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setPosition(centerX - rectangle.getGlobalBounds().width / 2.0f, posY);
}
void Interface::loadBackground() {
    if (!backgroundTexture.loadFromFile("../resources/textures/menu.jpg")) {
        std::cerr << "Failed to load image '../resources/textures/menu.jpg'" << std::endl;
    }
}

void Interface::loadInstructions()
{
    instructionText.setString("");

    std::ifstream file("../resources/texts/instruction.txt");
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

    std::thread thread1(&Interface::addOption, this, "New player", startY);
    std::thread thread2(&Interface::addOption, this, "Continue", startY + OPTION_HEIGHT + OPTION_GAP);
    std::thread thread3(&Interface::addOption, this, "Score table", startY + 2 * (OPTION_HEIGHT + OPTION_GAP));
    std::thread thread4(&Interface::addOption, this, "Rules", startY + 3 * (OPTION_HEIGHT + OPTION_GAP));
    std::thread thread5(&Interface::addOption, this, "Exit", startY + 4 * (OPTION_HEIGHT + OPTION_GAP));

    // Waiting for threads to finish
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
}

void Interface::setupScoreTableWindow()
{
    playerNamesText.clear();
    float width = CELL_WIDTH;
    float height = (CELL_HEIGHT + CELL_GAP) * records.size();
    setupRectangle(scoreTableWindow, sf::Vector2f(width, height), sf::Color::White, 2,
        sf::Color::Black, window.getSize().x / 2.0f, OPTION_GAP);

    for (size_t i = 0; i < records.size(); ++i) {
        sf::Text playerOutputNameText;
        playerOutputNameText.setFont(font);
        playerOutputNameText.setString(records[i].first + ' ' + std::to_string(records[i].second));
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
    std::lock_guard<std::mutex> lock(mutex);

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

void Interface::chooseVideoMode()
{
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    
    sf::VideoMode bestMode = modes[0];
    for (const auto& mode : modes) {
        if (mode.width > bestMode.width || mode.height > bestMode.height) {
            bestMode = mode;
        }
    }
    videoMode = bestMode;
}

void Interface::updateLastScore()
{
    auto theBest = std::max(previousPoints, newPoints);
    records.push_back({ playerName, theBest});
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
                if (tableWasSet == false) {
                    setupScoreTableWindow();
                    tableWasSet = true;
                }
                currentState = State::ScoreTable;
                break;
            case 3:
                currentState = State::Rules;
                break;
            case 4:
                currentState = State::Exit;
                break;
            default:
                break;
            }
        }
    }
}

void Interface::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event) or gameIsFinish) {
        gameIsFinish = false;

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
        case State::SummaryGame:

            initSummaryGame();
            if (not isRecord) {
                updateLastScore();
                sortScoreTable();
                recordScoreTable();
                isRecord = true;
                
            }
            handleSummaryGameEvents(event);
       
            break;
        case State::Exit:
            handleExit();
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
        renderInstruction();
        break;
    case State::SummaryGame:
        renderSummaryGame();
        break;
    }
    window.display();
}


void Interface::handleMainMenuEvents(sf::Event& event) {
    switch (event.type) {
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
    case sf::Event::TextEntered:
        if (event.text.unicode == 8) { //Backspace
            if (!playerName.empty()) {
                playerName.pop_back();
            }
        }
        else if (event.text.unicode == 13) { //Enter
            newPlayerActions();
        }
        else if (event.text.unicode < 128) { // Regular ASCII characters except Enter
            playerName += static_cast<char>(event.text.unicode);
        }
        playerInputNameText.setString(playerName);
        break;
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            
            if (isPlayButtonClicked(mousePos)) {
                newPlayerActions();
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
    case sf::Event::TextEntered:
        if (event.text.unicode == 8) { //Backspace
            if (!playerName.empty()) {
                playerName.pop_back();
            }
        }
        else if (event.text.unicode == 13) { //Enter
            playContinueActions();
        }
        else if (event.text.unicode < 128) { //Regular ASCII characters
            playerName += static_cast<char>(event.text.unicode);
        }
        playerInputNameText.setString(playerName);
        break;
    case sf::Event::MouseButtonPressed:
       if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (isPlayButtonClicked(mousePos)) {
                playContinueActions();
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
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                currentState = State::MainMenu;
            }
        }
    }

}

void Interface::handleRulesEvents(sf::Event& event) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (isBackButtonClicked(mousePos)) {
                currentState = State::MainMenu;
            }
        }
    case sf::Event::MouseWheelScrolled:
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

void Interface::handleSummaryGameEvents(sf::Event& event)
{
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (summaryExitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                currentState = State::Exit;

            else if (summaryBackButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                currentState = State::MainMenu;
        }
    }
}

void Interface::handleExit()
{
    window.close();
    exitProgram = true;
}

void Interface::renderSummaryGame()
{
    window.draw(backgroundSprite);
    window.draw(summaryScoreText);
    window.draw(summaryPointsText);
    window.draw(summaryBackButton);
    window.draw(summaryBackText);
    window.draw(summaryExitButton);
    window.draw(summaryExitText);
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
    window.draw(uniqueNameText);
    window.draw(patternText);
    window.draw(playerNameWindow);
    window.draw(playerInputNameText);
    window.draw(playButton);
    window.draw(saveButtonText);

    if (uniqueMessageWasShow)
        window.draw(uniqueInfoText);
    if (patternMessageWasShow)
        window.draw(patternNameText);

    window.draw(backButton); 
    window.draw(backButtonText);
}

void Interface::renderContinuePlayer() {
    window.draw(backgroundSprite);
    window.draw(existNameText);
    window.draw(playerNameWindow);
    window.draw(playerInputNameText);
    window.draw(playButton);
    window.draw(saveButtonText);

    if (uniqueMessageWasShow)
        window.draw(playerNotFoundText);

    window.draw(backButton); 
    window.draw(backButtonText);
}

bool Interface::playerExists(const std::string& playerName) {
    std::ifstream file("../resources/texts/scoreTable.txt");
  
    for (auto record : records) {
        if (record.first == playerName) {
            return true;
        }  
    }
    return false;
}

void Interface::playerErase(const std::string& playerName) {

    for (auto it = records.begin(); it != records.end();) {
        if (it->first == playerName) {
            previousPoints = it->second;
            it = records.erase(it);
        }
        else {
            it++;
        }
    }
}

void Interface::renderScoreTable() {
    window.draw(backgroundSprite);
    window.draw(scoreTableWindow);
    for (const auto& playerNameText : playerNamesText) {
        window.draw(playerNameText);
    }
    window.draw(backButton);
    window.draw(backButtonText);
}

void Interface::renderInstruction()
{
    window.draw(backgroundSprite); // Clear the window with white color
    instructionText.setPosition(50, 50 + scrollOffset);
    window.draw(instructionText);   // Draw the instructions text
    window.draw(backButton);
    window.draw(backButtonText);    
}

void Interface::setupBackButton()
{
    backButton.setSize(sf::Vector2f(200, 60));
    backButton.setFillColor(sf::Color::White);
    backButton.setOutlineThickness(2);
    backButton.setOutlineColor(sf::Color::Black);

    backButtonText.setFont(font);
    backButtonText.setString("Back");
    backButtonText.setCharacterSize(40);
    backButtonText.setFillColor(sf::Color::Black);

    sf::Vector2f center(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    backButton.setPosition(
        center.x - backButton.getSize().x / 2.0f,
        window.getSize().y - 100
    );
    backButtonText.setPosition(
        center.x - backButtonText.getGlobalBounds().width / 2.0f,
        window.getSize().y - 90
    );
}

bool Interface::isBackButtonClicked(sf::Vector2i mousePos)
{
    return backButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Interface::isExitButtonClicked(sf::Vector2i mousePos)
{
    return exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Interface::isPlayButtonClicked(sf::Vector2i mousePos)
{
    return playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Interface::loadScoreTable()
{
    records.clear();

    std::filesystem::path inputPath = "../resources/texts/scoreTable.txt";

    if (!std::filesystem::exists(inputPath)) {
        std::cerr << "Unable to open file: " << inputPath << std::endl;
        return;
    }
   std::ifstream inputFile(inputPath);
   std::string name;
   int score;

   while (inputFile >> name >> score) {
        records.push_back({name, score});
   }
   inputFile.close();

}

void Interface::sortScoreTable()
{
    std::ranges::sort(records, [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return b.second < a.second;
        });
}

void Interface::recordScoreTable()
{
    std::filesystem::path outputPath = "../resources/texts/scoreTable.txt";

    std::ofstream outputFile(outputPath, std::ofstream::trunc);
    if (!outputFile) {
        std::cerr << "Unable to open file: " << outputPath << std::endl;
        return;
    }

    for (const auto& record : records) {
        outputFile << record.first << " " << record.second << std::endl;
    }
    outputFile.close();
}

void Interface::reset()
{
    successCreating = false;
}

void Interface::checkPattern() {
 
        std::regex reg("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{4,12}$"); 

        auto isNameValid = std::regex_match(playerName, reg);
        if (not isNameValid) {
            patternMessageWasShow = true;
        }
        else {
            readyToStart = true;
            currentState = State::SummaryGame;
        }
        return;
}

void Interface::run() {
    while (window.isOpen() and not readyToStart) {
        handleEvents();

        render();
    }
}

bool Interface::getExitProgram()
{
    return exitProgram;
}

