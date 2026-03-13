#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include "animatables/actions.h"
#include "animatables/foods.h"
#include "sprites.h" // alien sprite data
#include "backgrounds.h"
#include "icons.h" //menu icon data
#include "buttons.h"
#include "home_screen/menu.h"
#include "constants.h"
#include "utils.h"
#include "littleGuy.h"
#include "home_screen/drawHome.h"
#include "globals.h"
#define DC_PIN   2
#define CS_PIN   5   
#define RST_PIN  4

// Color definitions
#define BLACK 0x0000

// Initialize using Hardware SPI 
Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN, DC_PIN, RST_PIN);


GFXcanvas16 canvas(SCREEN_WIDTH, SCREEN_HEIGHT);
SPRITE_STATE currentState;
littleGuy alien;
void setup(void) {
  Serial.begin(115200); // Use 115200 for ESP32

  //input pin will be HIGH when the switch is open and LOW when the switch is closed
  setupButtons(3);
  Serial.println("Tamagotchi Booting...");
  
  tft.begin();
  tft.fillScreen(BLACK);
  alien = {STATE_IDLE, center_y(SPRITE_HEIGHT), center_x(SPRITE_WIDTH), alien_right_open, 50, 50, 50};
  tft.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Parameters: (x, y, data, width, height)
  tft.drawRGBBitmap(alien.getX(), alien.getY(), alien.getSprite(), SPRITE_WIDTH, SPRITE_HEIGHT);
  drawMenu();
  Serial.println("Pet rendered!");
}

enum SCREENS {
  HOME_SCREEN,
  STAT_SCEEN
};
SCREENS currentScreen = HOME_SCREEN;

void loop() {  

  unsigned long currentTime = millis();
  int pressedButton = checkButtons(currentTime, 3);
  switch(currentScreen){

    case(HOME_SCREEN):
      if(pressedButton == 0) shiftMenuLeft();
      if(pressedButton == 1) shiftMenuRight();
      if(pressedButton == 2) selectMenu();
      
      switch (alien.getState())
      {
      case STATE_IDLE:
        doBlink(currentTime);
        break;
      case STATE_EAT: {
        if (pressedButton == 2 && (currentlyFlying == nullptr || !currentlyFlying->active)) {
                currentlyFlying = &getRandomFood(); 
          }

            if (currentlyFlying != nullptr && currentlyFlying->active) {
                // flyLeftToCenter handles the timer and moves the X
                currentlyFlying->flyLeftToCenter(currentTime);
            }

        doEat(currentTime, (pressedButton == 2)); 
        break;

      }
      case STATE_EXCERCISE:
        doRun(currentTime);
        break;
      }

      //draws Alien and home
      drawHome(currentTime);

      break;
  }

  
}
