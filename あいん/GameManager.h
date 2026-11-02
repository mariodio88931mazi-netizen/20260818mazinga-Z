#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Experience.h"
#include "LevelManager.h"
#include "UpgradeManager.h"

#include <vector>

class GameManager
{
private:

    Player player;

    std::vector<Enemy> enemies;
    std::vector<Experience> experiences;

    LevelManager levelManager;
    UpgradeManager upgradeManager;

    int spawnFrame;

    void SpawnEnemy();

    bool gameOver;

public:

    void Initialize();
    void Update();
    void Draw();
};