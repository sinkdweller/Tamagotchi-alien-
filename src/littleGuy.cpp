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

    this->fullRate = -0.001;
    this->energyRate = -0.001;
    this->happyRate = -0.001;
    this->annoyRate = -1;
    this->healthRate = 0;
}


SPRITE_STATE littleGuy::getState(){return state;}
void littleGuy::setState(SPRITE_STATE s) { state = s; }
void littleGuy::setSprite(const uint16_t* s) { sprite = s; }
void littleGuy::setX(int newX){ x = newX;}
void littleGuy::setY(int newY){ y = newY;}
int littleGuy::getX(){return x;}
int littleGuy::getY(){return y;}
float littleGuy::getHealth(){return stats.health;}
void littleGuy::setHealth(int newHealth){stats.health = newHealth; }
const uint16_t* littleGuy::getSprite(){return sprite;}

void littleGuy::updateStats(unsigned long deltaMs){
    float dt = deltaMs/1000.0f; //time in seconds
    plusHappy(dt*happyRate); //approx 100/ day
    plusFull(dt*fullRate);
    plusEnergy(dt*energyRate);
    plusAnnoy(dt*annoyRate);
    plusHealth(dt*healthRate);

    if(stats.full < 10) plusHealth(dt*-0.001);
    if(stats.happy < 10) plusHealth(dt*-0.001);
    if(stats.health < 50) isSick = true;

}
void littleGuy::setFullRate(float amount){fullRate = amount;}
void littleGuy::setHappyRate(float amount){happyRate = amount;}
void littleGuy::setEnergyRate(float amount){energyRate = amount;}
void littleGuy::setAnnoyRate(float amount){annoyRate = amount;}
void littleGuy::setHealthRate(float amount){healthRate = amount;}

float littleGuy::getFull(){return stats.full;}
float littleGuy::getHappy(){return  stats.happy;}
float littleGuy::getEnergy(){return  stats.energy;}
float littleGuy::getAnnoy(){return  stats.annoy;}

void littleGuy::plusHealth(float amount) {
    stats.health += amount;
    if (stats.health > 100) stats.health = 100;
    if(stats.health < 0) stats.health = 0;
}

void littleGuy::plusHappy(float amount) {
    stats.happy += amount;
    if (stats.happy > 100) stats.happy = 100;
    if (stats.happy < 0) stats.happy = 0;
}


void littleGuy::plusEnergy(float amount){
    stats.energy += amount;
    if(stats.energy > 100) stats.energy = 100;
    if(stats.energy < 0) stats.energy = 0;

}


void littleGuy::plusFull(float amount){
    stats.full+=amount;
    if(stats.full>100) stats.full = 100;
    if(stats.full < 0) stats.full = 0;

}

void littleGuy::plusAnnoy(float amount){
    stats.annoy += amount;
    if(stats.annoy > 100) stats.annoy = 100;
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