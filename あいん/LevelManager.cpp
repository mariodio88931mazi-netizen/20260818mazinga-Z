#include "LevelManager.h"
#include "DxLib.h"

void LevelManager::Initialize()
{
    level = 1;
    currentExp = 0;
    nextExp = 10;
    levelUp = false;
}

void LevelManager::AddExp(int value)
{
    currentExp += value;

    levelUp = false;

    // 必要経験値に達したらレベルアップ
    while (currentExp >= nextExp)
    {
        currentExp -= nextExp;

        level++;

        // 次のレベルに必要な経験値
        nextExp += 5;

        levelUp = true;
    }
}

bool LevelManager::IsLevelUp()
{
    if (levelUp)
    {
        levelUp = false;
        return true;
    }

    return false;
}

void LevelManager::Draw()
{
    DrawFormatString(
        20, 80,
        GetColor(255, 255, 255),
        "LEVEL : %d",
        level
    );

    DrawFormatString(
        20, 105,
        GetColor(50, 255, 100),
        "EXP : %d / %d",
        currentExp,
        nextExp
    );
}