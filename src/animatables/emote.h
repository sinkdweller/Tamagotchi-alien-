#pragma once
#include "constants.h"
#include <Arduino.h>
#include "misc_assets/emotes.h"
#include "utils.h"
#include <Adafruit_SSD1351.h>
extern GFXcanvas16 canvas;

struct Emote{
    const uint16_t* sprite;
    unsigned long timeStart;
    int duration;
};

extern Emote* currentEmote;
extern Emote vein;
extern Emote sweat;
extern Emote err;
void drawEmote(int x, int y); //draws currentEmote on top of alien;