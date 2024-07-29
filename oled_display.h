#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <U8g2lib.h> // Include the U8g2 library

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Create an instance of the U8g2 display class
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2; // Adjust the constructor parameters to match your display

void initializeDisplay();
void displayPressWithPowerButton(); // Add this function if used
void displayWeight(float weight, bool doorClosed);

#endif // OLED_DISPLAY_H

