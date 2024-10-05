#include "DriveMaster.h"

DriveMaster::DriveMaster(int pin) : _pin(pin), _dir_pin(-1) {}

DriveMaster::DriveMaster(int pin, int dir_pin) : _pin(pin), _dir_pin(dir_pin) {}

DriveMaster::~DriveMaster() {}

void DriveMaster::begin() {}

void DriveMaster::write(uint16_t value, bool telemetery) {}
void DriveMaster::write(int16_t value) {}

void DriveMaster::sendCommand(uint16_t value) {}
void DriveMaster::sendValue(uint16_t value) {}