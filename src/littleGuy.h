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
struct Stats{
  int full;
  int happy;
  int energy;
  int annoy;
  int health;
};

struct littleGuy {
    SPRITE_STATE state;
    int x;
    int y;
    const uint16_t* sprite;
    Stats stats;
   
    Emote* currentEmote;

    littleGuy(
      SPRITE_STATE state,
      int x,
      int y,
      const uint16_t* sprite
    );
    bool isSick;

    void drawEmote(int x, int y);
    void setEmote(Emote* newEmote);

    void drawGuy();

    int getX();
    int getY();
    int setXY(int x, int y);
    void setX(int x);
    void setY(int y);
    const uint16_t* getSprite();
    void setState(SPRITE_STATE s);
    void setSprite(const uint16_t* s);
    SPRITE_STATE getState();
    //STATS DECAY METHOD
    void updateStats(unsigned long deltaMs);

    float fullRate;
    float happyRate;
    float energyRate;
    float annoyRate;

    void setFullRate(float amount);
    void setHappyRate(float amount);
    void setEnergyRate(float amount);
    void setAnnoyRate(float amount);
    //STATS GETTERS/SETTERS
    int getAnnoy(); 
    void plusAnnoy(float amount);

    int getFull();
    void plusFull(float amount);

    int getHappy();
    void plusHappy(float amount);

    int getEnergy();
    void plusEnergy(float amount);

    int getHealth();
    void plusHealth(float amount);
    void setHealth(int health);
    
};

littleGuy& getPet();