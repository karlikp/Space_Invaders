#pragma once

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

void EntityManager::initEnemies() {
    float startX = 100.0f;
    float startY = 50.0f;
    float offsetX = 60.0f;
    float offsetY = 60.0f;

    // Tworzenie wierszy przeciwników
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i % 3 == 0) {
                //addEnemy(std::make_shared<Enemy1>(startX + j * offsetX, startY + i * offsetY));
                auto enemy = new Enemy1();
                enemies.push_front(enemy);

            }
            else if (i % 3 == 1) {
                enemies.push_front(new Enemy2(startX + j * offsetX, startY + i * offsetY));
            }
            else {
                enemies.push_front(new Enemy3(startX + j * offsetX, startY + i * offsetY));
            }

        }
    }
}

void EntityManager::initPlayer()
{

    entities.push_back(std::make_shared<Player>(window));
}

void EntityManager::initObstacle()
{
 
    float tempWidth = widthWindow;
    float distFromBottom = highWindow - 0.1 * highWindow;
    float offsetX = 0.075 * highWindow;
    float obstacleWidth = 0.15 * highWindow;
    int obstacleCounter = 0;    //How many obstacles is possible

    //scaling
    float scale = obstacleWidth / 300;

    
    if (tempWidth >= 0.3 * highWindow) { //first obstacle is possible
        
        do {
            obstacleCounter++;
            tempWidth -= 0.225 * highWindow;

        } while (tempWidth >= 0.225 * highWindow);
    }

    while (obstacleCounter > 1) {
        //left obstacle
        entities.push_back(std::make_shared<Obstacle>(offsetX, distFromBottom, scale));
        //right obstacle
        entities.push_back(std::make_shared<Obstacle>(widthWindow - offsetX, distFromBottom, scale));
        obstacleCounter -= 2;
    };

    if (obstacleCounter == 1) {
        entities.push_back(std::make_shared<Obstacle>((widthWindow + obstacleWidth) / 2, distFromBottom, scale));
    }  
}

void EntityManager::initUFO()
{
    entities.push_back(std::make_shared<UFO>(widthWindow, 0.1*highWindow));
}



void EntityManager::updateEnemies()
{
    for (const auto& enemy : enemies) {
        enemy->entitySprite.setPosition(enemy->position);
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
    for (auto entity : entities) {
        (*window).draw(entity->entitySprite);
    }
}
