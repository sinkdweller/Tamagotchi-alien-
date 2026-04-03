
#include "time_manager.h"
#include <Arduino.h>
#include "constants.h"
unsigned long getTime(){
    return millis() * TIME_SCALE;
}
// void setTimeScale(float scale){
//     timeScale = scale;
// }