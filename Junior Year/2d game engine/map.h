#pragma once
#include "tile.h"

enum mapTile { GRASS, SAND, SAND_UPPER_RIGHT_CORNER, SAND_UPPER_LEFT_CORNER,
				SAND_LOWER_RIGHT_CORNER, SAND_LOWER_LEFT_CORNER, SAND_TOP,
				SAND_BOTTOM, SAND_RIGHT, SAND_LEFT, RED_SINGLE_FLOWER,
				RED_MULTI_FLOWER, BLUE_SINGLE_FLOWER, BLUE_MULTI_FLOWER};
				
enum objTile {
		FENCE_TOP, FENCE_TOP_RIGHT, FENCE_RIGHT, FENCE_BOT_RIGHT, FENCE_BOT,
		FENCE_BOT_LEFT, FENCE_LEFT, FENCE_TOP_LEFT, NONE
};
				
				
class map{
	mapTile **mapTiles;
	objTile **objTiles;
	int max_x;
	int max_y;
	bool isFull;
	bool isObjFull;
	public:
		int x;
		int y;
		int objX;
		int objY;
		map(int x, int y);
		void addTile(int _tileType);
		void addObjTile(int _tileType);
		void render(tile t,double _x,double _y, int width_of_screen, int height_of_screen, SDL_Renderer* gRenderer);
		int getMaxX();
		int getMaxY();
		bool isBlocked(int, int);
		mapTile getTileType(int x,int y);
};
