#pragma once
#include "littleGuy.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
enum SCREENS {
  HOME_SCREEN,
  STAT_SCREEN
};

extern littleGuy alien;
extern GFXcanvas16 canvas;
extern Adafruit_SSD1351 tft;
extern SCREENS currentScreen;