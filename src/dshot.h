#pragma once
#ifndef DSHOT_H
#define DSHOT_H

#include "DriveMaster.h"

class dshot : public DriveMaster {
private:
  rmt_obj_t *_channel = nullptr;
  rmt_data_t _data[16];
public:
  explicit dshot(int pin);
  ~dshot();

  void begin() override;
  void write() override;
};

#endif
