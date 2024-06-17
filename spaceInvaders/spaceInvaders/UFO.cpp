#include "Headers/UFO.h"
#include "Headers/Global.h"
#include "Headers/EntityManager.h"

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
	auto iPowerups = EntityManager::getPowerups();
	for (Powerup& const powerup : iPowerups )
	{
		if (0 == powerup.dead && 1 == powerup.get_hitbox().intersects(i_player_hitbox))
		{
			powerup.dead = 1;

			//Plus 1, because 0 means we didn't pick up any powerups.
			return 1 + powerup.type;
		}
	}

	return 0;
}
