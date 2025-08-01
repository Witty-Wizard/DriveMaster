/**
 * @file HBridge.h
 * @brief Header file for the HBridge class, which controls an H-Bridge motor
 * driver.
 */

#pragma once
#ifndef HBRIDGE_H
#define HBRIDGE_H

#include "DriveMaster.h"

/**
 * @class HBridge
 * @brief A class to control an H-Bridge motor driver.
 *
 * The HBridge class provides methods to initialize and control the speed and
 * direction of a motor using an H-Bridge. It inherits from the DriveMaster
 * base class, which provides the control pins.
 */
class HBridge : public DriveMaster
{
public:
  /**
   * @brief Constructs an HBridge object with specified control pins.
   *
   * @param pin The PWM pin used for controlling motor speed (inherited from
   * DriveMaster).
   * @param dir_pin The direction control pin (inherited from DriveMaster).
   */
  explicit HBridge(int pin, int dir_pin);

  /**
   * @brief Initializes the H-Bridge driver.
   *
   * Sets up the necessary pin modes for motor control.
   */
  void begin() override;

  /**
   * @brief Writes a speed value to the motor.
   *
   * The value controls both the speed and direction of the motor.
   * Positive values set forward direction, while negative values set reverse
   * direction. The value is constrained between -255 and 255.
   *
   * @param value The speed value to write, where 0 is stopped, 255 is full
   * forward, and -255 is full reverse.
   */
  void write(int16_t value) override;
};

#endif // HBRIDGE_H
