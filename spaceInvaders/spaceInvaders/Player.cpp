#include "Headers/Player.h"

Player::Player()
{
	reset();

	bullet_texture.loadFromFile("Resources/Images/PlayerBullet.png");
	ship_texture.loadFromFile("Resources/Images/Player.png");

	bullet_sprite.setTexture(bullet_texture);
	ship_sprite.setTexture(texture);
}

void Player::reset()
{
}
