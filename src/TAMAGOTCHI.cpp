#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include "actions.h"
#include "sprites.h" // alien sprite data
#include "backgrounds.h"
#include "icons.h" //menu icon data
#include "buttons.h"
#include "constants.h"


#define DC_PIN   2
#define CS_PIN   5   
#define RST_PIN  4

// Color definitions
#define BLACK 0x0000

// Initialize using Hardware SPI 
Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN, DC_PIN, RST_PIN);
int center_x(int width){
  return (SCREEN_WIDTH - width)/2;
}
int center_y(int height){
  return (SCREEN_HEIGHT - height)/2;  
}

const int INIT_SPRITE_Y_LOC = center_y(SPRITE_HEIGHT);
int SPRITE_Y_LOC = INIT_SPRITE_Y_LOC;
int SPRITE_X_LOC = center_x(SPRITE_WIDTH);


const uint16_t* currentSprite;
enum SPRITE_STATE{ 
  STATE_IDLE,
  STATE_EAT,
  STATE_SLEEP,
  STATE_EXCERCISE

};
SPRITE_STATE currentState;
//this is a buffer
GFXcanvas16 canvas(SCREEN_WIDTH, SCREEN_HEIGHT);
void drawMenu();
void moveLeft();
void moveRight();
void select();
void setup(void) {
  Serial.begin(115200); // Use 115200 for ESP32

  //input pin will be HIGH when the switch is open and LOW when the switch is closed
  setupButtons(3);
  Serial.println("Tamagotchi Booting...");
  
  tft.begin();
  tft.fillScreen(BLACK);
  currentSprite = alien_right_open;
  tft.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Parameters: (x, y, data, width, height)
  tft.drawRGBBitmap(SPRITE_X_LOC, SPRITE_Y_LOC, currentSprite, SPRITE_WIDTH, SPRITE_HEIGHT);
  drawMenu();
  Serial.println("Pet rendered!");
}

int yOffset=0;
unsigned long lastFrameTime=0;
void loop() {  

  unsigned long currentTime = millis();
  checkButtons(currentTime, 3);
  
  switch (currentState)
    {
      case STATE_IDLE:
        blink_idle(currentTime);
    }
  
  //DRAW SPRITE
  if(currentTime - lastFrameTime > FRAME_RATE){
    lastFrameTime = currentTime;
    float jiggle = sin(currentTime * 0.004) * 3; //+-  2 pixels
    // redraw background (to buffer)
    canvas.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);

    SPRITE_Y_LOC = INIT_SPRITE_Y_LOC + (int)jiggle;
    //redraw sprite (to buffer)
    canvas.drawRGBBitmap(SPRITE_X_LOC, SPRITE_Y_LOC, currentSprite, SPRITE_WIDTH, SPRITE_HEIGHT);
    //push buffer to screen
    tft.drawRGBBitmap(0, 0, canvas.getBuffer(), SCREEN_WIDTH, SCREEN_HEIGHT - ICON_SIZE);
  }
}


Button userButtons[] = {
{26, "LEFT", moveLeft, 0, HIGH, HIGH},
{27, "RIGHT", moveRight, 0, HIGH, HIGH},
{12, "SELECT", select, 0, HIGH, HIGH}  
};
void doPoke(){
  Serial.println("Poke!");
}

void doSleep(){
  Serial.println("Sleep!");
}

void doEat(){
  Serial.println("Eat!");
}

void doExcercise(){
  Serial.println("Excercise!");
}

//MENU
int menuIndex = 0;
const int menuSize = 4;

struct menuItem {
  const char* ActionName;
  void (*action)();
  const uint16_t* icon;
  const uint16_t* icon_pressed;
  };
  
void moveLeft(){
   drawMenu();
   Serial.println("Left Button");
   menuIndex = (menuIndex > 1)? (menuIndex-1) : 3;
}
void moveRight(){
  drawMenu();
  Serial.println("Right Button pressed!");
   menuIndex = (menuIndex <3)? (menuIndex+1) : 0;

}
void select(){
  Serial.println("Select Button pressed!");
}
  
const menuItem menuItems[] = {
  {"IDLE", doPoke, nullptr, nullptr},
  {"EAT", doEat, eat_icon, eat_icon_pressed},
  {"SLEEP", doSleep, sleep_icon, sleep_icon_pressed},
  {"EXCERCISE", doExcercise, excercise_icon, excercise_icon_pressed}
};
  
void drawMenu() {
    int spacing = 30;

    for (int i = 1; i < menuSize; i++) {

        int x = center_x(ICON_SIZE) + (i - 2) * spacing; //X location

        const uint16_t* iconToDraw =
            (menuIndex == i) 
                ? menuItems[i].icon_pressed 
                : menuItems[i].icon;

        tft.drawRGBBitmap(x, SCREEN_HEIGHT - ICON_SIZE, iconToDraw, ICON_SIZE, ICON_SIZE);
    }
}
