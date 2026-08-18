#include "DxLib.h"
#include <vector>

// ブロック
struct Block
{
    int x;
    int y;
    bool alive;
};

// プレイヤー
struct Player
{
    int x;
    int y;
    int width;
    int height;
};

// ボール
struct Ball
{
    float x;
    float y;
    float vx;
    float vy;
    int radius;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモード
    ChangeWindowMode(TRUE);

    // DXライブラリ初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 裏画面を描画先にする
    SetDrawScreen(DX_SCREEN_BACK);

    // -------------------------
    // プレイヤー
    // -------------------------
    Player player;

    player.x = 300;
    player.y = 550;
    player.width = 100;
    player.height = 20;

    // -------------------------
    // ボール
    // -------------------------
    Ball ball;

    ball.x = 350;
    ball.y = 500;
    ball.vx = 4.0f;
    ball.vy = -4.0f;
    ball.radius = 10;

    // -------------------------
    // ブロック
    // -------------------------
    std::vector<Block> blocks;

    const int rows = 5;
    const int columns = 8;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            Block block;

            block.x = 60 + x * 80;
            block.y = 80 + y * 30;
            block.alive = true;

            blocks.push_back(block);
        }
    }

    // ゲームループ
    while (ProcessMessage() == 0)
    {
        // -------------------------
        // 画面クリア
        // -------------------------
        ClearDrawScreen();

        // =========================
        // 入力
        // =========================

        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            player.x -= 6;
        }

        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            player.x += 6;
        }

        // 画面外に出ないようにする
        if (player.x < 0)
        {
            player.x = 0;
        }

        if (player.x + player.width > 640)
        {
            player.x = 640 - player.width;
        }

        // =========================
        // ボール移動
        // =========================

        ball.x += ball.vx;
        ball.y += ball.vy;

        // 左右の壁
        if (ball.x - ball.radius < 0 ||
            ball.x + ball.radius > 640)
        {
            ball.vx *= -1;
        }

        // 上の壁
        if (ball.y - ball.radius < 0)
        {
            ball.vy *= -1;
        }

        // =========================
        // プレイヤーとの衝突
        // =========================

        if (ball.x + ball.radius >= player.x &&
            ball.x - ball.radius <= player.x + player.width &&
            ball.y + ball.radius >= player.y &&
            ball.y - ball.radius <= player.y + player.height)
        {
            ball.vy *= -1;

            // プレイヤーにめり込まないようにする
            ball.y = player.y - ball.radius;
        }

        // =========================
        // ブロックとの衝突
        // =========================

        for (auto& block : blocks)
        {
            if (!block.alive)
            {
                continue;
            }

            const int blockWidth = 70;
            const int blockHeight = 20;

            if (ball.x + ball.radius >= block.x &&
                ball.x - ball.radius <= block.x + blockWidth &&
                ball.y + ball.radius >= block.y &&
                ball.y - ball.radius <= block.y + blockHeight)
            {
                // ブロックを消す
                block.alive = false;

                // ボールを反射
                ball.vy *= -1;

                break;
            }
        }

        // =========================
        // ボールが下に落ちた
        // =========================

        if (ball.y > 600)
        {
            // ボールを初期位置に戻す
            ball.x = 350;
            ball.y = 500;

            ball.vx = 4.0f;
            ball.vy = -4.0f;
        }

        // =========================
        // 描画
        // =========================

        // プレイヤー
        DrawBox(
            player.x,
            player.y,
            player.x + player.width,
            player.y + player.height,
            GetColor(255, 255, 255),
            TRUE
        );

        // ボール
        DrawCircle(
            (int)ball.x,
            (int)ball.y,
            ball.radius,
            GetColor(255, 255, 255),
            TRUE
        );

        // ブロック
        for (const auto& block : blocks)
        {
            if (!block.alive)
            {
                continue;
            }

            DrawBox(
                block.x,
                block.y,
                block.x + 70,
                block.y + 20,
                GetColor(255, 100, 100),
                TRUE
            );
        }

        // 画面更新
        ScreenFlip();
    }

    // DXライブラリ終了
    DxLib_End();

    return 0;
}