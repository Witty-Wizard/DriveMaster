@mainpage
DriveMaster is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

# Supported Protocol

- [DShot300](#dshot300)
- [DShot600](#dshot600)

## DShot300 {#dshot300}

### Configuration

- Baud rate: 100000
- Data bits: 8 Bits
- Parity: Even Parity
- Stop bits: 2 Stop bits
- Signal polarity: Inverted

## DShot600 {#dshot600}

### Configuration

- Baud rate: 420000
- Data bits: 8 Bits
- Parity: No Parity
- Stop bits: 1 Stop bits
- Signal polarity: Uninverted

# Getting Started
- [Installation](#installation)
- [Tutorial](#tutorial)
- [Examples](#example)

# Installation {#installation}

## Arduino Installation

To use the DriveMaster library in your Arduino projects, follow these installation steps:

1. Download the DriveMaster library from the [GitHub repository](https://github.com/Witty-Wizard/DriveMaster).
2. Extract the downloaded ZIP file.
3. Copy the extracted folder to the `libraries` directory in your Arduino sketchbook.
4. Restart the Arduino IDE.
5. You should now be able to include the DriveMaster library in your Arduino sketches.

## PlatformIO Installation

If you are using PlatformIO, you can install the DriveMaster library directly from the PlatformIO Library Manager. Add the following line to your `platformio.ini` file:

```ini
lib_deps = Witty-Wizard/DriveMaster @ ^0.1.0
```
# Tutorial {#tutorial}

## Using DriveMaster Library for Motor Control

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

# Examples {#example}

## DShot Example
@include "../examples/basic_dshot/basic_dshot.ino"

# License
This library is distributed under the GNU [General Public License version 3.0](https://www.gnu.org/licenses/gpl-3.0.html).