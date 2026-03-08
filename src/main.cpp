#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include "actions.h"
#include "sprites.h" // alien sprite data
#include "backgrounds.h"
#include "icons.h" //menu icon data
#include "buttons.h"
#include "constants.h"
#include "utils.h"
#include "littleGuy.h"
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
  alien = {STATE_IDLE, center_y(SPRITE_HEIGHT), center_x(SPRITE_WIDTH), alien_right_open};
  tft.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Parameters: (x, y, data, width, height)
  tft.drawRGBBitmap(alien.getX(), alien.getY(), alien.getSprite(), SPRITE_WIDTH, SPRITE_HEIGHT);
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
        doBlink(currentTime);
    }
  
  //DRAW SPRITE
  if(currentTime - lastFrameTime > FRAME_RATE){
    lastFrameTime = currentTime;
    float jiggle = sin(currentTime * 0.004) * 3; //+-  2 pixels
    // redraw background (to buffer)
    canvas.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);

    alien.setY(center_y(SPRITE_HEIGHT) + (int)jiggle);
    //redraw sprite (to buffer)
    canvas.drawRGBBitmap(alien.getX(), alien.getY(), alien.getSprite(), SPRITE_WIDTH, SPRITE_HEIGHT);
    //push buffer to screen
    tft.drawRGBBitmap(0, 0, canvas.getBuffer(), SCREEN_WIDTH, SCREEN_HEIGHT - ICON_SIZE);
  }
}
