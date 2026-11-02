#include "GameManager.h"
#include "DxLib.h"
#include "UpgradeManager.h"

#include <cstdlib>
#include <algorithm>
#include <cmath>

void GameManager::Initialize()
{
    player.Initialize(640, 360);

    enemies.clear();

    levelManager.Initialize();

    upgradeManager.Initialize();

    experiences.clear();

    spawnFrame = 0;

    gameOver = false;
}

void GameManager::Update()
{
    player.Update();

    spawnFrame++;

    if (spawnFrame >= 90 && enemies.size() < 30)
    {
        SpawnEnemy();

        spawnFrame = 0;
    }

    for (Enemy& enemy : enemies)
    {
        enemy.Update(player.GetX(), player.GetY());

        // 敵とプレイヤーの距離を計算
        float dx = enemy.GetX() - player.GetX();
        float dy = enemy.GetY() - player.GetY();

        float distance = sqrtf(dx * dx + dy * dy);

        // 接触判定
        float hitDistance = enemy.GetRadius() + 15;

        if (distance < hitDistance)
        {
            player.TakeDamage(1);
        }

        bool wasAlive = enemy.IsAlive();

        player.GetSword().CheckHit(enemy);

        if (wasAlive && !enemy.IsAlive())
        {
            Experience exp;
            exp.Initialize(enemy.GetX(), enemy.GetY(), 5);
            experiences.push_back(exp);
        }
    }

            experiences.push_back(exp);
        }
    }

    // 経験値の回収
    for (Experience& exp : experiences)
    {
        if (exp.CheckCollect(player.GetX(), player.GetY()))
        {
            levelManager.AddExp(exp.GetValue());

            // レベルアップしたら強化画面を開始
            if (levelManager.IsLevelUp())
            {
                upgradeManager.StartSelection();
            }
        }
    }

    // 回収済み経験値を削除
    experiences.erase(
        std::remove_if(
            experiences.begin(),
            experiences.end(),
            [](const Experience& exp)
            {
                return !exp.IsAlive();
            }
        ),
        experiences.end()
    );

    // 倒された敵を削除
    enemies.erase(
        std::remove_if(
            enemies.begin(),
            enemies.end(),
            [](const Enemy& enemy)
            {
                return !enemy.IsAlive();
            }
        ),
        enemies.end()
    );

    // 強化画面が表示されている場合
    if (upgradeManager.IsSelecting())
    {
        upgradeManager.Update(player.GetSword());

        return;
    }
}

void GameManager::Draw()
{
    // 敵を描画
    for (Enemy& enemy : enemies)
    {
        enemy.Draw();
    }

    // 主人公を描画
    player.Draw();

    // 操作説明
    DrawString(
        20, 20,
        "WASD : MOVE / MOUSE : SLASH",
        GetColor(255, 255, 255)
    );

    DrawFormatString(
        20, 45,
        GetColor(255, 255, 255),
        "ENEMIES : %d",
        (int)enemies.size()
    );

    // 経験値を描画
    for (Experience& exp : experiences)
    {
        exp.Draw();
    }

    // レベル・経験値を表示
    levelManager.Draw();

    upgradeManager.Draw();
}

void GameManager::SpawnEnemy()
{
    float x, y;

    // 4方向の画面外から敵を生成
    int side = rand() % 4;

    switch (side)
    {
    case 0:
        x = rand() % 1280;
        y = -20;
        break;

    case 1:
        x = 1300;
        y = rand() % 720;
        break;

    case 2:
        x = rand() % 1280;
        y = 740;
        break;

    default:
        x = -20;
        y = rand() % 720;
        break;
    }

    Enemy enemy;

    enemy.Initialize(x, y, 1.5f);

    enemies.push_back(enemy);
}