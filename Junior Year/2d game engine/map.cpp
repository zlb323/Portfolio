#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <iostream>
#include "tile.h"
#include "map.h"

int tile_size = 40;

using namespace std;


map::map(int x, int y){
	mapTiles = new mapTile*[x];
	objTiles = new objTile*[x];
	for(int i = 0; i < y; i++){
		mapTiles[i] = new mapTile[y];
		objTiles[i] = new objTile[y];
	}
	max_x = x;
	max_y = y;
	x = 0;
	objX = 0;
	y = 0;
	objY = 0;
	isFull = false;
	isObjFull = false;
}
void map::addObjTile(int _tileType){
	if(isObjFull){
		cout << "map is full";
		return;
	}
	objTile t = NONE;
	switch(_tileType){
		case 1:
			t = FENCE_TOP;
			break;
		case 2:
			t = FENCE_TOP_RIGHT;
			break;
		case 3:
			t = FENCE_RIGHT;
			break;
		case 4:
			t = FENCE_BOT_RIGHT;
			break;
		case 5:
			t = FENCE_BOT;
			break;
		case 6:
			t = FENCE_BOT_LEFT;
			break;
		case 7:
			t = FENCE_LEFT;
			break;
		case 8:
			t = FENCE_TOP_LEFT;
			break;
		default:
			t = NONE;
			break;
	}
	objTiles[objY][objX] = t;
	objX++;
	if(objX >= max_x){
		objX = 0;
		objY++;
		if(objY >= max_y) isFull = true;
	}
	return;
}

void map::addTile(int _tileType){
	if(isFull){
		cout << "map is full";
		return;
	}
	mapTile t;
	switch(_tileType){
		case 1:
			t = GRASS;
			break;
		case 2:
			t = SAND;
			break;
		case 3:
			t = SAND_UPPER_RIGHT_CORNER;
			break;
		case 4:
			t = SAND_UPPER_LEFT_CORNER;
			break;
		case 5:
			t = SAND_LOWER_RIGHT_CORNER;
			break;
		case 6:
			t = SAND_LOWER_LEFT_CORNER;
			break;
		case 7:
			t = SAND_TOP;
			break;
		case 8:
			t = SAND_BOTTOM;
			break;
		case 9:
			t = SAND_RIGHT;
			break;
		case 10:
			t = SAND_LEFT;
			break;
		case 11:
			t = RED_SINGLE_FLOWER;
			break;
		case 12:
			t = RED_MULTI_FLOWER;
			break;
		case 13:
			t = BLUE_SINGLE_FLOWER;
			break;
		case 14:
			t = BLUE_MULTI_FLOWER;
			break;
		default:
			t = GRASS;
	}
	mapTiles[y][x] = t;
	x++;
	if(x >= max_x){
		x = 0;
		y++;
		if(y >= max_y) isFull = true;
	}
	return;
}
void map::render(tile t,double _x,double _y, int width_of_screen, int height_of_screen, SDL_Renderer* gRenderer){
	int pos_x; //x position of next tile
	int pos_y;//y position of next tile
	SDL_Rect rect;
	for(int i = _y; i < height_of_screen + _y; i++){
		for(int j = _x; j < width_of_screen + _x; j++){
			pos_x = (i-_y)*tile_size;
			pos_y = (j-_x)*tile_size;
			rect = t.getTileSprite(mapTiles[i][j]);
			t.render(pos_x, pos_y, &rect, tile_size, gRenderer);
			rect = t.getObjSprite(objTiles[i][j]);
			t.render(pos_x, pos_y, &rect, tile_size, gRenderer);
		}
	}
}
int map::getMaxX(){
	return max_x;
}
int map::getMaxY(){
	return max_y;
}

bool map::isBlocked(int x, int y){
	cout << y << endl;
	if(objTiles[x][y] == NONE){
		 return false;
	 }
	return true;
}

mapTile map::getTileType(int x, int y){
	return mapTiles[x][y];
}
