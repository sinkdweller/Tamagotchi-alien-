
#include "time_manager.h"
#include <Arduino.h>

float timeScale = 1;
unsigned long getTime(){
    return millis() * timeScale;
}
void setTimeScale(float scale){
    timeScale = scale;
}