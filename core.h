#ifndef CORE_H
#define CORE_H

	#include<stdio.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include<SDL2/SDL.h>
	#include<SDL2/SDL_ttf.h>
	
	#include"input.h"
	
	
	void initSDL(int, int);
	void closeSDL();
	
	void initGame();
	void runGame();
	void closeGame();

#endif
