#include "Headers/Interface.h"

Interface::Interface() {
    if (!font.loadFromFile("kenvector_future.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    window.create(sf::VideoMode::getDesktopMode(), "Menu", sf::Style::Fullscreen);
    // window.create(sf::VideoMode(800, 600), "Menu", sf::Style::Close);
    std::cout << "Window created successfully." << std::endl;

    // Obliczenie rozmiaru t�a
    unsigned int screenWidth = std::min(window.getSize().y * 2, window.getSize().x);
    unsigned int screenHeight = screenWidth / 2;

    // Wczytanie tekstury t�a
    if (!backgroundTexture.loadFromFile("Resources/Menu.jpg")) {
        std::cerr << "Failed to load image 'Resources/Menu.jpg'" << std::endl;
    }

    // Ustawienie tekstury t�a na sprite
    backgroundSprite.setTexture(backgroundTexture);

    // Obliczenie skalowania tekstury t�a
    float scaleX = static_cast<float>(screenWidth) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(screenHeight) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);

    // Ustawienie po�o�enia t�a w centralnym punkcie okna
    backgroundSprite.setPosition(
        float(window.getSize().x - screenWidth) / 2.0f,
        float(window.getSize().y - screenHeight) / 2.0f
    );

    // Ustaw okna opcji na �rodku okna g��wnego
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        // Oblicz rozmiar i pozycj� ka�dego okna opcji
        sf::FloatRect optionBounds = optionTexts[i].getLocalBounds();
        float optionWidth = optionBounds.width + 40; // 20 pikseli marginesu z ka�dej strony
        float optionHeight = optionBounds.height + 20; // 10 pikseli marginesu z ka�dej strony
        float optionX = (window.getSize().x - optionWidth) / 2.0f; // Pozycja X na �rodku okna
        float optionY = (window.getSize().y - optionHeight * optionWindows.size()) / 2.0f + i * optionHeight; // Roz�o�enie opcji r�wnomiernie na �rodku okna
        optionWindows[i].setPosition(optionX, optionY);
        optionWindows[i].setSize(sf::Vector2f(optionWidth, optionHeight));
        optionTexts[i].setPosition(optionX + 20, optionY + 10); // Ustawienie tekstu wewn�trz okna opcji
    }


    // Obliczanie pozycji pocz�tkowych dla opcji
    float optionWidth = 200; // Szeroko�� okna opcji
    float optionHeight = 50; // Wysoko�� okna opcji
    float startX = (window.getSize().x - optionWidth) / 2; // Pocz�tkowa pozycja X
    float startY = (window.getSize().y - optionHeight * 4) / 2; // Pocz�tkowa pozycja Y

    // Obliczanie pozycji pocz�tkowych dla opcji
   // float startY = (window.getSize().y - 4 * 50 - 3 * 10) / 2; // Pocz�tkowa pozycja Y

    // Dodawanie opcji do menu na �rodku ekranu
    int gap = 20;
    addOption("New player", startY);
    addOption("Continue", startY + 50 + gap);
    addOption("Score table", startY + 2 * (50 + gap));
    addOption("Rules", startY + 3 * (50 + gap));
    addOption("Exit", startY + 4 * (50 + gap));
}

// Metoda dodaj�ca opcj� do menu
void Interface::addOption(const std::string& text, float y) {
    sf::RectangleShape optionWindow;
    sf::Text optionText;

    optionText.setFont(font);
    optionText.setString(text);
    optionText.setCharacterSize(40);
    optionText.setFillColor(sf::Color::Black);

    // Obliczanie pozycji opcji
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

void Interface::checkOptionClicked(sf::Vector2i mousePos) {
    for (size_t i = 0; i < optionWindows.size(); ++i) {
        if (optionWindows[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            std::cout << "Option " << i + 1 << " clicked!" << std::endl;
            // Tutaj mo�na doda� logik� dla wybranej opcji
        }
    }
}

void Interface::render() {
    window.clear();
    window.draw(backgroundSprite); // Rysowanie t�a
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
