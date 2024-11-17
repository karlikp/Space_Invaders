#pragma once


#include <vector>
#include <chrono>
#include <random>
#include <iostream>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Global.h"
 
class Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f screenSize;
	float stepX;
	float stepY;
	float scale;
	int ratio;
	bool isDead;

	std::bernoulli_distribution possibility;

	sf::Sprite entityBulletSprite;
	
	sf::Texture entityBulletTexture;
	sf::Texture entityTexture;

public:
	
	sf::Sprite entitySprite;

	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, float iRatio);
	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, sf::Sprite iBulletSprite, float iRatio);
	Entity(float iPosX, float iPosY, float iStepY, sf::Sprite iBulletSprite, sf::Vector2f iScreenSize);
	virtual ~Entity() = default;
	virtual void update() = 0;

	//Getters
	sf::Vector2f getPosition();
	sf::Vector2f getScreenSize();
	float getX();
	float getY();
	float getStepX();
	float getStepY();
	float getScale();
	bool getIsDead();
	sf::Sprite* getEntitySprite();
	sf::Sprite getEntityBulletSprite();
	std::bernoulli_distribution getPossibility();

	

	//Setters
	void setX(float iPosX);
	void setY(float iPosX);
	void setIsDead(bool newStatus);
	void setEntitySprite(std::string imageSource);
	void setEntityBulletSprite(std::string imageSource);
	void setEntityScale(float scale);
	void setEntityPosition();
	void setBulletPosition();
	void setPossibility(float possibility);

	friend class EntityManager;
};

struct Bullet : public Entity
{
	Bullet(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, sf::Sprite iEntityBulletSprite, float iRatio) 
		: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize, iEntityBulletSprite, iRatio) {

		float scale = (BULLET_RATIO * getScreenSize().y) / BULLET_DEFAULT_HEIGHT;
		setEntityScale(scale);
	}

	~Bullet() = default;

	void update() override {

		if (getIsDead() == false) {

			setY(getY() - getStepY());
			setX(getX() - getStepX());

			if (getX() <= 0 || getY() <= 0 ||
				getX() >= getScreenSize().x || getY() >= getScreenSize().y) {

				setIsDead(true);
			}
		}

		setBulletPosition();
	};

	sf::IntRect getHitbox() {
		return sf::IntRect(
			getX() + SMALL_HITBOX_MARGIN_RATIO,
			getY() + SMALL_HITBOX_MARGIN_RATIO,
			(BULLET_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
			(BULLET_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y);
	}

};

struct Powerup : public Entity
{
	short powerupType;

	int generatorType() {

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 3);

		return dis(gen);
	}

	Powerup(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, float iRatio) :
		Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize, iRatio) {

		powerupType = generatorType();
		float scale = POWERUP_RATIO * iScreenSize.y / POWERUP_DEFAULT_HEIGHT;

		setEntitySprite("../resources/textures/powerup.png");
		setEntityScale(scale);
	}
	~Powerup() = default;

	void update() override {

		if (getIsDead() == false) {

			setY(getY() - getStepY());
			setX(getX() - getStepX());

			if (getX() <= 0 || getY() <= 0 ||
				getX() >= getScreenSize().x || getY() >= getScreenSize().y) {

				setIsDead(true);
			}
		}

		setEntityPosition();
	}

	

	sf::IntRect getHitbox() {
		return sf::IntRect(
			getX() + SMALL_HITBOX_MARGIN_RATIO,
			getY() + SMALL_HITBOX_MARGIN_RATIO,
			(POWERUP_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
			(POWERUP_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y);
	}
};





