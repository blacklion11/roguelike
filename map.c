#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include"map.h"


extern SDL_Window *window;
//extern SDL_Renderer *renderer;
extern SDL_Surface *screen;

void initMap(Map *map)
{
    int width = map->width;
    int height = map->height;

    map->tiles = (char***) malloc(width * sizeof(char***));
    
    int i,j;
    for(i = 0; i < width; i++)
    {
        map->tiles[i] = (char**) malloc(height * sizeof(char**));
    }

    for(i = 0; i < width; i++)
    {
        for(j = 0; j < height; j++)
        {
            map->tiles[i][j] = (char*) malloc(sizeof(char*));
        }
    }
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Int Testing/////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	map->intTiles = (int**) malloc(width * sizeof(int**));
    
    for(i = 0; i < width; i++)
    {
        map->intTiles[i] = (int*) malloc(height * sizeof(int*));
    }

    for(i = 0; i < width; i++)
    {
        for(j = 0; j < height; j++)
        {
            map->intTiles[i][j] = (int) malloc(sizeof(int));
        }
    }
	/////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
}



void fillMap(Map *map, char *token)
{
    int i,j;
    for(i = 0; i < map->width; i++)
    {
        for(j = 0; j < map->height; j++)
        {
            map->tiles[i][j] = token;
        }
    }
}

void renderMap(SDL_Renderer *renderer, Map *map)
{	
	SDL_Rect *tile = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	tile->w = tile->h = 12;
	int i,j;
	for(i = 0; i < map->width; i++)
	{
		for(j = 0; j < map->height; j++)
		{
			switch(map->intTiles[i][j])
			{
				case 1:
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
					break;
				case 2:
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
					break;
				case 3:
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
					break;
				case 4:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					break;
				case 5:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					break;
				case 6:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					break;
				case 7:
					SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
					break;
				case 8:
					SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
					break;
				case 9:
					SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
					break;
				case 10:
					SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
					break;
			}
			tile->x = i * 12;
			tile->y = j * 12;
			SDL_RenderFillRect(renderer, tile);
		}
	}
	SDL_RenderPresent(renderer);
	
	free(tile);
}

void printMap(Map *map)
{
    int i,j;
    for(i = 0; i < map->width; i++)
    {
        for(j = 0; j < map->height; j++)
        {
            //printf("%s ",map->tiles[i][j]);
			printf("%d ", map->intTiles[i][j]);
		}
        printf("\n");
    }
	
	printf("\n");
	printf("\n");
	
	for(i = 0; i < map->width; i++)
    {
        for(j = 0; j < map->height; j++)
        {
            printf("%s ",map->tiles[i][j]);
			//printf("%d ", map->intTiles[i][j]);
		}
        printf("\n");
    }
}
