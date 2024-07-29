#include <Arduino.h>
#include "oled_display.h"
#include "loadcell.h"
#include "reedswitch.h"
#include "safteyswitch.h"

// #define FEEDBACK_PIN 40
// #define BUTTON_LED_PIN 44

// SafetySwitch safetySwitch(FEEDBACK_PIN, BUTTON_LED_PIN);

void setup() {
    Serial.begin(57600);
    initializeLoadCell();
    initializeDisplay();
    initializeReedSwitch();
    // safetySwitch.begin(); 
}

void loop() {
    handleTareCommand(); // Check for tare command
    float weight = getWeight(); // Get weight from the load cell
    bool doorClosed = checkReedSwitch(); // Check the state of the reed switch
    displayWeight(weight, doorClosed); // Display weight and door status
    // safetySwitch.update();
    delay(500); // Check weight every 500ms
}
