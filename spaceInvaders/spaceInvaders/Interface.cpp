#include "Headers/Interface.h"

Interface::Interface() {
    if (!font.loadFromFile("kenvector_future.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    window.create(sf::VideoMode::getDesktopMode(), "Menu", sf::Style::Fullscreen);
   
    std::cout << "Window created successfully." << std::endl;

    // Calculate Texture size
    unsigned int screenWidth = std::min(window.getSize().y * 2, window.getSize().x);
    unsigned int screenHeight = screenWidth / 2;

    // Load texture
    if (!backgroundTexture.loadFromFile("Resources/Menu.jpg")) {
        std::cerr << "Failed to load image 'Resources/Menu.jpg'" << std::endl;
    }
    
    backgroundSprite.setTexture(backgroundTexture);

    // Texture scale
    float scaleX = static_cast<float>(screenWidth) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(screenHeight) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);

    // Texture centre
    backgroundSprite.setPosition(
        float(window.getSize().x - screenWidth) / 2.0f,
        float(window.getSize().y - screenHeight) / 2.0f
    );


    // Calculate start position for options
    float optionWidth = 200; 
    float optionHeight = 50; 
    float startX = (window.getSize().x - optionWidth) / 2; 
    float startY = (window.getSize().y - optionHeight * 4) / 2;
    

    // Adding options(to center) to main manu 
    int gap = 20;
    addOption("New player", startY);
    addOption("Continue", startY + 50 + gap);
    addOption("Score table", startY + 2 * (50 + gap));
    addOption("Rules", startY + 3 * (50 + gap));
    addOption("Exit", startY + 4 * (50 + gap));
}


void Interface::addOption(const std::string& text, float y) {
    sf::RectangleShape optionWindow;
    sf::Text optionText;

    optionText.setFont(font);
    optionText.setString(text);
    optionText.setCharacterSize(40);
    optionText.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = optionText.getLocalBounds();
    optionText.setPosition((window.getSize().x - textBounds.width) / 2, y + (30 - textBounds.height) / 2);

    optionWindow.setSize(sf::Vector2f(textBounds.width + 20, 50));
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
}

//Logics for options
void Interface::checkOptionClicked(sf::Vector2i mousePos) {
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        if (optionWindows[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            std::cout << "Option " << i + 1 << " clicked!" << std::endl;
            
        }
    }
}

void Interface::render() {
    window.clear();
    window.draw(backgroundSprite); 
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        window.draw(optionWindows[i]);
        window.draw(optionTexts[i]);
    }
    window.display();
}

void Interface::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}
