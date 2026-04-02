#ifndef ACTIONS_H
#define ACTIONS_H
#include "sprites.h"
#include "globals.h"
#include <Arduino.h>
extern const uint16_t* currentSprite;

extern littleGuy alien;
//Sick idles/animations are automatically managed here
void doIdle(unsigned long currentTime);
void doRun(unsigned long currentTime);
void doPoke(unsigned long currentTime);
void doSleep(unsigned long currentTime);
void openMouth();
void closeMouth();
#endif