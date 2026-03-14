#pragma once
#include "constants.h"
#include <Arduino.h>
#include "misc_assets/particles.h"
#include "utils.h"
#include <Adafruit_SSD1351.h>
extern Adafruit_SSD1351 tft;
extern GFXcanvas16 canvas;

struct Food{
    const uint16_t* sprite;
    int nutrition;
    int x;
    int y;
    int moveInterval; //millis/pixel
    unsigned long lastMoveTime;
    bool active;
    int flyLeftToCenter(unsigned long currentTime);
};
Food& getRandomFood();
extern Food* currentlyFlying;
void renderActiveItems();