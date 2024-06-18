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

float UFO::checkPowerupReach(sf::IntRect* i_player_hitbox)
{
    for (auto& const powerup : EntityManager::getPowerups()) //I tried use iterators and delete dead powerups but it generate errors
    {
        auto playerHitbox = *i_player_hitbox;
        if (powerup->getIsDead() == false && powerup->getHitbox().intersects(playerHitbox))
        {
            powerup->setIsDead(true);
            
            return powerup->randomPowerup();
        }
    }

	return 0;
}

bool UFO::checkBulletColision(sf::IntRect* i_player_hitbox)
{
		auto playerHitbox = *i_player_hitbox;
		if (getHitbox().intersects(playerHitbox))
		{
		
			EntityManager::addPowerup(std::make_unique<Powerup>(getX(), getY(), getStepX(), getStepY(), getScreenSize()));

			return 1;
		}
	

	return 0;
}

sf::IntRect UFO::getHitbox()
{
	return sf::IntRect(
		getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(UFO_HEIGHT_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(UFO_HEIGHT_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y);
}
