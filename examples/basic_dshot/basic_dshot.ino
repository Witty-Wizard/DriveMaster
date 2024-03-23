/*!
 * @file basic_dshot.ino
 */
#include <DriveMaster.h>

#define MOTOR_PIN 9

DriveMaster *motor;

void setup() {
  motor = new DriveMaster(MOTOR_PIN);
  motor->begin();
}

void loop() {
  motor->sendValue(512);
  delay(1000); // Delay for 1 second
}