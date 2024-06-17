#include "Headers/UFO.h"
#include "Headers/Global.h"

UFO::UFO(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	float scale = (UFO_HEIGHT_RATIO * iScreenSize.y) / UFO_DEFAULT_HEIGHT;

	setEntitySprite("Resources/UFO.png");
	setEntityScale(scale);
}

void UFO::update()
{
	setEntityPosition();
}

void UFO::draw()
{//TO DO
}

short int UFO::checkPowerupReach(sf::IntRect& i_player_hitbox)
{
	return 0;
}
