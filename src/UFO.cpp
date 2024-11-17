#include "../headers/UFO.h"
#include "../headers/Global.h"
#include "../headers/EntityManager.h"
#include "../headers/Player.h"

UFO::UFO(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	x = iPosX;
	y = iPosY;
	stepX = iStepX;
	stepY = iStepY;
	screenSize = iScreenSize;
	
	float scale = (UFO_HEIGHT_RATIO * iScreenSize.y) / UFO_DEFAULT_HEIGHT;

	setEntitySprite("../resources/textures/ufo.png");
	setEntityScale(scale);
	setEntityPosition();
}

void UFO::update()
{
	if (getIsDead() == false) {
		setX(getX() - UFO_MOVE_SPEED);

		if (getX() < 0 - (UFO_HEIGHT_RATIO * getScreenSize().y)) {
			setIsDead(true);
		}
	}
	else {
		setX(screenSize.x + (2 * UFO_WIDTH_RATIO * screenSize.y));
		setY(0.1 * screenSize.y);
		setIsDead(false);
		Player::setUfoInProgress(false);
	}
	
	setEntityPosition();
}

short UFO::checkPowerupCollision(sf::IntRect* iPlayerHitbox)
{
	auto playerHitbox = *iPlayerHitbox;
    for (const auto& powerup : EntityManager::getPowerups()) //I tried use iterators and delete dead powerups but it generate errors
    {
        if (powerup->getIsDead() == false && powerup->getHitbox().intersects(playerHitbox))
        {
            powerup->setIsDead(true);
            
            return powerup->generatorType(); //collision existed
        }
    }

	return 0; //lack of collision
}

bool UFO::checkBulletCollision(sf::IntRect iBulletHitbox)
{
		if (getHitbox().intersects(iBulletHitbox))
		{
			setIsDead(true);

			EntityManager::addPowerup(std::make_unique<Powerup>(getX(), getY(), MOTIONLESS_X, -POWERUP_SPEED, getScreenSize(), UFO_WIDTH_RATIO));

			return 1;
		}
	
	return 0;
}

sf::IntRect UFO::getHitbox()
{
	return sf::IntRect(
		getX() + HITBOX_MARGIN_RATIO,
		getY() + HITBOX_MARGIN_RATIO,
		(UFO_WIDTH_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(UFO_HEIGHT_RATIO - 2 * HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

short UFO::getPowerupType()
{
	return powerupType;
}
