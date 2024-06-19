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

	// cztery omawiane techniki,
	// sprytniejsi przeciwnicy kr¹¿¹cy po innym torze ok
	// komunikat o wygranej
	// dokoñczenie bonusów (podniesienie przeciwników)


	Interface interface;
	
	interface.run();

	if (interface.getExitProgram())
		return 0;

	short level = 1;

	do{

		//Game* game = new Game();

		////Game loop
		//while (game->getWindowIsOpen() and !game->getEndGame())
		//{
		//	game->update();

		//	game->draw();
		//}

		interface.getGameInfo();

		/*delete game;*/

		interface.run();

	} while (not interface.getExitProgram());

	//interface.closeWindow();
	
	return 0;

}

