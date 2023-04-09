#pragma once

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#include "QoklaToolbox.h"
#include "math.h"

class DeviceScreen
{
private:
    unsigned char _brightness;
    Display *_dpy;
    Atom _backlight;
    int _screen = 0, o = 0;
    Window _rootWindow;
    XRRScreenResources *_resources;
    RROutput _output;
    XRRPropertyInfo *_info;
    double _min, _max;
    long _value;
    std::string _pathToDevice;

public:
    DeviceScreen(std::string pathToDevice);
    void ChangeBrightnessRaw(unsigned char brightness);
    void ChangeBrightnessPercent(unsigned char percentBrightness);

    int GetBrightnessRaw();
    int GetBrightnessPercent();
};
