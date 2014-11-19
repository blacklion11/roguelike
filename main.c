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
SDL_Event event;

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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void closeSDL()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	initSDL();

	
	SDL_Rect player;
	player.x = 10;
	player.y = 10;
	player.w = 30;
	player.h = 30;
	
	while(!quit)
	{
		if(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							quit = true;
							break;
						case SDLK_LEFT:
							player.x -= 10;
							break;
						case SDLK_RIGHT:
							player.x += 10;
							break;
						case SDLK_UP:
							player.y -= 10;
							break;
						case SDLK_DOWN:
							player.y += 10;
							break;
					}
					break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &player);
		SDL_RenderPresent(renderer);
	}
	
	closeSDL();
	return 0;
}










