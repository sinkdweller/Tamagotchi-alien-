#ifndef ACTIONS_H
#define ACTIONS_H
#include "sprites.h"
#include "globals.h"
#include <Arduino.h>
extern const uint16_t* currentSprite;

extern littleGuy alien;  
void doBlink(int currentTime);
void doRun(int currentTime);
void doEat(int currentTime);
void doPoke(int currentTime);
void doSleep(int currentTime);
#endif