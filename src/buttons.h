#pragma once

#include <Arduino.h>
#include "menu.h"
//n BUTTONS TO ACTION MAPPING (PULLUP)

extern void shiftMenuLeft();
extern void shiftMenuRight();
void setupButtons(int num);
void checkButtons(unsigned long currentTime, int num);


