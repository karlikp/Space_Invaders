#include "Headers/Player.h"

Player::Player()
{
	reset();

	bulletTexture.loadFromFile("Resources/Images/playerBullet1.png");
	shipTexture.loadFromFile("Resources/Images/playerShip1.png");

	bulletSprite.setTexture(bulletTexture);
	shipSprite.setTexture(shipTexture);
}

void Player::update()
{//TO DO
}

void Player::rendering()
{//TO DO
}

void Player::reset()
{//TO DO
}
