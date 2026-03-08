#ifndef ACTIONS_H
#define ACTIONS_H
#include "sprites.h"
#include <Arduino.h>
extern const uint16_t* currentSprite;

void blink_idle(int currentTime);
void run_idle(int currentTime);
void eat_idle(int currentTime);

#endif