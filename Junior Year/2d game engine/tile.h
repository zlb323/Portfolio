#pragma once
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

class tile
{
	public:
		tile();
		bool loadFromFile(const char* path, SDL_Renderer*);
		void render(int x, int y, SDL_Rect* clip,int tile_size, SDL_Renderer*);
		SDL_Rect getTileSprite(int type);
		SDL_Rect getObjSprite(int type);
	private:
		SDL_Texture* mtexture;
		int mwidth;
		int mheight;
};
