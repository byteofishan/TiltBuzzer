#include <Wire.h>
#include <Adafruit_ADXL345_U.h>

// Define constants
const int NUM_LEDS = 11;
const int LED_PINS[NUM_LEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int SMOOTHNESS = 1; // Higher value = smoother transition
const int BUZZER_PIN = A0;

// Define ADXL345 object
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

int currentLED = 0;
int targetLED = 0;

// Define notes for each LED
int notes[NUM_LEDS] = {262,294, 330, 349, 392, 440, 494, 523, 587, 659, 698};

void setup() {
  Serial.begin(9600);

  // Initialize ADXL345
  if (!accel.begin()) {
    Serial.println("Failed to find ADXL345 chip");
    while (1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
  
  // Initialize LED pins
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Read accelerometer data
  sensors_event_t event;
  accel.getEvent(&event);

  // Calculate tilt angle
  float angle = atan2(event.acceleration.y, event.acceleration.x) * 180 / PI;

  // Map angle to LED index
  targetLED = map(angle, 0, -90, 0, NUM_LEDS - 1);
  targetLED = constrain(targetLED, 0, NUM_LEDS - 1);

  // Smooth LED transition
  if (currentLED < targetLED) {
    currentLED = min(currentLED + SMOOTHNESS, targetLED);
  } else if (currentLED > targetLED) {
    currentLED = max(currentLED - SMOOTHNESS, targetLED);
  }

  // Update LEDs and play note
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i == currentLED) {
      digitalWrite(LED_PINS[i], HIGH);
      tone(BUZZER_PIN, notes[i]);
    } else {
      digitalWrite(LED_PINS[i], LOW);
    }
  }

  delay(50);
  noTone(BUZZER_PIN); // Turn off buzzer
}
