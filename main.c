#include"core.h"

// SDL Variables
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *screen;

TTF_Font *font;

/*
*	Initializes SDL and all SDL extension libraries
*/
void initSDL()
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Game Window",
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  DEFAULT_WINDOW_WIDTH,
							  DEFAULT_WINDOW_HEIGHT,
							  0
							 );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);  //<--Check on different graphics cards if should be SDL_RENDERER_ACCELERATED
	screen = SDL_GetWindowSurface(window);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	TTF_Init();
	font = TTF_OpenFont("fonts/c64.ttf", 12);
	
	// Redirect output to log files
	FILE * my_stdout = freopen ("logs/my_stdout.txt", "wt" /*or "wt"*/, stdout);
	FILE * my_stderr = freopen ("logs/my_stderr.txt", "wb" /*or "wt"*/, stderr);
}

void closeSDL()
{
	TTF_CloseFont(font);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{
	initGame();
	runGame();
	
	
	return 0;
}










