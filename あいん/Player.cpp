#include "Player.h"
#include "DxLib.h"

#include <cmath>

void Player::Initialize(float startX, float startY)
{
    x = startX;
    y = startY;

    speed = 5.0f;

    hp = 100;

    sword.Initialize();
}

void Player::Update()
{
    float moveX = 0;
    float moveY = 0;

    // WASD移動
    if (CheckHitKey(KEY_INPUT_W)) moveY -= 1;
    if (CheckHitKey(KEY_INPUT_S)) moveY += 1;
    if (CheckHitKey(KEY_INPUT_A)) moveX -= 1;
    if (CheckHitKey(KEY_INPUT_D)) moveX += 1;

    // 斜め移動の速度調整
    float length = sqrtf(moveX * moveX + moveY * moveY);

    if (length > 0)
    {
        moveX /= length;
        moveY /= length;
    }

    x += moveX * speed;
    y += moveY * speed;

    // 画面外に出ないようにする
    if (x < 15) x = 15;
    if (x > 1265) x = 1265;

    if (y < 15) y = 15;
    if (y > 705) y = 705;

    // 剣の更新
    sword.Update(x, y);
}

void Player::Draw()
{
    // 主人公
    DrawCircle(
        (int)x,
        (int)y,
        15,
        GetColor(50, 150, 255),
        TRUE
    );

    // 剣
    sword.Draw();
}

void Player::TakeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}

bool Player::IsDead() const
{
    return hp <= 0;
}