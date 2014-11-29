#ifndef WORLD_H
#define WORLD_H

#include<SDL2/SDL.h>
#include"map.h"

typedef struct World
{
    int size;
    Map map;
}World;


void initWorld();
void generateWorld();
void renderWorld(SDL_Renderer *, World *);



#endif




