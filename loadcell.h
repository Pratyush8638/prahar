#ifndef LOADCELL_H
#define LOADCELL_H

#include <HX711.h>

extern HX711 scale; // Declare the scale object

void initializeLoadCell();
void handleTareCommand();
float getWeight(); // Function to get the weight

#endif // LOADCELL_H
