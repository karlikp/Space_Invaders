#pragma once

#include "Headers/Entity.h"
#include "Headers/EntityManager.h"
#include "Headers/Enemy1.h"
#include "Headers/Enemy2.h"
#include "Headers/Enemy3.h"

sf::RenderWindow EntityManager::* window;

EntityManager::EntityManager()
{
    window = &(Game::window);
    initEnemies();
}

void EntityManager::initEnemies() {
    float startX = 100.0f;
    float startY = 50.0f;
    float offsetX = 60.0f;
    float offsetY = 60.0f;

    // Tworzenie wierszy przeciwników
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i % 3 == 0) {
                enemies.push_back(Enemy1(startX + j * offsetX, startY + i * offsetY));

            }
            else if (i % 3 == 1) {
                enemies.push_back(Enemy2(startX + j * offsetX, startY + i * offsetY));
            }
            else {
                enemies.push_back(Enemy3(startX + j * offsetX, startY + i * offsetY));
            }

        }
    }
}

void EntityManager::updateEnemies()
{
    for (auto enemy : enemies) {
        enemy.enemySprite.setPosition(enemy.position);
    }
}

void EntityManager::renderEnemies()
{
    for (auto enemy : enemies) {
        (*window).draw(enemy.enemySprite);
    }
}
