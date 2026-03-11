
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
    alien_eating_0,
    alien_eating_1,
    1000,
    1000,
    1,
    0,
    0
};
Animation runAnim{
    alien_running_0,
    alien_running_1,
    1200,
    1200,
    1,
    0,
    0
};
void doAnimation(int currentTime, Animation& anim){
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
void doEat(int currentTime){
    doAnimation(currentTime, eatAnim);
}
void doRun(int currentTime){
    doAnimation(currentTime, runAnim);

}
//put this with animation struct later...
const int BLINK_DURATION = 200;
unsigned long lastBlinkTime = 0;
bool isBlinking = false;
int nextBlinkInterval=3000;
void doBlink(int currentTime){  
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

