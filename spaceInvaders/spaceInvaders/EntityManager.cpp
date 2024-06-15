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


sf::RenderWindow* EntityManager::window = nullptr;

EntityManager::EntityManager(sf::RenderWindow* windowI)
{
    window = windowI;
    widthWindow = (*window).getSize().x;
    highWindow = (*window).getSize().y;

}

//void EntityManager::addEnemy(std::shared_ptr<Enemy> enemy)
//{
//    enemies.push_back(enemy);
//}

void EntityManager::addEnemy(std::unique_ptr<Enemy> enemy)
{
    enemies.push_back(std::move(enemy));
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity)
{
    entities.push_back(std::move(entity));
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
