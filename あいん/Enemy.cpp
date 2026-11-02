#include "Enemy.h"
#include "DxLib.h"

#include <cmath>

void Enemy::Initialize(
    float startX,
    float startY,
    float moveSpeed)
{
    x = startX;
    y = startY;

    speed = moveSpeed;

    radius = 18;

    hp = 1;

    alive = true;
}

void Enemy::Update(float playerX, float playerY)
{
    if (!alive) return;

    float dx = playerX - x;
    float dy = playerY - y;

    float distance = sqrtf(dx * dx + dy * dy);

    if (distance > 0)
    {
        dx /= distance;
        dy /= distance;

        x += dx * speed;
        y += dy * speed;
    }
}

void Enemy::Draw()
{
    if (!alive) return;

    DrawCircle(
        (int)x,
        (int)y,
        (int)radius,
        GetColor(220, 50, 50),
        TRUE
    );
}

void Enemy::TakeDamage(int damage)
{
    if (!alive) return;

    hp -= damage;

    if (hp <= 0)
    {
        alive = false;
    }
}