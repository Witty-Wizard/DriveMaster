@mainpage
DriveMaster is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

# Supported Protocol

- [DShot](#dshot)

## DShot {#dshot}

### Frame Structure
The DShot frame consists of 16 bits and follows a specific structure:

- **Throttle**: 11 bits representing throttle values ranging from 48 to 2047.
- **Telemetry Request**: 1 bit indicating whether telemetry data is requested.
- **CRC**: 4 bits for error checking using a cyclic redundancy check.

### DShot Versions and Bitrates
Different versions of DShot support varying bitrates and durations for high and low signal times:

| DShot Version | Bitrate (bps) | T1H (µs) | T0H (µs) | Bit Length (µs) | Frame Length (µs) |
|---------------|----------------|----------|----------|-----------------|-------------------|
| DShot150      | 150,000        | 5.00     | 2.50     | 6.67            | 106.72            |
| DShot300      | 300,000        | 2.50     | 1.25     | 3.33            | 53.28             |
| DShot600      | 600,000        | 1.25     | 0.625    | 1.67            | 26.72             |
| DShot1200     | 1,200,000      | 0.625    | 0.313    | 0.83            | 13.28             |



# Getting Started
- [Installation](#installation)
- [Tutorial](#tutorial)
- [Examples](#example)

## Installation {#installation}

### Arduino Installation

To use the DriveMaster library in your Arduino projects, follow these installation steps:

1. Download the DriveMaster library from the [GitHub repository](https://github.com/Witty-Wizard/DriveMaster).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to the `libraries` directory in your Arduino sketchbook.
4. Restart the Arduino IDE.
5. You should now be able to include the DriveMaster library in your Arduino sketches.

### PlatformIO Installation

If you are using PlatformIO, you can install the DriveMaster library directly from the PlatformIO Library Manager. Add the following line to your `platformio.ini` file:

```ini
lib_deps = Witty-Wizard/DriveMaster @ ^0.1.0
```
## Tutorial {#tutorial}

### Using DriveMaster Library for Motor Control

To control motors in your Arduino project using the DriveMaster library, follow these steps:

1. **Include Necessary Libraries**

Include the required library at the beginning of your sketch:
```cpp
#include <DriveMaster.h>
```

2. **Instantiate DriveMaster Object**
Create an instance of the DriveMaster class, specifying the pin connected to the motor:

```cpp
DriveMaster *motor = new DriveMaster(motorPin);
```

3. **Initialize Motor Control**
Call the begin() method to initialize motor control:

```cpp
void setup() {
    motor->begin();
}
```

5. **Send Commands or Values**
You can use the sendCommand() or sendValue() methods to send specific commands or values to the motor:

```cpp
// Send a specific command to the motor
motor->sendCommand(1000);

// Send a value directly to the motor
motor->sendValue(512);
```

## Examples {#example}

### DShot Example
@include "./examples/basic_dshot/basic_dshot.ino"

# License
This library is distributed under the GNU [General Public License version 3.0](https://www.gnu.org/licenses/gpl-3.0.html).