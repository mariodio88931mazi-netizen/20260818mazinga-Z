#include "Experience.h"
#include "DxLib.h"

#include <cmath>

void Experience::Initialize(
    float startX,
    float startY,
    int expValue)
{
    x = startX;
    y = startY;

    value = expValue;

    alive = true;
}

void Experience::Draw()
{
    if (!alive) return;

    DrawCircle(
        (int)x,
        (int)y,
        7,
        GetColor(50, 255, 100),
        TRUE
    );
}

bool Experience::CheckCollect(float playerX, float playerY)
{
    if (!alive) return false;

    float dx = playerX - x;
    float dy = playerY - y;

    float distance = sqrtf(dx * dx + dy * dy);

    if (distance <= 25)
    {
        alive = false;
        return true;
    }

    return false;
}