#pragma once
#include "constants.h"
#include "constants.h"
#include <Arduino.h>
#include "misc_assets/particles.h"
#include "utils.h"
#include <Adafruit_SSD1351.h>
extern GFXcanvas16 canvas;
int center_x(int width);
int center_y(int height);
void drawSpriteTransparent(int x, int y, const uint16_t* sprite, int w, int h);