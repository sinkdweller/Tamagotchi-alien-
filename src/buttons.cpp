#include "buttons.h"

void setupButtons(int num){
  Serial.println("Setting up Buttons");
  for (int i = 0; i < num; i++){
    pinMode(userButtons[i].pinNumber, INPUT_PULLUP); // built-in pull-up resistor
  }  
}
const int debounceTime = 50;
void checkButtons(unsigned long currentTime, int num){
  for (int i = 0; i < num; i++){
    Button &button = userButtons[i];
    bool buttonState = digitalRead(button.pinNumber);
    
    //if switch changed due to noise
    if(buttonState!=button.lastState){
      button.lastTime = currentTime;
    }
    //Not a flicker reaction
    if(currentTime - button.lastTime > debounceTime){
      //button state changed after a stable time 
      if(buttonState!= button.lastConfirmedState){
        button.lastConfirmedState = buttonState;
        if(buttonState==LOW){
          button.action();
        }
        button.lastTime = currentTime;
        }
    }
     button.lastState = buttonState;

    
  }
  
  
}
