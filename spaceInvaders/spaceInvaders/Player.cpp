#include "Headers/Player.h"


Player::Player(sf::RenderWindow* window)
{
	bulletTexture.loadFromFile("Resources/playerBullet1.png");
	shipTexture.loadFromFile("Resources/playerShip1_blue.png");

	bulletSprite.setTexture(bulletTexture);
	shipSprite.setTexture(shipTexture);

	//Zeskalowaæ sprite oraz ustawiæ obiekt w odpowiednim miejscu
}

Player::Player(float x, float y) : Entity(x, y) {

	

	bulletTexture.loadFromFile("Resources/playerBullet1.png");
	shipTexture.loadFromFile("Resources/playerShip1_blue.png");

	bulletSprite.setTexture(bulletTexture);
	shipSprite.setTexture(shipTexture);

}

void Player::update()
{
	//TO DO	
}

void Player::draw()
{
	//TO DO
}

//void Player::reset()
//{//TO DO
//}
