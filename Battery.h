#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "QoklaToolbox.h"

class Battery
{
private:
    std::string _pathToDevice;
    void _WatchDog();

public:
    Battery(std::string pathToBat);
    int GetChargePercent();
    short GetChargeStatus();
    int GetCycleCount();
    std::string GetModelName();
};
