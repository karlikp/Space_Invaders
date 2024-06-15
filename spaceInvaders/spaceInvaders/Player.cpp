#include "Headers/Player.h"
#include "Headers/Global.h"
#include "Headers/Game.h"



Player::Player(sf::RenderWindow* window)
{
	bulletTexture.loadFromFile("Resources/playerBullet1.png");
	shipTexture.loadFromFile("Resources/playerShip1_blue.png");

	bulletSprite.setTexture(bulletTexture);
	shipSprite.setTexture(shipTexture);

	
}

Player::Player(float x, float y, float scale) : Entity(x, y) {

	entityBulletTexture.loadFromFile("Resources/playerBullet1.png");
	entityTexture.loadFromFile("Resources/playerShip1_blue.png");

	entityBulletSprite.setTexture(entityBulletTexture);
	entitySprite.setTexture(entityTexture);
	entitySprite.setScale(scale, scale);
}

void Player::update()
{
	float screenHeight = Game::screenHeight;
	float screenWidth = Game::screenWidth;

	if (not isDead) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			position.x = std::max<int>(position.x - PLAYER_MOVE_SPEED, GAP * screenHeight);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			position.x = std::min<int>(position.x + PLAYER_MOVE_SPEED, (screenWidth - (GAP * screenHeight)));
		}
	}

	this->entitySprite.setPosition(this->position);
}

void Player::draw()
{
	//TO DO
}

//void Player::reset()
//{//TO DO
//}
