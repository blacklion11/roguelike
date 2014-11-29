#ifndef MAP_H
#define MAP_H

#include<SDL2/SDL.h>

typedef struct Map
{
	int seed;
    int width;
    int height;
    char*** tiles;
	int** intTiles;
}Map;

void initMap(Map *);
void printMap(Map *);
void fillMap(Map *,char *);
void renderMap(SDL_Renderer *, Map *);

#endif
