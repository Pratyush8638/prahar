#include "reedswitch.h"
#include <Arduino.h>

const int switchReed = 24; // Define the reed switch pin

void initializeReedSwitch() {
    pinMode(switchReed, INPUT); // Set the reed switch pin as input
}

bool checkReedSwitch() {
    return digitalRead(switchReed) == HIGH;
}
