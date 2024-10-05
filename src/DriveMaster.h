/**
 * @file DriveMaster.h
 * @brief Header file for the DriveMaster class.
 */

#pragma once
#ifndef DRIVEMASTER_H
#define DRIVEMASTER_H

#include <Arduino.h>

/**
 * @brief Base class for motor control.
 */
class DriveMaster
{
public:
  /**
   * @brief Construct a new DriveMaster object with only the pin.
   * @param pin The pin number for motor control.
   */
  DriveMaster(int pin);

  /**
   * @brief Construct a new DriveMaster object with the specified pin and direction pin.
   * @param pin The pin number for motor control.
   * @param dir_pin The pin number for direction control.
   */
  DriveMaster(int pin, int dir_pin);

  /**
   * @brief Destroy the DriveMaster object.
   */
  virtual ~DriveMaster();

  /**
   * @brief Initialize the motor control.
   */
  virtual void begin();

  /**
   * @brief Write a command to the motor.
   * @param value The command value to write.
   * @param telemetry Flag indicating telemetry presence.
   */
  virtual void write(uint16_t value, bool telemetery = false);

  /**
   * @brief Write a command to the motor using an 8-bit signed integer value.
   *        The value ranges from -255 to 255, where:
   *        - 255 is full speed forward
   *        - -255 is full speed reverse
   *        - 0 is stop
   * @param value The signed 8-bit command value to write (-255 to 255).
   */
  virtual void write(int16_t value);

  /**
   * @brief Send a command to the motor.
   * @param value The command value to send.
   */
  virtual void sendCommand(uint16_t value);

  /**
   * @brief Send a value to the motor.
   * @param value The value to send.
   */
  virtual void sendValue(uint16_t value);

protected:
  int _pin;     /**< Pin number for motor control. */
  int _dir_pin; /**< Pin number for direction control. */
};
#include "dshot.h"
#include "HBridge.h"
#endif
