#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"world.h"




extern World world;


void initWorld()
{
    int size = 5;
    //printf("Enter the size of the world you want to create: ");
    //scanf("%d", &size);

    
	// Sizes must be 2^n + 1 for terrain generator to work
    switch(size)
    {
        case 1:
            world.map.width = 9;
            world.map.height = 9;
            break;
        case 2:
            world.map.width = 17;
            world.map.height = 17;
            break;
        case 3:
            world.map.width = 33;
            world.map.height = 33;
            break;
        case 4:
            world.map.width = 65;
            world.map.height = 65;
            break;
        case 5:
            world.map.width = 129;
            world.map.height = 129;
            break;
        default:
            world.map.width = 33;
            world.map.height = 33;
            break;
    }

    initMap(&(world.map));
    fillMap(&(world.map),"#");
    //printMap(&(world.map));
    generateWorld();
	printMap(&(world.map));
}


/**
Seed Generation
*/
void generateSeed()
{
	srand(time(NULL));
    int seed, i, j;
    
	do
	{
		world.map.seed = rand() % 10000;
	}
	while(world.map.seed < 1111);
	
	printf("--------------------------\n\nSEED: %d\n\n----------------------------------\n", world.map.seed);
}

/**
Diamond Terrain Generation
*/
void diamondHeightmap(int x, int y, int length)
{
	if(y - length == 0)
	{
		world.map.intTiles[y - length][x] = (world.map.intTiles[y][x]    +    world.map.intTiles[y - length][x - length]    +    world.map.intTiles[y - length][x + length]) / 3;
	}
	if(y + length == world.map.width - 1)
	{
		world.map.intTiles[y+length][x] = (world.map.intTiles[y][x]    +   world.map.intTiles[y + length][x - length]    +   world.map.intTiles[y + length][x + length]) / 3 ;
	}
	else
	{
		world.map.intTiles[y + length][x] = (world.map.intTiles[y][x]    +    world.map.intTiles[y + length][x - length]    +    world.map.intTiles[y + length][x + length]    +    world.map.intTiles[y + 2 * length][x]) / 4;
	}
	if(x - length == 0)
	{
		world.map.intTiles[y][x - length] = (world.map.intTiles[y][x]    +   world.map.intTiles[y - length][x - length]    +   world.map.intTiles[y + length][x - length]) / 3;
	}
	if(x + length == world.map.height - 1)
	{
		world.map.intTiles[y][x + length] = (world.map.intTiles[y][x]    +   world.map.intTiles[y - length][x + length]    +   world.map.intTiles[y + length][x + length]) / 3;
	}
	else
	{
		world.map.intTiles[y][x + length] = (world.map.intTiles[y][x]    +    world.map.intTiles[y - length][x - length]    +    world.map.intTiles[y + length][x + length]    +    world.map.intTiles[y][x + 2 * length]) / 4;
	}
	
}

/**
Square Terrain Generation
*/
void squareHeightmap(int x, int y, int length)
{
	world.map.intTiles[y - length / 2][x - length / 2] = (world.map.intTiles[y - length][x - length]    +    world.map.intTiles[y - length][x]    +    world.map.intTiles[y][x - length]    +    world.map.intTiles[x][y]) / 4;
	world.map.intTiles[y - length / 2][x + length / 2] = (world.map.intTiles[y - length][x]    +    world.map.intTiles[y - length][x + length]    +    world.map.intTiles[y][x + length]    +    world.map.intTiles[x][y]) / 4;
	world.map.intTiles[y + length / 2][x - length / 2] = (world.map.intTiles[y][x - length]    +    world.map.intTiles[y + length][x - length]    +    world.map.intTiles[y + length][x]    +    world.map.intTiles[x][y]) / 4;
	world.map.intTiles[y + length / 2][x + length / 2] = (world.map.intTiles[y][x + length]    +    world.map.intTiles[y + length][x]    +    world.map.intTiles[y + length][x + length]    +    world.map.intTiles[x][y]) / 4;
}

/**
Terrain heightmap generation
*/
void generateHeightmap()
{
	// apply seed to corners
	world.map.intTiles[world.map.width - 1][world.map.width - 1] = world.map.seed % 10;
	world.map.intTiles[world.map.width - 1][0] = world.map.seed / 10 % 10;
	world.map.intTiles[0][world.map.width - 1] = world.map.seed / 100% 10;
	world.map.intTiles[0][0] = world.map.seed / 1000 % 10;
	
	/**
	Filling in the heightmap
	*/
	int length = world.map.width / 2;
	
	//Fill Center Tile
	world.map.intTiles[(world.map.width - 1) / 2][(world.map.height - 1) / 2] = (world.map.intTiles[0][0] + 
																				 world.map.intTiles[0][world.map.height - 1] +
																				 world.map.intTiles[world.map.width - 1][0] + 
																				 world.map.intTiles[world.map.width - 1][world.map.height - 1]
																				 ) / 4;
	while(length > 0)
	{
		//Do diamond Step
		int i,j;
		for(i = 0; i < world.map.width / 2 / length; i++)
		{
			for(j = 0; j < world.map.height / 2 / length; j++)
			{
				diamondHeightmap(length + (j * 2 * length), length + (i * 2 * length), length);
			}
		}
		
		//Do square Step
		for(i = 0; i < world.map.width / 2 / length; i++)
		{
			for(j = 0; j < world.map.height / 2 / length; j++)
			{
				if(length > 1) squareHeightmap(length + (j * 2 * length), length + (i * 2 * length), length);
			}
		}
		
		
		if(length == 1)length = 0;
		length -= length / 2;
	}
}

void fillHeightmapChars()
{
	int i, j;
	for(i = 0; i < world.map.width; i++)
	{
		for(j = 0; j < world.map.height; j++)
		{
			if(world.map.intTiles[i][j] <= 2)
				world.map.tiles[i][j] = "~";
			if(world.map.intTiles[i][j] > 2 && world.map.intTiles[i][j] <= 4)
				world.map.tiles[i][j] = "#";
			if(world.map.intTiles[i][j] > 4 && world.map.intTiles[i][j] <= 6)
				world.map.tiles[i][j] = "n";
			if(world.map.intTiles[i][j] > 6 && world.map.intTiles[i][j] <= 8)
				world.map.tiles[i][j] = "t";
			if(world.map.intTiles[i][j] > 8)
				world.map.tiles[i][j] = "^";
		}
	}
}

void generateWorld()
{
	generateSeed();
	generateHeightmap();
	fillHeightmapChars();
}

void renderWorld(SDL_Renderer *renderer, World *wrld)
{
	renderMap(renderer, &(wrld->map));
}

























