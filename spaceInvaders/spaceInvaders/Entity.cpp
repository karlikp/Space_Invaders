#include "Headers/Entity.h"

Entity::Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize) :
	position(iPosX, iPosY),
	stepX(iStepX),
	stepY(iStepY),
	screenSize(iScreenSize)
{
	live = true;
}

Entity::Entity(float iPosX, float iPosY, float iStepY, sf::Sprite iBulletSprite, sf::Vector2f iScreenSize) :
	position(iPosX, iPosY),
	stepY(iStepY),
	entityBulletSprite(iBulletSprite),
	screenSize(iScreenSize)
{
	live = true;
}

sf::Vector2f Entity::getScreenSize()
{
	return screenSize;
}

sf::Vector2f Entity::getPosition(){
	return position;
}

float Entity::getX() {
	return position.x;
}

float Entity::getY() {
	return position.y;
}

float Entity::getStepX(){
	return stepX;
}

float Entity::getStepY(){
	return stepY;
}

bool Entity::getLive() {
	return live;
}

sf::Sprite Entity::getEntitySprite() {
	return entitySprite;
}

sf::Sprite Entity::getEntityBulletSprite() {
	return entityBulletSprite;
}

void Entity::setX(float iPosX) {
	position.x = iPosX;
}

void Entity::setY(float iPosY) {
	position.y = iPosY;
}

void Entity::setLive(bool status) {
	live = status;
}

void Entity::setEntitySprite(std::string imageSource) {
	
	entityTexture.loadFromFile(imageSource);
	entitySprite.setTexture(entityTexture);
}

void Entity::setEntityBulletSprite(std::string imageSource) {

	entityBulletTexture.loadFromFile(imageSource);
	entityBulletSprite.setTexture(entityTexture);
}

void Entity::setEntityScale(float scale) {
	entitySprite.setScale(scale, scale);
}

void Entity::setEntityPosition() {
	entitySprite.setPosition(position);
}
