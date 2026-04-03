// tamagotchi.cpp
#include "littleGuy.h"

littleGuy::littleGuy(
    SPRITE_STATE state,
    int x,
    int y,
    const uint16_t* sprite,
    int health
){
    this->x = x;
    this->y = y;
    this->state = state;
    this->sprite = sprite;
    this->health = health; //out of 100

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
int littleGuy::getHealth(){return health;}
void littleGuy::setHealth(int health){health = health; }
const uint16_t* littleGuy::getSprite(){return sprite;}

void littleGuy::decayStats(unsigned long deltaMs){
    float dt = deltaMs/1000.0f; //time in seconds
    stats.happy -= dt*0.001; //approx 100/ day
    stats.full -= dt*0.001;
    stats.energy -= dt*0.001;
    stats.annoy -= dt*1;
    
}
int littleGuy::getFull(){return stats.full;}
int littleGuy::getHappy(){return stats.happy;}
int littleGuy::getEnergy(){return stats.energy;}
int littleGuy::getAnnoy(){return stats.annoy;}

void littleGuy::plusHappy(int amount) {
    stats.happy += amount;
    if (stats.happy > 100) stats.happy = 100;
}

void littleGuy::minusHappy(int amount) {
    stats.happy -= amount;
    if (stats.happy < 0) stats.happy = 0;
}

void littleGuy::plusEnergy(int amount){
    stats.energy += amount;
    if(stats.energy > 100) stats.energy = 100;
}
void littleGuy::minusEnergy(int amount){
    stats.energy += amount;
    if(stats.energy < 0) stats.energy = 0;
}

void littleGuy::plusFull(int amount){
    stats.full+=amount;
    if(stats.full>100) stats.full = 100;
}
void littleGuy::minusFull(int amount){
    stats.full -= amount;
    if(stats.full < 0) stats.full = 0;
}

void littleGuy::plusAnnoy(int amount){
    stats.annoy += amount;
    if(stats.annoy > 100) stats.annoy = 100;
}

void littleGuy::minusAnnoy(int amount){
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