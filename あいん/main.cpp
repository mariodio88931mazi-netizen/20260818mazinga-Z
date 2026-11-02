#include "DxLib.h"

#include "GameManager.h"

#include <ctime>
#include <cstdlib>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    ChangeWindowMode(TRUE);

    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    SetMainWindowText("Sword Survival");

    srand((unsigned int)time(nullptr));

    GameManager game;

    game.Initialize();

    // ÉQÅ[ÉÄÉãÅ[Év
    while (
        ProcessMessage() == 0 &&
        CheckHitKey(KEY_INPUT_ESCAPE) == 0
        )
    {
        game.Update();

        ClearDrawScreen();

        game.Draw();

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}