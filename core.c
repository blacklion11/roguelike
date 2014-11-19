#include"core.h"
#include"player.h"

// SDL Variables
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Surface *screen;

//System Running Variables
bool running = true;

//Player variable
Player player;

void initGame()
{
	initSDL(640, 480);
}

void runGame()
{
	player.x = player.y = player.w = player.h = 50;
	player.name = "Mike";
	player.moveSpeed = 2.0f;
	
	while(running)
	{
		//Get Input
		if(getInput() == -1)
		{
			running = false;
		}
		
		
		//Update
		
		
		//Render
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_Rect rect;
		rect.x = player.x;
		rect.y = player.y;
		rect.w = player.w;
		rect.h = player.h;
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}
	
	
	closeGame();
}

void closeGame()
{
	closeSDL();
}