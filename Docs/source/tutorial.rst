.. _tutorial:

Tutorial
========

Using DriveMaster Library for Motor Control
-------------------------------------------

To control motors in your Arduino project using the DriveMaster library, follow these steps:

1. **Include Necessary Libraries**

Include the required library at the beginning of your sketch:

.. code-block:: cpp

   #include <DriveMaster.h>

2. **Instantiate DriveMaster Object**

Create an instance of the DriveMaster class, specifying the pin connected to the motor:

.. code-block:: cpp

   DriveMaster *motor = new dshot(motorPin);

3. **Initialize Motor Control**

Call the ``begin()`` method to initialize motor control:

.. code-block:: cpp

   void setup() {
       motor->begin();
   }

4. **Send Commands or Values**

You can use the ``sendCommand()`` or ``sendValue()`` methods to send specific commands or values to the motor:

.. code-block:: cpp

   // Send a specific command to the motor
   motor->sendCommand(1000);

   // Send a value directly to the motor
   motor->sendValue(512);