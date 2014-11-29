#ifndef CORE_H
#define CORE_H

	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include<SDL2/SDL.h>
	#include<SDL2/SDL_ttf.h>
	#include<SDL2/SDL_image.h>
	
	#include"input.h"
	#include"world.h"
	
	#define DEFAULT_WINDOW_WIDTH 1366
	#define DEFAULT_WINDOW_HEIGHT 768
	
	
	void initSDL();
	void closeSDL();
	
	void initGame();
	void runGame();
	void closeGame();

#endif
