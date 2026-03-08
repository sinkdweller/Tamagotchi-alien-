
#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

//n BUTTONS TO ACTION MAPPING (PULLUP)

struct Button {
  const int pinNumber;
  const char* label;
  void (*action)();
  unsigned long lastTime;
  bool lastState; 
  bool lastConfirmedState;
  
};

extern Button userButtons[];
void setupButtons(int num);
void checkButtons(unsigned long currentTime, int num);

#endif
