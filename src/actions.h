#ifndef ACTIONS_H
#define ACTIONS_H
#include "sprites.h"
#include "globals.h"
#include <Arduino.h>
extern const uint16_t* currentSprite;

extern littleGuy alien;  
void doBlink(unsigned long currentTime);
void doRun(unsigned long currentTime);
void doEat(unsigned long currentTime, bool openMouth);
void doPoke(unsigned long currentTime);
void doSleep(unsigned long currentTime);

#endif