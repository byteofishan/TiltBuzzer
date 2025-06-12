# TiltAlert

TiltAlert is an Arduino-based tilt indicator using an ADXL accelerometer, LEDs, and a buzzer. When the device is tilted, an array of LEDs light up and a buzzer alerts the user.

## Components Used:
- Arduino Uno/Nano
- ADXL335/345 Accelerometer
- LEDs
- Buzzer
- Resistors
- Breadboard & Jumper Wires

## Features:
- Detects tilt direction and angle
- LED indication based on tilt
- Buzzer alert on large tilt

## How It Works:
The ADXL sensor detects tilt in X/Y axes. The Arduino processes this and triggers corresponding LEDs and buzzer alerts.

## Circuit Diagram:
https://github.com/byteofishan/TiltBuzzer/commit/2b9b8209d31d83f21cd3a783926de2eb4cdc771a#diff-9ca8b51c9357a700ebb6740ff4f8044d51476feb1a2a35b89451de8b7ba594ce

## Code:
 https://github.com/byteofishan/TiltBuzzer/blob/main/tilt.ino 
