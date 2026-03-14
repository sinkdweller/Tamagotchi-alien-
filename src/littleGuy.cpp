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

    lastAnnoyDecayTime = 0;
    lastHappyDecayTime = 0;
    lastFullDecayTime = 0;
    lastEnergyDecayTime = 0;

    full = 50;
    happy = 50;
    energy = 50;
    annoy = 0;
}


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
int littleGuy::getAnnoy(){return annoy;}

void littleGuy::plusHappy(int amount) {
    happy += amount;
    if (happy > 100) happy = 100;
}

void littleGuy::minusHappy(int amount) {
    happy -= amount;
    if (happy < 0) happy = 0;
}
void littleGuy::decayHappy(unsigned long currentTime){
    if(currentTime - lastHappyDecayTime>1000){
        minusEnergy(5);
    }
};
void littleGuy::plusEnergy(int amount){
    energy += amount;
    if(energy > 100) energy = 100;
}
void littleGuy::minusEnergy(int amount){
    energy += amount;
    if(energy < 0) energy = 0;
}
void littleGuy::decayEnergy(unsigned long currentTime){
    if(currentTime - lastEnergyDecayTime>1000){
        minusEnergy(5);
    }
};
void littleGuy::plusFull(int amount){
    full+=amount;
    if(full>100) full = 100;
}
void littleGuy::minusFull(int amount){
    full -= amount;
    if(full < 0) full = 0;
}
void littleGuy::decayFull(unsigned long currentTime){
    if(currentTime - lastFullDecayTime>1000){
        minusFull(5);
    }
};
void littleGuy::plusAnnoy(int amount){
    annoy += amount;
    if(annoy > 100) annoy = 100;
}

void littleGuy::minusAnnoy(int amount){
    annoy -= amount;
    if(annoy < 0) annoy = 0;
}
void littleGuy::decayAnnoy(unsigned long currentTime, int annoyAmount){
    if(currentTime - lastAnnoyDecayTime>1000){
        minusAnnoy(annoyAmount);
    }
};
void littleGuy::setEmote(Emote& newEmote){
    currentEmote = &newEmote;
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