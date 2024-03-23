#pragma once
#ifndef DSHOT_H
#define DSHOT_H

#include "DriveMaster.h"
#include <esp32-hal-rmt.h>
#define DSHOT_FRAME_LENGTH 16

enum DShotType { DSHOT_150, DSHOT_300 };

class dshot : public DriveMaster {
private:
  rmt_obj_t *_channel = nullptr;
  rmt_data_t _data[DSHOT_FRAME_LENGTH];
  uint16_t _timingDuration0;
  uint16_t _timingDuration1;
  uint16_t _timingDurationBit;
  uint8_t calculateCrc(uint16_t value);
  void write(uint16_t value, bool telemetery = false);

public:
  explicit dshot(int pin, DShotType type = DSHOT_300);
  ~dshot();

  void begin() override;
  void sendCommand(uint16_t value) override;
  void sendValue(uint16_t value) override;
};

#endif
