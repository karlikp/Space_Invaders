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
	//Tworzenie obiektu zarz�dzaj�cego programem poza rozgrywk�
	Interface interface;
	
	do{
		/* resetowanie wybranych p�l obiektu, kluczowe gdy gracz
		   uruchamia dwie lub wi�cej rozgrywek bez wychodzenia z programu */
		interface.reset();

		// Obs�uga menu g��wnego
		interface.run();

		// Sprawdzenie czy gracz zamierza op�ci� program
		if (interface.getExitProgram())
			return 0;
		// Utworzenie nowej rozgrywki
		Game* game = new Game();
		
		// G��wna p�tla rozgrywki
		while (game->getWindowIsOpen() and !game->getEndGame())
		{
			game->update(); // Aktualizowanie stanu rozgrywki

			game->draw();   // Wypisywanie powy�szego stanu na ekran
		}

		/* Po przekazaniu kluczowych danuch do obiektu interface nast�puje zniszczenie
		   obiektu rozgrywka na wypadek gdyby gracz zamierza� zagra� po raz drugi */
		delete game;		

		/* Sprawdzenie czy gracz zamierza op�ci� program,
		   je�li nie to powt�rz p�tle */
	} while (not interface.getExitProgram());
	return 0;
}

