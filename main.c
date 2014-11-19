#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<stdbool.h>


typedef struct Man
{
	int x, y;
	short life;
	char *name;
}Man;


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//SDL Stuff
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

// Boolean to test if the window is exited out
bool quit = false;


void initSDL()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Game Window",
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  SCREEN_WIDTH,
							  SCREEN_HEIGHT,
							  0
							 );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	surface = SDL_GetWindowSurface(window);
}

void closeSDL()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	initSDL();
	
	
	
	closeSDL();
	return 0;
}










