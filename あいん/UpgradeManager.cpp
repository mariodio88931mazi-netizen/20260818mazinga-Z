#include "UpgradeManager.h"
#include "DxLib.h"

#include <cstdlib>

void UpgradeManager::Initialize()
{
    isSelecting = false;
}

void UpgradeManager::StartSelection()
{
    isSelecting = true;

    // 3í—Ş‚©‚çƒ‰ƒ“ƒ_ƒ€‚ÉŒó•â‚ğ‘I‚Ô
    upgradeList[0] = rand() % 3;
    upgradeList[1] = rand() % 3;
    upgradeList[2] = rand() % 3;

    // d•¡‚ğ‚È‚­‚·
    while (upgradeList[0] == upgradeList[1])
    {
        upgradeList[1] = rand() % 3;
    }

    while (
        upgradeList[2] == upgradeList[0] ||
        upgradeList[2] == upgradeList[1])
    {
        upgradeList[2] = rand() % 3;
    }
}

void UpgradeManager::Update(Sword& sword)
{
    if (!isSelecting) return;

    int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);

    static int oldMouse = 0;

    int mouseInput = GetMouseInput();

    bool click =
        (mouseInput & MOUSE_INPUT_LEFT) &&
        !(oldMouse & MOUSE_INPUT_LEFT);

    oldMouse = mouseInput;

    if (!click) return;

    for (int i = 0; i < 3; i++)
    {
        int cardX = 290 + i * 240;

        int cardY = 260;

        if (
            mouseX >= cardX &&
            mouseX <= cardX + 200 &&
            mouseY >= cardY &&
            mouseY <= cardY + 250)
        {
            switch (upgradeList[i])
            {
            case 0:
                sword.AddAttackPower(1);
                break;

            case 1:
                sword.AddSwordLength(1.2f);
                break;

            case 2:
                sword.AddAttackDuration(4);
                break;
            }

            isSelecting = false;

            break;
        }
    }
}

void UpgradeManager::Draw()
{
    if (!isSelecting) return;

    // ”wŒi‚ğˆÃ‚­‚·‚é
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);

    DrawBox(
        0, 0, 1280, 720,
        GetColor(0, 0, 0),
        TRUE
    );

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    DrawString(
        520, 150,
        "LEVEL UP!",
        GetColor(255, 255, 0)
    );

    for (int i = 0; i < 3; i++)
    {
        int cardX = 290 + i * 240;

        int cardY = 260;

        DrawBox(
            cardX,
            cardY,
            cardX + 200,
            cardY + 250,
            GetColor(60, 60, 100),
            TRUE
        );

        DrawBox(
            cardX,
            cardY,
            cardX + 200,
            cardY + 250,
            GetColor(255, 255, 255),
            FALSE
        );

        switch (upgradeList[i])
        {
        case 0:
            DrawString(
                cardX + 35,
                cardY + 70,
                "ATTACK UP",
                GetColor(255, 100, 100)
            );

            DrawString(
                cardX + 20,
                cardY + 120,
                "Damage +1",
                GetColor(255, 255, 255)
            );
            break;

        case 1:
            DrawString(
                cardX + 35,
                cardY + 70,
                "SWORD UP",
                GetColor(100, 200, 255)
            );

            DrawString(
                cardX + 20,
                cardY + 120,
                "Length +20%",
                GetColor(255, 255, 255)
            );
            break;

        case 2:
            DrawString(
                cardX + 35,
                cardY + 70,
                "SPEED UP",
                GetColor(100, 255, 100)
            );

            DrawString(
                cardX + 20,
                cardY + 120,
                "Duration +4",
                GetColor(255, 255, 255)
            );
            break;
        }

        DrawString(
            cardX + 45,
            cardY + 210,
            "CLICK TO SELECT",
            GetColor(255, 255, 255)
        );
    }
}