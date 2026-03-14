#include "foods.h"

Food burger = {burger_sprite, 25, SCREEN_WIDTH - 20, center_y(20), 10, 0, true};
Food pill = {pill_sprite, 10, SCREEN_WIDTH-20, center_y(20), 10, 0, true};

Food foodMenu[] = {burger, pill};
const int foodCount = 2;
Food* currentlyFlying = nullptr;
void renderActiveItems() {
    if (currentlyFlying != nullptr && currentlyFlying->active) {
        canvas.drawRGBBitmap(currentlyFlying->x, currentlyFlying->y, currentlyFlying->sprite, 20, 20);
    }
}

Food& getRandomFood() {
    currentlyFlying = nullptr; 

    int randomIndex = random(0, foodCount);
    
    // Reset the chosen food's position before returning it
    foodMenu[randomIndex].x = SCREEN_WIDTH-20;
    foodMenu[randomIndex].active = true;
    foodMenu[randomIndex].lastMoveTime = millis();
    return foodMenu[randomIndex];
}
int Food::flyLeftToCenter(unsigned long currentTime){
    if(currentTime-lastMoveTime>moveInterval) {
        x-=1;
        lastMoveTime = currentTime;
    }
    int sprite_center_x = center_x(20);

    if(x <= sprite_center_x){
        active = false;
        currentlyFlying = nullptr;
        return nutrition;

    }
    return -1; // Still flying
}