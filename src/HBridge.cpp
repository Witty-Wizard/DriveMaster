#include <HBridge.h>

HBridge::HBridge(int pin, int dir_pin) : DriveMaster(pin, dir_pin) {}

void
HBridge::begin()
{
  pinMode(_pin, OUTPUT);
  pinMode(_dir_pin, OUTPUT);
}

void
HBridge::write(int16_t value)
{
  value = constrain(value, -255, 255);
  digitalWrite(_dir_pin, (value > 0) ? LOW : HIGH);
  value = (value > 0) ? value : 255 + value;
  analogWrite(_pin, value);
}