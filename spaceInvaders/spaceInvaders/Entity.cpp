#include "Headers/Entity.h"
#include "Headers/Global.h"

Entity::Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize) :
	position(iPosX, iPosY),
	stepX(iStepX),
	stepY(iStepY),
	screenSize(iScreenSize)
{
	isDead = false;
}

Entity::Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, sf::Sprite iBulletSprite, float iRatio) :
	position(0, iPosY),
	stepX(iStepX),
	stepY(iStepY),
	screenSize(iScreenSize),
	entityBulletSprite(iBulletSprite),
	ratio(iRatio)
{
	position.x = iPosX + ((iRatio - (BULLET_RATIO/2) ) * iScreenSize.y) / 2;
	isDead = false;

}

Entity::Entity(float iPosX, float iPosY, float iStepY, sf::Sprite iBulletSprite, sf::Vector2f iScreenSize) :
	position(iPosX, iPosY),
	stepY(iStepY),
	entityBulletSprite(iBulletSprite),
	screenSize(iScreenSize)
{
	isDead = false;
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

bool Entity::getIsDead() {
	return isDead;
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

void Entity::setIsDead(bool status) {
	isDead = status;
}

void Entity::setEntitySprite(std::string imageSource) {
	
	entityTexture.loadFromFile(imageSource);
	entitySprite.setTexture(entityTexture);
}

void Entity::setEntityBulletSprite(std::string imageSource) {

	entityBulletTexture.loadFromFile(imageSource);
	entityBulletSprite.setTexture(entityBulletTexture);
}

void Entity::setEntityScale(float scale) {
	entitySprite.setScale(scale, scale);
}

std::bernoulli_distribution Entity::getShootPossibility()
{
	return shootPossibility;
}

void Entity::setEntityPosition() {
	entitySprite.setPosition(position);
}

void Entity::setBulletPosition()
{
	entityBulletSprite.setPosition(position);
}

void Entity::setShootPossibility(float possibility)
{
	shootPossibility = std::bernoulli_distribution(possibility);
}
