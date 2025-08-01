#include "dshot.h"

#if defined(ARDUINO_ARCH_ESP32)

dshot::dshot(int pin, DShotType type) : DriveMaster(pin)
{
  switch(type) {
  case DSHOT_150:
    _timingDuration0 = 250;
    _timingDuration1 = 500;
    _timingDurationBit = 667;
    break;
  case DSHOT_300:
    _timingDuration0 = 125;
    _timingDuration1 = 250;
    _timingDurationBit = 333;
    break;
  }
}
dshot::~dshot() {}

void
dshot::begin()
{
  rmtInit(_pin, RMT_TX_MODE, RMT_MEM_NUM_BLOCKS_1, 1000);
}

void
dshot::write(uint16_t value, bool telemetery)
{
  uint8_t crc = calculateCrc(value);
  for(int i = 0; i < 16; i++) {
    if(i < 11) {
      _data[i].duration0 =
        ((value >> i) & 0x01) ? _timingDuration1 : _timingDuration0;
    }
    else if(i == 11) {
      _data[i].duration0 = telemetery ? _timingDuration1 : _timingDuration0;
    }
    else {
      _data[i].duration0 =
        ((crc >> (i - 12)) & 0x01) ? _timingDuration1 : _timingDuration0;
    }
    _data[i].duration1 = _timingDurationBit - _data[i].duration0;
    _data[i].level0 = 1;
    _data[i].level1 = 0;
  }
  rmtWrite(_pin, _data, DSHOT_FRAME_LENGTH, 10);
}

uint8_t
dshot::calculateCrc(uint16_t value)
{
  return ((value ^ (value >> 4) ^ (value >> 8)) & 0x0F);
}

void
dshot::sendCommand(uint16_t value)
{
  write(value, true);
}
void
dshot::sendValue(uint16_t value)
{
  write(value, false);
}
#endif