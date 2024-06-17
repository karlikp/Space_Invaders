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

void EntityManager::updateEnemies()
{
    //set position
    for (const auto& enemy : enemies) {
        enemy->update();
    }
}

void EntityManager::updateEntities()
{
    //set position
    for (const auto& entity : entities) {
        entity->update();
    }
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

//Unique pointer have to assign by reference
std::vector<std::unique_ptr<Bullet>>& EntityManager::getEnemyBullets()
{
    return enemyBullets;
}

std::vector<std::unique_ptr<Powerup>>& EntityManager::getPowerups()
{
    return powerups;
}
