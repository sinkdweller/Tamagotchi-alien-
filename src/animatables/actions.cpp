
#include "actions.h"
int SICK_HEALTH = 50;

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
Animation happyAnim{
    alien_happy_0,
    alien_happy_1,
    700,
    700,
    1,
    0,
    0
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
Animation eatSickAnim{
    alien_eat_sick_0, //mouth closed
    alien_eat_sick_1, //mouth closed
    1000,
    1000,
    1,
    0,
    0
};
Animation sickAnim{
    alien_sick_0,
    alien_sick_1,
    700,
    700,
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
Animation runSickAnim{
    alien_running_sick_0,
    alien_running_sick_1,
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

//ACTIONS
void openMouth(){
    if(alien.getHealth()>SICK_HEALTH) alien.setSprite(eatAnim.frame1);
    else alien.setSprite(eatSickAnim.frame1);
}  
void closeMouth(){
    if(alien.getHealth()>SICK_HEALTH) alien.setSprite(eatAnim.frame0);
    else alien.setSprite(eatSickAnim.frame0);
}

void doRun(unsigned long currentTime){
    if(alien.getHealth()>SICK_HEALTH)doAnimation(currentTime, runAnim);
    else doAnimation(currentTime, runSickAnim);
}

//IDLES
void sickIdle(unsigned long currentTime){
    doAnimation(currentTime, sickAnim);
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

void doIdle(unsigned long currentTime){
    if(alien.getHealth()>SICK_HEALTH){
        doBlink(currentTime);
    }else sickIdle(currentTime);
}

void doSleep(unsigned long currentTime){
    if(alien.getHealth()>SICK_HEALTH) alien.setSprite(alien_right_blink);
    else alien.setSprite(alien_sick_0);
};

void doPoke(unsigned long currentTime){
    if(alien.getHealth()>SICK_HEALTH && alien.getHappy()>50) doAnimation(currentTime, happyAnim);
};

