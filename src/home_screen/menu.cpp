#include "menu.h"


static int menuIndex = 0;
static const int menuSize = 4;
struct menuItem {
  const char* ActionName;
  void (*action)();
  const uint16_t* icon;
  const uint16_t* icon_pressed;
};
const menuItem menuItems[] = {
  {"IDLE", switchIdle, nullptr, nullptr},
  {"EAT", switchEat, eat_icon, eat_icon_pressed},
  {"SLEEP", switchSleep, sleep_icon, sleep_icon_pressed},
  {"EXCERCISE", switchExcercise, excercise_icon, excercise_icon_pressed}
};

void switchIdle(){
    alien.setState(STATE_IDLE);
}
void switchEat(){
    alien.setState(STATE_EAT);
}
void switchSleep(){
    alien.setState(STATE_SLEEP);
}
void switchExcercise(){
    alien.setState(STATE_EXCERCISE);
}
void shiftMenuLeft(){
   menuIndex = (menuIndex > 0)? (menuIndex-1) : 3;
   drawMenu(); //refresh ui
   
}
void shiftMenuRight(){
   menuIndex = (menuIndex <3)? (menuIndex+1) : 0;
   drawMenu(); //refresh ui

}
void selectMenu(){
    menuItems[menuIndex].action();

    drawMenu();
}


void drawMenu() {
    int spacing = 30;

    for (int i = 1; i < menuSize; i++) {

        int x = center_x(ICON_SIZE) + (i - 2) * spacing; //X location

        const uint16_t* iconToDraw =
            (menuIndex == i) 
                ? menuItems[i].icon_pressed 
                : menuItems[i].icon;

        tft.drawRGBBitmap(x, SCREEN_HEIGHT - ICON_SIZE, iconToDraw, ICON_SIZE, ICON_SIZE);
    }
}
