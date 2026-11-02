#pragma once

#include "Sword.h"

class UpgradeManager
{
private:

    int upgradeList[3];

    bool isSelecting;

public:

    void Initialize();

    void StartSelection();

    void Update(Sword& sword);

    void Draw();

    bool IsSelecting() const
    {
        return isSelecting;
    }
};