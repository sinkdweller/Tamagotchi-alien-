// tamagotchi.cpp
#include "littleGuy.h"

static littleGuy pet; 

littleGuy& getPet() { return pet; }

SPRITE_STATE littleGuy::getState(){return state;}
void littleGuy::setState(SPRITE_STATE s) { state = s; }
void littleGuy::setSprite(const uint16_t* s) { sprite = s; }
void littleGuy::setX(int newX){ this->x = newX;}
void littleGuy::setY(int newY){ this->y = newY;}
int littleGuy::getX(){return x;}
int littleGuy::getY(){return y;}
const uint16_t* littleGuy::getSprite(){return sprite;}
int littleGuy::getFull(){return full;}
int littleGuy::getHappy(){return happy;}
int littleGuy::getEnergy(){return energy;}

void littleGuy::plusHappy(int amount) {
    happy += amount;
    if (happy > 100) happy = 100;
}

void littleGuy::minusHappy(int amount) {
    happy -= amount;
    if (happy < 0) happy = 0;
}
void littleGuy::plusEnergy(int amount){
    energy += amount;
    if(energy > 100) energy = 100;
}
void littleGuy::minusEnergy(int amount){
    energy += amount;
    if(energy < 0) energy = 0;
}
void littleGuy::plusFull(int amount){
    full+=amount;
    if(full>100) full = 100;
}
void littleGuy::minusFull(int amount){
    full -= amount;
    if(full < 0) full = 0;
}