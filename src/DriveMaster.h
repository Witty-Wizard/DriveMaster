#pragma once
#ifndef DRIVEMASTER_H
#define DRIVEMASTER_H

#include <Arduino.h>
#include <esp32-hal-rmt.h>

class DriveMaster {
public:
  DriveMaster(int pin);
  virtual ~DriveMaster();
  virtual void begin();
  virtual void write();

protected:
  int _pin;
};
#include "dshot.h"

#endif
