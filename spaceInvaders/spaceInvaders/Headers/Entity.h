#pragma once


#include <vector>
#include <chrono>
#include <random>

#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Global.h"
 
class Entity
{
	//encapsulation

	sf::Vector2f position;
	sf::Vector2f screenSize;
	float stepX;
	float stepY;
	float scale;
	int ratio;
	bool isDead;

	//std::random_device rd;
	//std::mt19937_64* randomEnginePtr;
	//std::bernoulli_distribution shootPossibility;

	sf::Sprite entityBulletSprite;
	sf::Sprite entitySprite;
	sf::Texture entityBulletTexture;
	sf::Texture entityTexture;

public:
	
	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize);
	//Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, std::unique_ptr<Entity> ufo);
	Entity(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize, sf::Sprite iBulletSprite, float iRatio);
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
	bool getIsDead();
	sf::Sprite getEntitySprite();
	sf::Sprite getEntityBulletSprite();
	//std::bernoulli_distribution getShootPossibility();
	//std::mt19937_64* getRandomEnginePtr();

	//Setters
	void setX(float iPosX);
	void setY(float iPosX);
	void setIsDead(bool newStatus);
	void setEntitySprite(std::string imageSource);
	void setEntityBulletSprite(std::string imageSource);
	void setEntityScale(float scale);
	void setEntityPosition();
	void setBulletPosition();
	//void setShootPossibility(float possibility);

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
			std::cout << getY() << "Y\n";
			std::cout << getX() << "X\n";


			if (getX() <= 0 || getY() <= 0 ||
				getX() >= getScreenSize().x || getY() >= getScreenSize().y) {

				setIsDead(true);
			}
		}

		setBulletPosition();
	};

	void draw() override {
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
	Powerup(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize) : Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

		float scale = POWERUP_RATIO * iScreenSize.y / OBSTACLE_DEFAULT_WIDTH;

		setEntitySprite("Resources/powerup.png");
		setEntityScale(scale);
	}
	~Powerup() = default;

	void update() {};

	void draw() {};

	int randomPowerup() {

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 3);

		return dis(gen);
	}

	sf::IntRect getHitbox() {
		return sf::IntRect(
			getX() + SMALL_HITBOX_MARGIN_RATIO,
			getY() + SMALL_HITBOX_MARGIN_RATIO,
			(POWERUP_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y,
			(POWERUP_RATIO - 2 * SMALL_HITBOX_MARGIN_RATIO) * getScreenSize().y);
	}
};





