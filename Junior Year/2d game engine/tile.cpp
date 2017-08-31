#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <iostream>
#include "tile.h"
#include "map.h"


using namespace std;

		tile::tile()
		{
			mtexture = NULL;
			mwidth = 0;
			mheight = 0;			
		}
		bool tile::loadFromFile(const char* path, SDL_Renderer* gRenderer){ //load tileSpriteSheet
			SDL_Texture* newTexture = NULL;
			SDL_Surface* loadedSurface = SDL_LoadBMP(path );
			if(loadedSurface == NULL)
			{
				cout << "unable to load image" << endl;
			}
			else
			{
				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF) );
				newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface );
				if( newTexture == NULL)
				{
					cout << "unable to create texture" << endl;
				}
				else{
					mwidth = loadedSurface->w;
					mheight = loadedSurface->h;
				}
				SDL_FreeSurface(loadedSurface);
			}
			mtexture = newTexture;
			return mtexture != NULL;
		}
		void tile::render(int x, int y, SDL_Rect* clip, int tile_size, SDL_Renderer* gRenderer)
		{
			SDL_Rect renderQuad = {y, x, tile_size, tile_size};
			SDL_RenderCopy(gRenderer, mtexture, clip, &renderQuad);
		}
		SDL_Rect tile::getTileSprite(int type)
		{
			SDL_Rect rect;
			rect.w = 16;
			rect.h = 16;
			int x;
			int y;
			switch(type){
				case GRASS:
					x = 80;
					y = 80;
					break;
				case SAND:
					x = 64;
					y = 80;
					break;
				case SAND_UPPER_RIGHT_CORNER:
					x = 96;
					y = 96;
					break;
				case SAND_RIGHT:
					x = 96;
					y = 112;
					break;
				case SAND_LOWER_RIGHT_CORNER:
					x = 96;
					y = 128;
					break;
				case SAND_BOTTOM:
					x = 80;
					y = 128;
					break;
				case SAND_LOWER_LEFT_CORNER:
					x = 64;
					y = 128;
					break;
				case SAND_LEFT:
					x = 64;
					y = 112;
					break;
				case SAND_UPPER_LEFT_CORNER:
					x = 64;
					y = 96;
					break;
				case SAND_TOP:
					x = 80;
					y = 96;
					break;
				case RED_SINGLE_FLOWER:
					x = 112;
					y = 0;
					break;
				case RED_MULTI_FLOWER:
					x = 112;
					y = 16;
					break;
				case BLUE_MULTI_FLOWER:
					x = 112;
					y = 64;
					break;
				case BLUE_SINGLE_FLOWER:
					x = 112;
					y = 48;
					break;
				default:
					x = 112;
					y = 112;
					break;
			}
			rect.x = x;
			rect.y = y;
			return rect;
		}
		SDL_Rect tile::getObjSprite(int type)
		{
			SDL_Rect rect;
			rect.w = 16;
			rect.h = 16;
			int x = 0;
			int y = 0;
			switch(type){
				case 0:
					x = 16;
					y = 9*16;
					break;
				case FENCE_TOP_RIGHT:
					x = 32;
					y = 9*16;
					break;
				case FENCE_RIGHT:
					x = 32;
					y = 160;
					break;
				case FENCE_BOT_RIGHT:
					x = 32;
					y = 16*11;
					break;
				case FENCE_BOT:
					x = 16;
					y = 16*11;
					break;
				case FENCE_BOT_LEFT:
					x = 0;
					y = 16*11;
					break;
				case FENCE_LEFT:
					x = 0;
					y = 160;
					break;
				case FENCE_TOP_LEFT:
					x = 0;
					y = 9*16;
					break;
				default:
					x = 11*16;
					y = 16*12;
					break;
			}
			rect.x = x;
			rect.y = y;
			return rect;
		}

