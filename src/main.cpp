#include <iostream>
#include "../headers/Interface.h"
#include "../headers/Game.h"
#include "../headers/Enemy.h"
#include "../headers/Enemy1.h"
#include "../headers/Player.h"
#include "../headers/EntityManager.h"


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

