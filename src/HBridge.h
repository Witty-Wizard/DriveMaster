/**
 * @file HBridge.h
 * @brief Header file for the HBridge class.
 */

#pragma once
#ifndef HBRIDGE_H
#define HBRIDGE_H

#include "DriveMaster.h"

class HBridge : public DriveMaster{
    private:

    public:
    explicit HBridge(int pin, int dir_pin);
    void begin() override;
    void write(int16_t value) override;
};

#endif