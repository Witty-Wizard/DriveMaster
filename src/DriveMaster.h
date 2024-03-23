#pragma once
#ifndef DRIVEMASTER_H
#define DRIVEMASTER_H

#include <Arduino.h>

class DriveMaster {
public:
  DriveMaster(int pin);
  virtual ~DriveMaster();
  virtual void begin();
  virtual void write(uint16_t value, bool telemetery = false);
  virtual void sendCommand(uint16_t value);
  virtual void sendValue(uint16_t value);

protected:
  int _pin;
};
#include "dshot.h"
#endif
