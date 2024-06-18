#pragma once

#include <iostream>
#include <vector>
#include <memory>

//#include "Headers/Entity.h"
#include "Headers/EntityManager.h"
//#include "Headers/Enemy.h"
#include "Headers/Enemy1.h"
#include "Headers/Enemy2.h"
#include "Headers/Enemy3.h"
#include "Headers/Player.h"
#include "Headers/Obstacle.h"
#include "Headers/UFO.h"
#include "Headers/Global.h"



sf::RenderWindow* EntityManager::window = nullptr;
std::vector<std::unique_ptr<Entity>> EntityManager::entities;
std::vector<std::unique_ptr<Enemy>> EntityManager::enemies;
std::vector<std::unique_ptr<Bullet>> EntityManager::enemyBullets;
std::vector<std::unique_ptr<Bullet>> EntityManager::playerBullets;
std::vector<std::unique_ptr<Powerup>> EntityManager::powerups;

EntityManager::EntityManager(sf::RenderWindow* windowI)
{
    window = windowI;
    

}

void EntityManager::addEnemy(std::unique_ptr<Enemy> enemy)
{
    enemies.push_back(std::move(enemy));
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity)
{
    entities.push_back(std::move(entity));
}

void EntityManager::addPlayerBullet(std::unique_ptr<Bullet> bullet)
{
    playerBullets.push_back(std::move(bullet));
}

void EntityManager::addEnemyBullet(std::unique_ptr<Bullet> bullet)
{
    enemyBullets.push_back(std::move(bullet));
}

void EntityManager::addPowerup(std::unique_ptr<Powerup> powerup)
{
    powerups.push_back(std::move(powerup));
}

void EntityManager::updateEnemies()
{
    //set position
    for (const auto& enemy : enemies) {
        enemy->update();
    }

    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [](const std::unique_ptr<Enemy>& enemy) {
                return enemy->getIsDead();
            }),
        enemies.end());
}

void EntityManager::updateEntities()
{
    //set position
    for (const auto& entity : entities) {
        entity->update();
    }
}

void EntityManager::updatePlayerBullets()
{
    for (const auto& bullet : playerBullets) {
        bullet->update();
    }

    playerBullets.erase(
        std::remove_if(playerBullets.begin(), playerBullets.end(),
            [](const std::unique_ptr<Bullet>& bullet) {
                return bullet->getIsDead();
            }),
        playerBullets.end());
}

void EntityManager::drawEnemies()
{
    for (const auto& enemy : enemies) {
        (*window).draw(enemy->entitySprite);
    }
}

void EntityManager::drawEntities()
{
    for (const auto& entity : entities) {
        (*window).draw(entity->entitySprite);
    }
}

void EntityManager::drawPlayerBullets()
{
    for (const auto& bullet : playerBullets) {
        (*window).draw(bullet->entityBulletSprite);
    }
}

std::vector<std::unique_ptr<Enemy>>& EntityManager::getEnemies()
{
    return enemies;
}

//Unique pointer have to assign by reference
std::vector<std::unique_ptr<Bullet>>& EntityManager::getEnemyBullets()
{
    return enemyBullets;
}

std::vector<std::unique_ptr<Bullet>>& EntityManager::getPlayerBullets()
{
    return playerBullets;
}

std::vector<std::unique_ptr<Powerup>>& EntityManager::getPowerups()
{
    return powerups;
}

sf::RenderWindow* EntityManager::getWindow()
{
    return window;
}
