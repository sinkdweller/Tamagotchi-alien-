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
    int health;
    int x;
    int y;
    const uint16_t* sprite;
    Stats stats;
   
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
    void decayStats(unsigned long deltaMs);

    //STATS GETTERS/SETTERS
    int getAnnoy(); 
    void plusAnnoy(int amount);
    void minusAnnoy(int amount);

    int getFull();
    void plusFull(int amount);
    void minusFull(int amount);

    int getHappy();
    void plusHappy(int amount);
    void minusHappy(int amount);

    int getEnergy();
    void plusEnergy(int amount);
    void minusEnergy(int amount);

    int getHealth();
    void setHealth(int health);
    
};

littleGuy& getPet();