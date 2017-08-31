enum charTile { StandS, WalkS1, WalkS2, StandW, WalkW1, WalkW2,
                StandN, WalkN1, WalkN2, StandE, WalkE1, WalkE2};

class Character
{
public:
  character()
  {
    mtexture = NULL;
    mwidth = 0;
    mheight = 0;
  }
  bool loadFromFile(const char* path){ //load CharacterspriteSheet
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
  SDL_Rect getCharacterSprite(int type)
		{
			SDL_Rect rect;
			rect.w = 16;
			rect.h = 16;
			int x;
			int y;
			switch(type){
				case StandS:
					x = 16;
					y = 0;
					break;
				case WalkS1:
					x = 0;
					y = 0;
					break;
				case WalkS2:
					x = 32;
					y = 0;
					break;
				case StandW:
					x = 16;
					y = 16;
					break;
				case WalkW1:
					x = 0;
					y = 16;
					break;
				case WalkW2:
					x = 32;
					y = 16;
					break;
				case StandE:
          x = 16;
          y = 32;
          break;
        case WalkE1:
          x = 0;
          y = 32;
          break;
        case WalkE2:
          x = 32;
          y = 32;
          break;
        case StandN:
          x = 16;
          y = 48;
          break;
        case WalkN1:
          x = 0;
          y=  48;
          break;
        case WalkN2:
          x = 32;
          y = 48;
          break;
			}
			rect.x = x;
			rect.y = y;
			return rect;
		}
  private:
    SDL_Texture* mtexture;
    int mwidth;
    int mheight;
};
