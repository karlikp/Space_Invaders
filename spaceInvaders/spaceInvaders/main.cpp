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

	short level = 1;

	//Init Game engine (object class needed to gameplay)
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

