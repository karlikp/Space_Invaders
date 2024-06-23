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
	//Tworzenie obiektu zarz¹dzaj¹cego programem poza rozgrywk¹
	Interface interface;
	
	do{
		/* resetowanie wybranych pól obiektu, kluczowe gdy gracz
		   uruchamia dwie lub wiêcej rozgrywek bez wychodzenia z programu */
		interface.reset();

		// Obs³uga menu g³ównego
		interface.run();

		// Sprawdzenie czy gracz zamierza opóœciæ program
		if (interface.getExitProgram())
			return 0;
		// Utworzenie nowej rozgrywki
		Game* game = new Game();
		
		// G³ówna pêtla rozgrywki
		while (game->getWindowIsOpen() and !game->getEndGame())
		{
			game->update(); // Aktualizowanie stanu rozgrywki

			game->draw();   // Wypisywanie powy¿szego stanu na ekran
		}

		/* Po przekazaniu kluczowych danuch do obiektu interface nastêpuje zniszczenie
		   obiektu rozgrywka na wypadek gdyby gracz zamierza³ zagraæ po raz drugi */
		delete game;		

		/* Sprawdzenie czy gracz zamierza opóœciæ program,
		   jeœli nie to powtórz pêtle */
	} while (not interface.getExitProgram());
	return 0;
}

