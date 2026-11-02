#pragma once

class Experience
{
private:

    float x;
    float y;

    int value;

    bool alive;

public:

    void Initialize(float startX, float startY, int expValue);

    void Draw();

    bool CheckCollect(float playerX, float playerY);

    bool IsAlive() const
    {
        return alive;
    }

    int GetValue() const
    {
        return value;
    }
};