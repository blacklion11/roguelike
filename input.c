#include"core.h"
#include"player.h"


//SDL Event variable
SDL_Event e;

//Player variable
extern Player player;

int getInput()
{
	if(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_QUIT:
				return -1;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return -1;
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
	return 0;
}