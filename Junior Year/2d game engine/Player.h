#pragma once

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "map.h"


class Player{
	private:
		SDL_Texture* mtexture;
		int mwidth;
		int mheight;
		float speed;
		bool loadFromFile(const char* path, SDL_Renderer* gRenderer);
		SDL_Rect currentSprite;
		volatile float x;
		volatile float y;
	public:
		Player(const char* imgPath, SDL_Renderer* gRenderer);
		void render(SDL_Renderer* gRenderer);
		void moveUp(bool);
		void moveRight(bool);
		void moveDown(bool);
		void moveLeft(bool);
		
		void shiftUp();
		void shiftDown();
		void shiftLeft();
		void shiftRight();
		
		float getX();
		float getY();
		
		float getSpeed();
		void setSpeed(float);
		
		void getTerrainEffect(mapTile type);
};

