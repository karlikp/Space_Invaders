#include "Headers/Interface.h"

const float OPTION_WIDTH = 200.0f;
const float OPTION_HEIGHT = 50.0f;
const float OPTION_GAP = 20.0f;
const int OPTION_CHARACTER_SIZE = 40;
const bool WITHOUT_MESSAGE = false;
const bool WITH_MESSAGE = true;

//windows initialisation 
Interface::Interface() {
    startGame = false;
    noRecord = true;
    if (!font.loadFromFile("Resources/ARIAL.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    window.create(sf::VideoMode::getDesktopMode(), "Menu", sf::Style::Fullscreen);

    std::cout << "Window created successfully." << std::endl;

    loadResources();
    setupBackground();
    setupMenuOptions();

    playerNameText.setFont(font);
    playerNameText.setCharacterSize(40);
    playerNameText.setFillColor(sf::Color::Black);

    enterNameText.setFont(font);
    enterNameText.setString("Enter your name:");
    enterNameText.setCharacterSize(50);
    enterNameText.setFillColor(sf::Color::Black);

    playerNameBox.setSize(sf::Vector2f(400, 60));
    playerNameBox.setFillColor(sf::Color::White);
    playerNameBox.setOutlineThickness(2);
    playerNameBox.setOutlineColor(sf::Color::Black);

    saveButtonText.setFont(font);
    saveButtonText.setString("Save");
    saveButtonText.setCharacterSize(40);
    saveButtonText.setFillColor(sf::Color::Black);

    saveButtonWindow.setSize(sf::Vector2f(200, 60));
    saveButtonWindow.setFillColor(sf::Color::White);
    saveButtonWindow.setOutlineThickness(2);
    saveButtonWindow.setOutlineColor(sf::Color::Black);

    uniqueNameText.setFont(font);
    uniqueNameText.setString("Choose a unique player name!");
    uniqueNameText.setCharacterSize(30);
    uniqueNameText.setFillColor(sf::Color::Red);
}

void Interface::loadResources() {
    if (!backgroundTexture.loadFromFile("Resources/Menu.jpg")) {
        std::cerr << "Failed to load image 'Resources/Menu.jpg'" << std::endl;
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

    // Ustawienie pozycji komunikatów wewn¹trz t³a
    sf::Vector2f center(
        window.getSize().x / 2.0f,
        window.getSize().y / 2.0f
    );

    enterNameText.setPosition(
        center.x - enterNameText.getGlobalBounds().width / 2.0f,
        center.y - 150
    );
    playerNameBox.setPosition(
        center.x - playerNameBox.getSize().x / 2.0f,
        center.y - 50
    );
    playerNameText.setPosition(
        center.x - playerNameBox.getSize().x / 2.0f + 10,
        center.y - 40
    );

    saveButtonWindow.setPosition(
        center.x - saveButtonWindow.getSize().x / 2.0f,
        center.y + 50
    );
    saveButtonText.setPosition(
        center.x - saveButtonText.getGlobalBounds().width / 2.0f,
        center.y + 60
    );
    uniqueNameText.setPosition(
        center.x - saveButtonText.getGlobalBounds().width / 2.0f,
        center.y + 150
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
        }
    }
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
        playerNameText.setString(playerName);
        break;
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (saveButtonWindow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                savePlayerName();
            }
        }
        break;
    default:
        break;
    }
}

void Interface::checkOptionClicked(sf::Vector2i mousePos) {
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        if (optionWindows[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            std::cout << "Option " << i + 1 << " clicked!" << std::endl;
            if (optionTexts[i].getString() == "New player") {
                currentState = State::NewPlayer;
            }
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
        renderNewPlayer(WITHOUT_MESSAGE);
        break;
    }
    window.display();
}

void Interface::renderMainMenu() {
    window.draw(backgroundSprite);
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        window.draw(optionWindows[i]);
        window.draw(optionTexts[i]);
    }
}

void Interface::renderNewPlayer(bool showUniqueNameMessage) {
    window.draw(backgroundSprite);
    window.draw(enterNameText);
    window.draw(playerNameBox);
    window.draw(playerNameText);
    window.draw(saveButtonWindow);
    window.draw(saveButtonText);

    if (showUniqueNameMessage)
        window.draw(uniqueNameText);
}

void Interface::playGame() {
    savePlayerName()
}

void Interface::savePlayerName() {

    while (noRecord) {

        std::ifstream file("PlayerData/name.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line == playerName) {
                    renderNewPlayer(WITH_MESSAGE);
                    file.close();
                    return;
                }
            }
            file.close();
        }
        else {
            std::cerr << "Unable to open file for reading player names!" << std::endl;
            return;
        }

        std::ofstream outfile("PlayerData/name.txt", std::ios_base::app);
        if (outfile.is_open()) {
            outfile << playerName << std::endl;
            outfile.close();
            std::cout << "Player name saved successfully!" << std::endl;
            renderNewPlayer(WITHOUT_MESSAGE);
            noRecord = false;

        }
        else {
            std::cerr << "Unable to open file for saving player name!" << std::endl;
        }
    }
}

void Interface::run() {
    while (window.isOpen() and not startGame) {
        handleEvents();
        render();
    }
}

