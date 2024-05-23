#include <iostream>
#include "Headers/Game.h"
#include "Headers/Entity.h"
#include "Headers/Player.h"


#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	//Init Game engine
	Game game;

	//Init Entity objects
	Player player;
	set


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

