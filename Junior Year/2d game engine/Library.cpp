#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <thread>
#include "tile.h"
#include "map.h"
#include "windowView.h"
#include "gameHandler.h"
#include "Player.h"
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <chrono>

using namespace std;

SDL_Renderer* gRenderer = NULL;
const int tile_size = 40;
const int x_window_size = 16;
const int y_window_size = 12;

class AnimationFrame
{
	SDL_Texture *frame;
	int time,w,h; // milliseconds
	public:
	AnimationFrame(SDL_Texture *newFrame, int newTime=100)
	{
		frame = newFrame;
		time = newTime;
	}
	AnimationFrame(SDL_Renderer *ren, const char *imagePath, int newTime=100)
	{
		SDL_Surface *bmp = SDL_LoadBMP(imagePath);
		if (bmp == NULL) 
		{
			cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
			SDL_Quit();
		}
		SDL_SetColorKey(bmp,SDL_TRUE,SDL_MapRGB(bmp->format,0,255,0));
		w=bmp->w;
		h=bmp->h;
		frame = SDL_CreateTextureFromSurface(ren,bmp);
		SDL_FreeSurface(bmp);
		if (frame == NULL)
		{
			cout << "SDL_CreateTectureFromSurface Error: " << SDL_GetError() << endl;
			SDL_Quit();
		}
		time = newTime;
	}
	void show(SDL_Renderer *ren)
	{
		SDL_RenderCopy(ren, frame, NULL, NULL);
	}
	int getTime()
	{
		return time;
	}
	void destroy()
	{
		SDL_DestroyTexture(frame);
	}
};

class Animation
{
	vector<AnimationFrame *> frames;
	protected:
	int totalTime;
	public:
	Animation()
	{
		totalTime=0;
	}
	void addFrame(AnimationFrame *c)
	{
		frames.push_back(c);
		totalTime+=c->getTime();
	}
	virtual void show(SDL_Renderer *ren, int time /*milliseconds*/)
	{
		int aTime = time % totalTime;
		int tTime = 0;
		unsigned int i = 0;
		for (i = 0; i<frames.size();i++)
		{
			tTime+=frames[i]->getTime();
			if (aTime<=tTime) break;
		}
		frames[i]->show(ren);
	}
	virtual void destroy()
	{
		for (unsigned int i=0; i<frames.size();i++)
			frames[i]->destroy();
	}
};

class Sprite : public Animation
{
	float x, dx, ax, y, dy, ay;
	public:
	Sprite():Animation()
	{
		x = 0.0; dx = 0.0; ax = 0.0;
		y = 0.0; dy = 0.0; ay = 0.0;	
	}
	void addFrames(SDL_Renderer *ren, const char imagePath, int count)
	{
			
	}
	
};


class Game
{
	SDL_Window *win;
	SDL_Renderer *ren;
	public:
	void init(const char *gameName, int maxW=640, int maxH = 480, int startX = 100, int startY = 100)
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			cout << "SDL_Init Error: " << SDL_GetError() << endl;
			return;
		}
		win = SDL_CreateWindow (gameName, startX, startY, maxW, maxH, SDL_WINDOW_SHOWN);
		if (win == NULL)
		{
			cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
			SDL_Quit();
			return;
		}
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (ren == NULL )
		{
			SDL_DestroyWindow(win);
			cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
			SDL_Quit();
			return;
		}
	}
	void done()
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
	SDL_Renderer* getRenderer()
	{
		return ren;
	}
	void handleEvent(SDL_Event &event)
	{
		
	}
};

class AdamsGame:public Game
{
	public:
	void handleEvent(SDL_Event &event)
	{
		 
	}
	void run(){
		
	}
};

void move(string direction){
	
}

int main(int argc, char **argv)
{
	AdamsGame g;
	g.init("Hello World!");
	tile til;
	gRenderer = g.getRenderer();
	int x = 0;
	int y = 0;
	ifstream mapFile("map_test.txt");
	mapFile >> x;
	mapFile >> y;
	map _map(x, y);
	_map.x = 0;
	_map.y = 0;
	int max = x*y;
	int tmp;
	for(int i =0; i<max; i++){
		mapFile >> tmp;
		_map.addTile(tmp);
	}
	for(int i =0; i<max; i++){
		mapFile >> tmp;
		_map.addObjTile(tmp);
	}

	Animation a;
	a.addFrame(new AnimationFrame(g.getRenderer(), "hello1.bmp", 3000));
	a.addFrame(new AnimationFrame(g.getRenderer(), "hello2.bmp", 100));
	int start = SDL_GetTicks();
	int ticks;
	bool done = false;
	
	windowView screen(16,12, _map.getMaxX(), _map.getMaxY());
	
	while(!done)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				done = true;
			}
			else if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_SPACE) done = true;
			}
		}
		ticks = SDL_GetTicks();
		SDL_RenderClear(g.getRenderer());
		a.show(g.getRenderer(),ticks);
		SDL_RenderPresent(g.getRenderer());
	}
	done = false;
	thread *thred;
	Player p("CharSpriteSheet.bmp", gRenderer);
	GameHandler gh(&screen, &p, &_map);
	thred = new thread(&GameHandler::run, &gh);
	
	while(!done){
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				done = true;
			}
			if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_DOWN){
					gh.setDown(true);
					gh.setUp(false);
					gh.setLeft(false);
					gh.setRight(false);
				}
				else if(event.key.keysym.sym == SDLK_UP){
					gh.setDown(false);
					gh.setUp(true);
					gh.setLeft(false);
					gh.setRight(false);
				}
				else if(event.key.keysym.sym == SDLK_LEFT){
					gh.setDown(false);
					gh.setUp(false);
					gh.setLeft(true);
					gh.setRight(false);
				}
				else if(event.key.keysym.sym == SDLK_RIGHT){
					gh.setDown(false);
					gh.setUp(false);
					gh.setLeft(false);
					gh.setRight(true);
				}
			}
			if(event.type == SDL_KEYUP){
				if(event.key.keysym.sym == SDLK_DOWN){
					gh.setDown(false);
				}
				if(event.key.keysym.sym == SDLK_UP){
					gh.setUp(false);
				}
				else if(event.key.keysym.sym == SDLK_LEFT){
					gh.setLeft(false);
				}
				else if(event.key.keysym.sym == SDLK_RIGHT){
					gh.setRight(false);
				}
			}
		}
		g.run();
		
		ticks = SDL_GetTicks();
		SDL_RenderClear(g.getRenderer());
		a.show(g.getRenderer(),ticks);
		til.loadFromFile("sheet.bmp", gRenderer);
		screen.render(_map,til, gRenderer);
		p.render(gRenderer);
		SDL_RenderPresent(g.getRenderer());
	}
	gh.finish();
	if (thred != NULL)thred->join();
	int end = SDL_GetTicks();
	cout << "FPS " << (ticks*1000.0/float(end-start))<<endl;
	a.destroy();
	g.done();
	return 0;
}
