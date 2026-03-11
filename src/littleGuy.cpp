// tamagotchi.cpp
#include "littleGuy.h"

static littleGuy pet; 

littleGuy& getPet() { return pet; }

void littleGuy::setState(SPRITE_STATE s) { state = s; }
SPRITE_STATE littleGuy::getState(){return state;}
void littleGuy::setSprite(const uint16_t* s) { sprite = s; }
void littleGuy::setX(int newX){ this->x = newX;}
void littleGuy::setY(int newY){ this->y = newY;}
int littleGuy::getX(){return x;}
int littleGuy::getY(){return y;}
const uint16_t* littleGuy::getSprite(){return sprite;}