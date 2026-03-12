#pragma once
#include <cstdint>

enum SPRITE_STATE{ 
  STATE_IDLE,
  STATE_EAT,
  STATE_SLEEP,
  STATE_EXCERCISE
};
struct littleGuy {
    SPRITE_STATE state;
    int x;
    int y;
    const uint16_t* sprite;
    int full; //out of 100
    int happy; //out of 100
    int energy; //out of 100

    int getFull();
    void plusFull(int amount);
    void minusFull(int amount);

    int getHappy();
    void plusHappy(int amount);
    void minusHappy(int amount);

    int getEnergy();
    void plusEnergy(int amount);
    void minusEnergy(int amount);

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