#include "DeviceScreen.h"

DeviceScreen::DeviceScreen(std::string pathToDevice)
{
    this->_pathToDevice = pathToDevice;
    this->_dpy = XOpenDisplay(NULL);
    this->_rootWindow = RootWindow(this->_dpy, 0);
}

void DeviceScreen::ChangeBrightnessRaw(unsigned char brightness)
{
    this->_backlight = XInternAtom(this->_dpy, "Backlight", True);
    this->_resources = XRRGetScreenResources(this->_dpy, this->_rootWindow);
    this->_output = _resources->outputs[0];
    this->_info = XRRQueryOutputProperty(this->_dpy, this->_output, this->_backlight);
    this->_min = this->_info->values[0];
    this->_max = this->_info->values[1];

    XRRFreeScreenResources(this->_resources);
    XFree(this->_info);

    XRRChangeOutputProperty(this->_dpy, this->_output, this->_backlight, XA_INTEGER, 32, PropModeReplace, (unsigned char *) &brightness, 1);

    XFlush(this->_dpy);
    XSync(this->_dpy, False);
}

void DeviceScreen::ChangeBrightnessPercent(unsigned char brightnessPercent)
{
    ChangeBrightnessRaw(ceil(brightnessPercent * 2.55));
}

int DeviceScreen::GetBrightnessRaw()
{
    return stoi(QoklaToolbox::getFileContents(this->_pathToDevice + "/actual_brightness", NULL));
}

int DeviceScreen::GetBrightnessPercent()
{
    return ceil(GetBrightnessRaw() / (float)2.55);
}