#include <iostream>
#include "Headers/Interface.h"
#include "Headers/Game.h"
#include "Headers/Enemy.h"
#include "Headers/Player.h"


#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	Interface interface;
	
	interface.run();

	short level = 1;

	//Init Game engine (object class needed to gameplay)
	Game game;

	//Game loop
	while (game.getWindowIsOpen() and !game.getEndGame())
	{
		game.update();

		game.render();

	}
	return 0;
}

