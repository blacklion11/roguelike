#include"core.h"
#include"player.h"

// SDL Variables
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Surface *screen;

SDL_Color fgColor = {255, 255, 255};
SDL_Color bgColor = {0, 0, 0};
extern TTF_Font *font;
SDL_Rect txtLoc = {10, 10, 500, 50};

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
	
	
	SDL_Surface *txtSurface = TTF_RenderText_Shaded(font, "This is my text.", fgColor, bgColor);
	
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
		
		//Display Debug Information
		txtSurface = TTF_RenderText_Shaded(font, "This is my text.", fgColor, bgColor);
		SDL_BlitSurface(txtSurface, NULL, screen, &txtLoc);
	}
	
	SDL_FreeSurface(txtSurface);
	closeGame();
}

void closeGame()
{
	closeSDL();
}