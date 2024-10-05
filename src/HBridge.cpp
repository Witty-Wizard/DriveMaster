#include <HBridge.h>

HBridge::HBridge(int pin, int dir_pin) : DriveMaster(pin, dir_pin)
{
}

void HBridge::begin()
{
    pinMode(_pin, OUTPUT);
    pinMode(_dir_pin, OUTPUT);
}

void HBridge::write(int16_t value)
{
    value = value % 256;
    if (value >= 0)
    {
        digitalWrite(_dir_pin, LOW);
    }
    else
    {
        digitalWrite(_dir_pin, HIGH);
        value = 255 + value;
    }
    analogWrite(_pin, value);
}