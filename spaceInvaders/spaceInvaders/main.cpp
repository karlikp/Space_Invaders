#include <iostream>
#include "Headers/Interface.h"
#include "Headers/Game.h"
#include "Headers/Enemy.h"
#include "Headers/Enemy1.h"
#include "Headers/Player.h"
#include "Headers/EntityManager.h"


#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	Interface interface;
	
	do{
		interface.reset();

		interface.run();

		if (interface.getExitProgram())
			return 0;

		Game* game = new Game();
		
		while (game->getWindowIsOpen() and !game->getEndGame())
		{
			game->update();

			game->draw();
		}

		delete game;

	} while (not interface.getExitProgram());

	return 0;
}

