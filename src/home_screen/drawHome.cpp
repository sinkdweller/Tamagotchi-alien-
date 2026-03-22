#include "drawHome.h"
void drawBar(int x, int y, int barWidth, int barHeight, int statValue) {
    //int barWidth = 40;
    //int barHeight = 8;
    int maxStatValue = 100;

    // Draw the outline/background
    canvas.drawRect(x, y, barWidth, barHeight, 0xFFFF); // White border

    // Calculate fill width
    int fillWidth = map(statValue, 0, maxStatValue, 0, barWidth - 2);

    // Choose color based on how hungry the pet is
    uint16_t barColor = 0x07E0; // Green
    if (statValue < 30) barColor = 0xF800; // Red if starving

    // Draw the fill
    canvas.fillRect(x + 1, y + 1, fillWidth, barHeight - 2, barColor);
}
void drawBackground(){
  canvas.drawRGBBitmap(0, 0, alien_home, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void drawFood(){
  renderActiveItems();
}

int yOffset=0;
unsigned long lastFrameTime=0;
void drawHome(int currentTime){
  if(currentTime - lastFrameTime > FRAME_RATE){
    lastFrameTime = currentTime;
    float jiggle = sin(currentTime * 0.004) * 3; //+-  2 pixels


    alien.setY(center_y(SPRITE_HEIGHT) + (int)jiggle);
    //redraw TRANSPARENT sprite (to buffer)
    alien.drawGuy();
    //push buffer to screen
    tft.drawRGBBitmap(0, 0, canvas.getBuffer(), SCREEN_WIDTH, SCREEN_HEIGHT - ICON_SIZE);
  }
}