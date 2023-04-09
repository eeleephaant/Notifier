#include "Battery.h"

enum BatteryStatus {
    NOT_CHARGING = 0,
    CHARGING = 1,
    DISCHARGING = 2,
    FULL = 3
};

Battery::Battery(std::string pathToBat)
{
    this->_pathToDevice = pathToBat;
}

short Battery::GetChargeStatus()
{
    std::string statusState = QoklaToolbox::getFileContents(_pathToDevice + "/status", NULL);
    if (statusState == "Not charging")
    {
        return BatteryStatus::NOT_CHARGING;
    }
    else if (statusState == "Charging")
    {
        return BatteryStatus::CHARGING;
    }
    else if (statusState == "Discharging")
    {
        return BatteryStatus::DISCHARGING;
    }
    else if (statusState == "Full")
    {
        return BatteryStatus::FULL;
    }
    else {
        std::cout << "[ GetChargeStatus() ] Unsupported state : " << statusState;
        exit(1);
    }
}

int Battery::GetChargePercent()
{
    return stoi(QoklaToolbox::getFileContents(_pathToDevice + "/capacity", NULL));
}

int Battery::GetCycleCount()
{
    return stoi(QoklaToolbox::getFileContents(_pathToDevice + "/cycle_count", NULL));
}

std::string Battery::GetModelName()
{
    return QoklaToolbox::getFileContents(_pathToDevice + "/model_name", NULL);
}