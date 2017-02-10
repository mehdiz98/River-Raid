#include "gameobjects.h"

GameObjects::GameObjects()
{
    //set random x position
    int random_number = (rand() % 400) + 150;
    setPos(random_number,0);
}

void GameObjects::stop()
{
    timer->stop();
}
