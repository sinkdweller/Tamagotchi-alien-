#pragma once
#include <cstdint>
#include "utils.h"
#include "animatables/emote.h"
enum SPRITE_STATE{ 
  STATE_IDLE,
  STATE_EAT,
  STATE_SLEEP,
  STATE_EXCERCISE
};
struct littleGuy {
    SPRITE_STATE state;
    int health;
    int x;
    int y;
    const uint16_t* sprite;
    int full; //out of 100
    int happy; //out of 100
    int energy; //out of 100
    int annoy;
    unsigned long lastAnnoyDecayTime;
    unsigned long lastHappyDecayTime;
    unsigned long lastFullDecayTime;
    unsigned long lastEnergyDecayTime;

   
    Emote* currentEmote;

    littleGuy(
      SPRITE_STATE state,
      int x,
      int y,
      const uint16_t* sprite,
      int health
    );


    void drawEmote(int x, int y);
    void setEmote(Emote* newEmote);

    void drawGuy();

    int getAnnoy(); 
    void plusAnnoy(int amount);
    void minusAnnoy(int amount);
    void decayAnnoy(unsigned long currentTime,int annoyAmount);

    int getFull();
    void plusFull(int amount);
    void minusFull(int amount);
    void decayFull(unsigned long currentTime);

    int getHappy();
    void plusHappy(int amount);
    void minusHappy(int amount);
    void decayHappy(unsigned long currentTime);

    int getEnergy();
    void plusEnergy(int amount);
    void minusEnergy(int amount);
    void decayEnergy(unsigned long currentTime);

    int getHealth();
    void setHealth(int health);
    int getX();
    int getY();
    int setXY(int x, int y);
    void setX(int x);
    void setY(int y);
    const uint16_t* getSprite();
    void setState(SPRITE_STATE s);
    void setSprite(const uint16_t* s);
    SPRITE_STATE getState();
};

littleGuy& getPet();