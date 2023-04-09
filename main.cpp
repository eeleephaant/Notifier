#include <iostream>
#include "./Battery.h"
#include "./DeviceScreen.h"
#include <string>

int main(int argc, char *argv[])
{
    Battery battery("/sys/class/power_supply/BAT1");
    std::cout << "Battery percent: " << battery.GetChargePercent();
    std::cout << "\nBattery status: " << battery.GetChargeStatus();
    std::cout << "\nCycle count: " << battery.GetCycleCount();
    std::cout << "\nBattery model: " << battery.GetModelName();

    DeviceScreen screen("/sys/class/backlight/amdgpu_bl0");
    std::cout << "\n\nScreen brightness raw: " << screen.GetBrightnessRaw();
    std::cout << "\n Screen brightness percent: " << screen.GetBrightnessPercent();
    unsigned char brightness;
    std::cout << "\n\n\nLets to change brightness: ";
    std::cin >> brightness;
    screen.ChangeBrightnessPercent(brightness);
    std::cout << "\nBrightness now: " << screen.GetBrightnessPercent();

}