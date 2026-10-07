/*
 * Voice Controlled Humanoid Robot
 * Microcontroller: ATmega328P / Arduino Uno
 * Motor Shield: Adafruit L293D
 * Communication: HC-05 Bluetooth Module (UART)
 */

#include <AFMotor.h>

// Motor speed configuration (0 - 255)
#define MOTOR_SPEED 170

// Define motor channels
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Initialize UART communication with HC-05
  Serial.begin(9600);

  // Set default speed for all DC motors
  motor1.setSpeed(MOTOR_SPEED);
  motor2.setSpeed(MOTOR_SPEED);
  motor3.setSpeed(MOTOR_SPEED);
  motor4.setSpeed(MOTOR_SPEED);

  stopMotors();
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'U': // Move Forward
        moveForward();
        break;
      case 'D': // Move Backward
        moveBackward();
        break;
      case 'L': // Turn Left
        turnLeft();
        break;
      case 'R': // Turn Right
        turnRight();
        break;
      case 'S': // Stop all motors
        stopMotors();
        break;
      default:
        break;
    }
  }
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
