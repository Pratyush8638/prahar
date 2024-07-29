#include "loadcell.h"
#include <HX711.h>

HX711 scale;

const int LOADCELL_DOUT_PIN = 25; // Change to an available pin
const int LOADCELL_SCK_PIN = 26;  // Change to an available pin

void initializeLoadCell() {
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(433); // Adjust to match your calibration factor
    scale.tare();         // Reset the scale to 0
}

void handleTareCommand() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        if (command.equalsIgnoreCase("tare")) {
            scale.tare();
            Serial.println("Scale tared.");
        }
    }
}

float getWeight() {
    if (scale.wait_ready_timeout(200)) {
        return round(scale.get_units());
    } else {
        Serial.println("HX711 not found.");
        return 0.0;
    }
}
