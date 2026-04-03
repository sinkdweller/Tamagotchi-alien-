// tamagotchi.cpp
#include "littleGuy.h"

littleGuy::littleGuy(
    SPRITE_STATE state,
    int x,
    int y,
    const uint16_t* sprite
){
    this->x = x;
    this->y = y;
    this->state = state;
    this->sprite = sprite;
    this-> isSick = false;
    stats.health = 100; 
    stats.full = 50;
    stats.happy = 50;
    stats.energy = 50;
    stats.annoy = 0;
}


SPRITE_STATE littleGuy::getState(){return state;}
void littleGuy::setState(SPRITE_STATE s) { state = s; }
void littleGuy::setSprite(const uint16_t* s) { sprite = s; }
void littleGuy::setX(int newX){ x = newX;}
void littleGuy::setY(int newY){ y = newY;}
int littleGuy::getX(){return x;}
int littleGuy::getY(){return y;}
int littleGuy::getHealth(){return stats.health;}
void littleGuy::setHealth(int newHealth){stats.health = newHealth; }
const uint16_t* littleGuy::getSprite(){return sprite;}

void littleGuy::decayStats(unsigned long deltaMs){
    float dt = deltaMs/1000.0f; //time in seconds
    minusHappy(dt*0.001); //approx 100/ day
    minusFull(dt*0.001);
    minusEnergy(dt*0.001);
    minusAnnoy(dt*1);

    if(stats.full < 10) minusHealth(dt*0.001);
    if(stats.happy < 10) minusHealth(dt*0.001);
    if(stats.health < 50) isSick = true;

}
int littleGuy::getFull(){return (int) stats.full;}
int littleGuy::getHappy(){return  (int) stats.happy;}
int littleGuy::getEnergy(){return  (int) stats.energy;}
int littleGuy::getAnnoy(){return  (int) stats.annoy;}

void littleGuy::plusHealth(float amount) {
    stats.health += amount;
    if (stats.health > 100) stats.health = 100;
}

void littleGuy::minusHealth(float amount) {
    stats.health -= amount;
    if (stats.health < 0) stats.health = 0;
}

void littleGuy::plusHappy(float amount) {
    stats.happy += amount;
    if (stats.happy > 100) stats.happy = 100;
}

void littleGuy::minusHappy(float amount) {
    stats.happy -= amount;
    if (stats.happy < 0) stats.happy = 0;
}

void littleGuy::plusEnergy(float amount){
    stats.energy += amount;
    if(stats.energy > 100) stats.energy = 100;
}
void littleGuy::minusEnergy(float amount){
    stats.energy -= amount;
    if(stats.energy < 0) stats.energy = 0;
}

void littleGuy::plusFull(float amount){
    stats.full+=amount;
    if(stats.full>100) stats.full = 100;
}
void littleGuy::minusFull(float amount){
    stats.full -= amount;
    if(stats.full < 0) stats.full = 0;
}

void littleGuy::plusAnnoy(float amount){
    stats.annoy += amount;
    if(stats.annoy > 100) stats.annoy = 100;
}

void littleGuy::minusAnnoy(float amount){
    stats.annoy -= amount;
    if(stats.annoy < 0) stats.annoy = 0;
}

void littleGuy::setEmote(Emote* newEmote){
    currentEmote = newEmote;
}

void littleGuy::drawEmote(int x, int y) {

    if (currentEmote == nullptr) return;

    drawSpriteTransparent(
        x,
        y,
        currentEmote->sprite,
        20,
        20
    );
}

void littleGuy::drawGuy(){
    drawSpriteTransparent(x, y, sprite, SPRITE_WIDTH, SPRITE_HEIGHT);
    //draw active EMOTE (top left corner)
    drawEmote(x+10, y+10);
}