#include "Headers/Player.h"

Player::Player()
{
	posX = (0.5 * window.getSize().x);

	bulletTexture.loadFromFile("Resources/playerBullet1.png");
	shipTexture.loadFromFile("Resources/playerShip1_blue.png");

	bulletSprite.setTexture(bulletTexture);
	shipSprite.setTexture(shipTexture);

}

void Player::update()
{
	
}

void Player::rendering()
{
	if (not isDead) {
		shipSprite.setPosition(posX, posY);

	}
}

//void Player::reset()
//{//TO DO
//}
