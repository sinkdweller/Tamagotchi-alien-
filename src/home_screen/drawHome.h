#pragma once
#include "constants.h"
#include "backgrounds.h"
#include "utils.h"
#include "globals.h"
#include "animatables/foods.h"
#include "animatables/emote.h"
//draws Alien and home
void drawHome(int currentTime);
void drawBackground();
void drawFood();
void drawBar(int x, int y, int barWidth, int barHeight, int statValue);