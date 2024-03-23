#include "dshot.h"

dshot::dshot(int pin) : DriveMaster(pin) {}
dshot::~dshot() {}

void dshot::begin() { _channel = rmtInit(_pin, RMT_TX_MODE, RMT_MEM_64); }

void dshot::write() {
rmtWrite(_channel, _data, 16);
}