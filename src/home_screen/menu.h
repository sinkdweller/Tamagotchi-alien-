#pragma once
#include "constants.h"
#include <Arduino.h>
#include "icons.h"
#include "utils.h"
#include <Adafruit_SSD1351.h>
#include "littleGuy.h"
#include "globals.h"
extern Adafruit_SSD1351 tft;
extern littleGuy alien;
void drawMenu();
void shiftMenuRight();
void shiftMenuLeft();
void switchIdle();
void switchEat();
void switchSleep();
void switchExcercise();
void selectMenu();