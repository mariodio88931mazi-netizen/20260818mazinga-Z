#pragma once

class Enemy
{
private:

    float x;
    float y;

    float speed;

    float radius;

    int hp;

    bool alive;

public:

    void Initialize(float startX, float startY, float moveSpeed);

    void Update(float playerX, float playerY);

    void Draw();

    void TakeDamage(int damage);

    bool IsAlive() const
    {
        return alive;
    }

    float GetX() const
    {
        return x;
    }

    float GetY() const
    {
        return y;
    }

    float GetRadius() const
    {
        return radius;
    }
};