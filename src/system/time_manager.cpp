
#include "time_manager.h"
#include <Arduino.h>
#include "constants.h"
//REAL TIME FOR ANIMATIONS, BUTTONS, UI, etc.
unsigned long getTime(){
    return millis();
}
//SYSTEM TIME: DECAY, ETC.
unsigned long getSystemTime(){
    return millis() * TIME_SCALE;
}
// void setTimeScale(float scale){
//     timeScale = scale;
// }