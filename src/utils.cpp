#include "utils.h"
int center_x(int width){
  return (SCREEN_WIDTH - width)/2;
}
int center_y(int height){
  return (SCREEN_HEIGHT - height)/2;  
}
void drawSpriteTransparent(int x, int y, const uint16_t* sprite, int w, int h) {
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {

      uint16_t pixel = sprite[row * w + col];

      if (pixel != 0x0000) { // skip black
        canvas.drawPixel(x + col, y + row, pixel);
      }

    }
  }
}