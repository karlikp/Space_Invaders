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
	/*Interface interface;
	
	interface.run();

	if (interface.getClose())
		return 0;

	short level = 1;*/

	//Init Game engine (object class needed to gameplay)
	Game game;

	//Game loop
	while (game.getWindowIsOpen() and !game.getEndGame())
	{
		game.update();

		game.draw();

	}
	

	return 0;

	//EntityManager manager;

	//Enemy* pEnemy = new Enemy1();

	//manager.addEnemy(std::make_unique<Enemy1>());
}

