
#include "actions.h"

const int BLINK_DURATION = 200;
unsigned long lastBlinkTime = 0;
bool isBlinking = false;
int nextBlinkInterval=3000;
void blink_idle(int currentTime){  
  //start blink
  if(!isBlinking && (currentTime - lastBlinkTime > nextBlinkInterval)){
      isBlinking = true;
      currentSprite = alien_right_blink;
      lastBlinkTime = currentTime;
  }
  //unblink
  if(isBlinking && (currentTime - lastBlinkTime > BLINK_DURATION)){
      isBlinking = false;
      currentSprite = alien_right_open;
      nextBlinkInterval = random(3000,6000);
      lastBlinkTime = currentTime;
  }
}