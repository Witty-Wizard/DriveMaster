#include "DriveMaster.h"

DriveMaster::DriveMaster(int pin) : _pin(pin) {}

DriveMaster::~DriveMaster() {}

void DriveMaster::begin() {}

void DriveMaster::write(uint16_t value, bool telemetery) {}

void DriveMaster::sendCommand(uint16_t value) {}
void DriveMaster::sendValue(uint16_t value) {}