#ifndef PLAYER_H
#define PLAYER_H
	
	#include<stdint.h>

	// Task Mappings
	const int PLAYER_MOVE = 1;
	
	typedef struct Player
	{
		int x, y, w, h;
		char *name;
		int health;
		float moveSpeed;
		int currentTask;
	}Player;

	void movePlayerXY(int32_t, int32_t);

#endif