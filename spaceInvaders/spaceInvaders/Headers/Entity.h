#pragma once

//#include "Game.h"

#include <vector>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Entity
{
	//encapsulation

	sf::Vector2f position;
	sf::Vector2f screenSize;
	float stepX;
	float stepY;
	float scale;
	bool live;

	sf::Sprite entityBulletSprite;
	sf::Sprite entitySprite;
	sf::Texture entityBulletTexture;
	sf::Texture entityTexture;

public:
	
	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	Entity(float iPosX, float iPosY, float iStepY, sf::Sprite iBulletSprite, sf::Vector2f iScreenSize);
	virtual ~Entity() = default;

	virtual void update() = 0;
	virtual void draw() = 0;

	//Getters
	sf::Vector2f getPosition();
	sf::Vector2f getScreenSize();
	float getX();
	float getY();
	float getStepX();
	float getStepY();
	float getScale();
	bool getLive();
	sf::Sprite getEntitySprite();
	sf::Sprite getEntityBulletSprite();

	//Setters
	void setX(float iPosX);
	void setY(float iPosX);
	void setLive(bool newStatus);
	void setEntitySprite(std::string imageSource);
	void setEntityBulletSprite(std::string imageSource);
	void setEntityScale(float scale);
	void setEntityPosition();

	friend class EntityManager;
};





