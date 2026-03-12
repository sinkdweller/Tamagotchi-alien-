
#include "actions.h"
//two frame animations
struct Animation{
    const uint16_t* frame0;
    const uint16_t* frame1;
    int frame0Duration;
    int frame1Duration;
    bool frameState; //frame 1 or 2.
    int nextInterval;
    int lastToggleTime;

};
Animation eatAnim{
    alien_eating_0, //mouth closed
    alien_eating_1, //mouth closed
    1000,
    1000,
    1,
    0,
    0
};
Animation runAnim{
    alien_running_0,
    alien_running_1,
    700,
    700,
    1,
    0,
    0
};
void doAnimation(unsigned long currentTime, Animation& anim){
    //setframe state to 1 if 0
    if(!anim.frameState && (currentTime-anim.lastToggleTime > anim.frame0Duration )){
        alien.setSprite(anim.frame1);
        anim.lastToggleTime = currentTime;
        anim.frameState=1;
    }
    if(anim.frameState && (currentTime-anim.lastToggleTime > anim.frame1Duration)){
        alien.setSprite(anim.frame0);
        anim.lastToggleTime = currentTime;
        anim.frameState=0;
    }
}
//Setting alien sprite:
//frame1 to set to for hold time
//frame2 to revert to

bool toggleAnimTimed(unsigned long currentTime, Animation& anim, bool flipFrameState, int holdTime){
    const uint16_t* flipFrame = flipFrameState ? anim.frame1: anim.frame0;
    //if not flipped, flip the first time
    if(anim.frameState!=flipFrameState){
        alien.setSprite(flipFrame);
        anim.frameState = flipFrameState;
        anim.lastToggleTime = currentTime;
        return 1;
    }
    const uint16_t* initialFrame = flipFrameState ? anim.frame0: anim.frame1;

    // revert after hold time
    if(anim.frameState==flipFrameState && (currentTime - anim.lastToggleTime > holdTime)){
        alien.setSprite(initialFrame);
        anim.frameState = !flipFrameState;
        return 0;
    }

}
void doEat(unsigned long currentTime, bool buttonPressed) {
    static unsigned long eatStartTime = 0;
    static bool isEating = false;

    if (buttonPressed && !isEating) {
        isEating = true;
        eatStartTime = currentTime;
        alien.setSprite(eatAnim.frame1); // OPEN MOUTH
        Serial.println("OPEN");
    }

    if (isEating) {
        // If 1 second passes, close it
        if (currentTime - eatStartTime >= 1000) {
            alien.setSprite(eatAnim.frame0); // CLOSED MOUTH
            isEating = false;
            Serial.println("CLOSED - TIMER DONE");
        }
    } else {
        // This ensures if we aren't eating, we ARE closed.
        // If your setSprite handles "same sprite" checks, this won't lag.
        alien.setSprite(eatAnim.frame0); 
    }
}
void doRun(unsigned long currentTime){
    doAnimation(currentTime, runAnim);

}
//put this with animation struct later...
const int BLINK_DURATION = 200;
unsigned long lastBlinkTime = 0;
bool isBlinking = false;
int nextBlinkInterval=3000;
void doBlink(unsigned long currentTime){  
  //start blink
  if(!isBlinking && (currentTime - lastBlinkTime > nextBlinkInterval)){
      isBlinking = true;
      alien.setSprite(alien_right_blink);
      lastBlinkTime = currentTime;
  }
  //unblink
  if(isBlinking && (currentTime - lastBlinkTime > BLINK_DURATION)){
      isBlinking = false;
      alien.setSprite(alien_right_open);
      nextBlinkInterval = random(3000,6000);
      lastBlinkTime = currentTime;
  }
}

