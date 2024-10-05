/**
 * @file dshot.h
 * @brief Header file for the dshot class.
 */

#pragma once
#ifndef DSHOT_H
#define DSHOT_H

#include "DriveMaster.h"

#if defined(ARDUINO_ARCH_ESP32)
#include <esp32-hal-rmt.h>
#define DSHOT_FRAME_LENGTH 16

/**
 * @brief Enumeration for different DShot types.
 */
enum DShotType
{
  DSHOT_150, /**< DShot150 protocol */
  DSHOT_300  /**< DShot300 protocol */
};

/**
 * @brief Class representing DShot communication.
 */
class dshot : public DriveMaster
{
private:
  rmt_data_t _data[DSHOT_FRAME_LENGTH]; /**< RMT data array for DShot frames */
  uint16_t _timingDuration0;            /**< Timing duration for logic 0 */
  uint16_t _timingDuration1;            /**< Timing duration for logic 1 */
  uint16_t _timingDurationBit;          /**< Timing duration for a bit */
  /**
   * @brief Calculate the CRC (Cyclic Redundancy Check) for the given DShot
   * command value.
   * @param value DShot command value
   * @return Calculated CRC value
   */
  uint8_t calculateCrc(uint16_t value);
  /**
   * @brief Write a DShot frame with the specified value and telemetry flag.
   * @param value DShot value to write
   * @param telemetry Flag indicating telemetry presence
   */
  void write(uint16_t value, bool telemetery = false);

public:
  /**
   * @brief Construct a new dshot object with the specified pin and DShot type.
   * @param pin Pin to use for DShot communication
   * @param type DShot protocol type (DSHOT_150 or DSHOT_300)
   */
  explicit dshot(int pin, DShotType type = DSHOT_300);
  /**
   * @brief Destroy the dshot object.
   */
  ~dshot();
  /**
   * @brief Initialize the DShot communication.
   */
  void begin() override;
  /**
   * @brief Send a DShot command with telemetry enabled.
   * @param value DShot command value
   */
  void sendCommand(uint16_t value) override;
  /**
   * @brief Send a DShot value with telemetry disabled.
   * @param value DShot value to send
   */
  void sendValue(uint16_t value) override;
};
#endif
#endif
