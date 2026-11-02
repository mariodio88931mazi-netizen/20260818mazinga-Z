#pragma once

#include "Sword.h"

class Player
{
private:

    float x;
    float y;

    float speed;

    int hp;

    Sword sword;

public:

    void Initialize(float startX, float startY);

    void Update();

    void Draw();

    float GetX() const
    {
        return x;
    }

    float GetY() const
    {
        return y;
    }

    Sword& GetSword()
    {
        return sword;
    }

    void TakeDamage(int damage);
    bool IsDead() const;
};