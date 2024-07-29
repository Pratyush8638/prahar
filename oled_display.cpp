#include "oled_display.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "power_button.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initializeDisplay() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Infinite loop if initialization fails
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds("Drones", 0, 0, &x1, &y1, &w, &h);
    display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2 - 10);
    display.println(F("Drones"));

    display.getTextBounds("Tech Lab", 0, 0, &x1, &y1, &w, &h);
    display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2 + 10);
    display.println(F("Tech Lab"));

    display.display();
    delay(2000);

    display.clearDisplay();
}
void displayPressWithPowerButton() {
  display.clearDisplay();
  display.setTextSize(2); // Set text size to 2
  display.setTextColor(WHITE); // Set text color to white

  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds("Press", 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, 0); // Center the text

  display.println(F("Press"));
  // Draw power button bitmap
  display.drawBitmap(
    (SCREEN_WIDTH - 32) / 2, // X position
    (SCREEN_HEIGHT / 4),     // Y position (just below "Press")
    power_button_bmp,        // Bitmap data
    32, 32,                  // Bitmap dimensions
    WHITE                    // Bitmap color
  );
}

void displayWeight(float weight, bool doorClosed) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    if (weight > 200) {
        display.setCursor(0, 0);
          String cautionStr = F("CAUTION!"); // Text to display
        int16_t x1, y1;
        uint16_t w, h;
        display.getTextBounds(cautionStr, 0, 0, &x1, &y1, &w, &h);// Get text bounds for the "CAUTION!" string
        display.setCursor((SCREEN_WIDTH - w) / 2, 0); // Top center// Set cursor to horizontally center the "CAUTION!" text
        display.println(cautionStr); // Display the text
        // display.println(F("CAUTION!"));
        display.setTextSize(1);
        display.setCursor(0, 30);
        display.println(F("Overweight!"));
        display.setTextSize(1);
        display.setCursor(0, 45);
        display.print(F("Weight: "));
        display.print(weight);
        display.println(F("g"));
    } else {
        display.setCursor(0, 0);
        // display.setTextSize(1);
        // display.print(F("Weight: "));
        display.setTextSize(2);
        String weightStr = String(weight) + "g"; // Create a string with the weight
  
        int16_t x1, y1;
        uint16_t w, h;
       display.getTextBounds(weightStr, 0, 0, &x1, &y1, &w, &h);        // Get text bounds for the weight string
       display.setCursor((SCREEN_WIDTH - w) / 2, 0); // Top center // Set cursor to horizontally center the text
       display.println(weightStr); // Display the weight
    }

    if (doorClosed && weight < 200) {
      display.clearDisplay();
      display.setTextSize(2); // Set text size to 2
      display.setTextColor(WHITE); // Set text color to white

      int16_t x1, y1;
      uint16_t w, h;
      display.getTextBounds("Press", 0, 0, &x1, &y1, &w, &h);
      display.setCursor((SCREEN_WIDTH - w) / 2, 0); // Center the text
      display.println(F("Press"));
      // Draw power button bitmap
    display.drawBitmap(
    (SCREEN_WIDTH - 32) / 2, // X position
    (SCREEN_HEIGHT / 4),     // Y position (just below "Press")
    power_button_bmp,        // Bitmap data
    32, 32,                  // Bitmap dimensions
    WHITE                    // Bitmap color
  );
        // display.println(F("Door: Closed"));
    } else {
        display.println(F("Door: Open"));
    }
    display.display();
}
