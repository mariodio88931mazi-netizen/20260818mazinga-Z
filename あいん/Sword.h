#pragma once

class Enemy;

class Sword
{
private:

    float x, y;
    float angle;

    int attackFrames;

    int oldMouseX;
    int oldMouseY;

    bool firstUpdate;

    int attackPower;

    float swordLength;

    int attackDuration;
public:

    void Initialize();

    void Update(float playerX, float playerY);

    void Draw();

    bool CheckHit(Enemy& enemy);

    bool IsAttacking() const
    {
        return attackFrames > 0;
    }

    void AddAttackPower(int value)
    {
        attackPower += value;
    }

    void AddSwordLength(float value)
    {
        swordLength *= value;
    }

    void AddAttackDuration(int value)
    {
        attackDuration += value;
    }
};