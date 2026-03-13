#include "drawHome.h"

int yOffset=0;
unsigned long lastFrameTime=0;
void drawHome(int currentTime){
  if(currentTime - lastFrameTime > FRAME_RATE){
    lastFrameTime = currentTime;
    float jiggle = sin(currentTime * 0.004) * 3; //+-  2 pixels
    // redraw background (to buffer)
    canvas.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderActiveItems();
    alien.setY(center_y(SPRITE_HEIGHT) + (int)jiggle);
    //redraw sprite (to buffer)
    canvas.drawRGBBitmap(alien.getX(), alien.getY(), alien.getSprite(), SPRITE_WIDTH, SPRITE_HEIGHT);
    //push buffer to screen
    tft.drawRGBBitmap(0, 0, canvas.getBuffer(), SCREEN_WIDTH, SCREEN_HEIGHT - ICON_SIZE);
  }
}