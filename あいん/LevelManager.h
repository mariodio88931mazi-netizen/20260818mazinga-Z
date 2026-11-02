#pragma once

class LevelManager
{
private:

    int level;
    int currentExp;
    int nextExp;

    bool levelUp;
public:

    void Initialize();

    void AddExp(int value);

    void Draw();

    bool IsLevelUp();

    int GetLevel() const
    {
        return level;
    }

    int GetCurrentExp() const
    {
        return currentExp;
    }

    int GetNextExp() const
    {
        return nextExp;
    }
};
