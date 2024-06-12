#pragma once

#include "Headers/EntityManager.h"
#include "Headers/Enemy1.h"
#include "Headers/Enemy2.h"
#include "Headers/Enemy3.h"


EntityManager::EntityManager()
{
    initEnemies();
}

void EntityManager::initEnemies() {
    short startX = 100;
    short startY = 50;
    short offsetX = 60;
    short offsetY = 60;

    // Tworzenie wierszy przeciwników
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i % 3 == 0) {
                enemies.push_back(std::make_unique<Enemy1>(startX + j * offsetX, startY + i * offsetY));
            }
            else if (i % 3 == 1) {
                enemies.push_back(std::make_unique<Enemy2>(startX + j * offsetX, startY + i * offsetY));
            }
            else {
                enemies.push_back(std::make_unique<Enemy3>(startX + j * offsetX, startY + i * offsetY));
            }
        }
    }
}