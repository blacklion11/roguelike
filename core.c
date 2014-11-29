#include"core.h"
#include"player.h"

/*
* SDL Variables
*/
	// Window pointer
extern SDL_Window *window;
	// Renderer pointer
extern SDL_Renderer *renderer;
	// Window screen pointer (this is the screen actually displayed)
extern SDL_Surface *screen;
	// Surface used for debug information
SDL_Surface *debugScreen;
	// The clear color used on the renderer
SDL_Color clearColor = {0, 0, 0};
	// The color used text
SDL_Color textColor = {255, 255, 255};
	// The TTF font being used
extern TTF_Font *font;

/*
* System Running Variables
*/
bool running = true;


/*
* Player variables
*/
	//The player
Player player;

/*
* World variables
*/
	//The world
World world;


void initGame()
{
	initSDL();
	initWorld();
}

void runGame()
{
	player.x = player.y = 100;
	player.w = player.h = 12;
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
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		
		renderWorld(renderer, &world);
		
		
		//Display Debug Information
		/*
		debugScreen = TTF_RenderText_Solid(font, "This is a test", textColor);
		
		SDL_Texture *temp;
		temp = SDL_CreateTextureFromSurface(renderer, debugScreen);
		SDL_RenderCopy(renderer, temp, NULL, NULL);
		SDL_RenderPresent(renderer);
		
		SDL_DestroyTexture(temp);
		*/
	}
	
	//SDL_FreeSurface(txtSurface);
	closeGame();
}

void closeGame()
{
	closeSDL();
}