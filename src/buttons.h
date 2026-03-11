#pragma once

#include <Arduino.h>
#include "home_screen/menu.h"
//n BUTTONS TO ACTION MAPPING (PULLUP)

extern void shiftMenuLeft();
extern void shiftMenuRight();
void setupButtons(int num);
int checkButtons(unsigned long currentTime, int num);


