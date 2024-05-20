#include <iostream>
#include "Headers/Game.h"

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	//Init Game engine
	Game game;

	//Game loop
	while (game.getWindowIsOpen() and !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();

	}
	return 0;
}

//int main(void) {
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}

