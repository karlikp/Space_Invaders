#pragma once

#include "Headers/EnemyManager.h"

EnemyManager::EnemyManager()
{
    initEnemies();
}

void EnemyManager::initEnemies() {
    float startX = 100.f;
    float startY = 50.f;
    float offsetX = 60.f;
    float offsetY = 60.f;

    // Tworzenie wierszy przeciwników
    /*for (int i = 0; i < 5; ++i) {
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
    }*/
}