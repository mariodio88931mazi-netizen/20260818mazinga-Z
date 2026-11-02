#include "Sword.h"
#include "Enemy.h"
#include "DxLib.h"

#include <cmath>

void Sword::Initialize()
{
    x = 0;
    y = 0;

    angle = 0;

    attackFrames = 0;

    oldMouseX = 0;
    oldMouseY = 0;

    firstUpdate = true;

    attackPower = 1;

    swordLength = 105.0f;

    attackDuration = 8;
}

void Sword::Update(float playerX, float playerY)
{
    int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);

    x = playerX;
    y = playerY;

    // マウスの方向に剣を向ける
    float dx = mouseX - playerX;
    float dy = mouseY - playerY;

    angle = atan2f(dy, dx);

    // 前回のマウス座標との差
    float moveX = mouseX - oldMouseX;
    float moveY = mouseY - oldMouseY;

    float moveDistance =
        sqrtf(moveX * moveX + moveY * moveY);

    if (!firstUpdate)
    {
        // マウスが一定以上動いたら攻撃
        if (moveDistance >= 5.0f)
        {
            attackFrames = attackDuration;
        }
    }

    if (attackFrames > 0)
    {
        attackFrames--;
    }

    oldMouseX = mouseX;
    oldMouseY = mouseY;

    firstUpdate = false;
}

void Sword::Draw()
{
    // 剣の根元
    float startX = x + cosf(angle) * 15;
    float startY = y + sinf(angle) * 15;

    // 剣の先端
    float endX = x + cosf(angle) * swordLength;
    float endY = y + sinf(angle) * swordLength;

    unsigned int color = GetColor(220, 220, 255);

    if (IsAttacking())
    {
        color = GetColor(255, 150, 50);
    }

    DrawLine(
        (int)startX,
        (int)startY,
        (int)endX,
        (int)endY,
        color,
        8
    );
}

bool Sword::CheckHit(Enemy& enemy)
{
    if (!IsAttacking()) return false;

    if (!enemy.IsAlive()) return false;

    // 剣の根元
    float ax = x + cosf(angle) * 15;
    float ay = y + sinf(angle) * 15;

    // 剣の先端
    float bx = x + cosf(angle) * 105;
    float by = y + sinf(angle) * 105;

    // 敵の座標
    float px = enemy.GetX();
    float py = enemy.GetY();

    float vx = bx - ax;
    float vy = by - ay;

    float lengthSquared = vx * vx + vy * vy;

    // 線分上で最も近い位置を求める
    float t = ((px - ax) * vx + (py - ay) * vy)
        / lengthSquared;

    // 線分の範囲内に制限
    if (t < 0) t = 0;
    if (t > 1) t = 1;

    float closestX = ax + t * vx;
    float closestY = ay + t * vy;

    float dx = px - closestX;
    float dy = py - closestY;

    float distance = sqrtf(dx * dx + dy * dy);

    // 敵と剣が接触したらダメージ
    if (distance <= enemy.GetRadius() + 8)
    {
        enemy.TakeDamage(attackPower);
        return true;
    }

    return false;
}