#include "Headers/Player.h"
#include "Headers/Global.h"
#include "Headers/Game.h"


Player::Player(float iPosX, float iPosY, float iStepX, float iStepY, sf::Vector2f iScreenSize)
	: Entity(iPosX, iPosY, iStepX, iStepY, iScreenSize) {

	float scale = (0.075 * iScreenSize.y) / PLAYER_DEFAULT_HEIGHT;

	setEntitySprite("Resources/playerShip1_blue.png");
	setEntityBulletSprite("Resources/playerBullet1.png");
	setEntityScale(scale);

	currentDamage = 1;
	reloadTimer = RELOAD_TIME;
	activePower = NORMAL_STATE;
	powerupTimer = 0;
}

void Player::update()
{
	if (getLive() == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setX(std::max<int>(getX() - getStepX(), GAP_RATIO * getScreenSize().y/*screenHeight*/));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			setX(std::min<int>(getX() + getStepX(), (getScreenSize().x - ((0.075 + GAP_RATIO) * getScreenSize().y))));
		}
	}

	if (reloadTimer == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (activePower == FASTER_RELOAD)
			{
				reloadTimer = FAST_RELOAD_TIME;
			}
			else
			{
				reloadTimer = RELOAD_TIME;
			}
			

			EntityManager::addPlayerBullet
			(std::make_unique<Bullet>(getX(), getY(), BULLET_SPEED_Y, getEntityBulletSprite(), getScreenSize()));

			float bulletScale = (BULLET_RATIO * getScreenSize().y) / BULLET_DEFAULT_HEIGHT;

			if (activePower = TRIPLE_SHOOT)
			{
				EntityManager::addPlayerBullet
				(std::make_unique<Bullet>(getX() - bulletScale, getY(), BULLET_SPEED_Y, getEntityBulletSprite(), getScreenSize()));
				EntityManager::addPlayerBullet
				(std::make_unique<Bullet>(getX() + bulletScale, getY(), BULLET_SPEED_Y, getEntityBulletSprite(), getScreenSize()));
			}
		}
	}
	else
	{
		reloadTimer--;
	}
	//Check enemy hit
	//auto enemyBullets = EntityManager::getEnemyBullets();

	/*for (const auto& enemyBullet : enemyBullets)
	{
		if (1 == get_hitbox().intersects(enemy_bullet.get_hitbox()))
		{
			if (1 == current_power)
			{
				current_power = 0;

				shield_animation_over = 0;
			}
			else
			{
				dead = 1;
			}

			enemy_bullet.dead = 1;

			break;
		}
	}*/

	setEntityPosition();
}

void Player::draw()
{
	//TO DO
}

sf::IntRect Player::getHitbox()
{
	return sf::IntRect(
		getX(), getY(), 
		(PLAYER_SIZE_RATIO - HITBOX_MARGIN_RATIO) * getScreenSize().y,
		(PLAYER_SIZE_RATIO - HITBOX_MARGIN_RATIO) * getScreenSize().y);
}

//void Player::reset()
//{//TO DO
//}
