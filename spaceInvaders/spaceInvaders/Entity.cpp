#include "Headers/Entity.h"
#include "Headers/Game.h"


Entity::Entity(short x, short y) : posX(x), posY(y) {

	window = &Game::window;

};