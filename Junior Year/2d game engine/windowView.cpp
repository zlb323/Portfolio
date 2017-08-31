#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <iostream>
#include <thread>
#include "tile.h"
#include "map.h"
#include "windowView.h"
#include <iostream>

using namespace std;


		windowView::windowView(int w, int h, int _maxX, int _maxY)
			:width(w), height(h) 
			{
				maxX = _maxX;
				maxY = _maxY;
				x = 0;
				y = 0;
				shiftUp = false;
				shiftRight = true;
			}
			
		void windowView::render(map _m, tile _t, SDL_Renderer* gRenderer){
			_m.render(_t, x,y,width,height, gRenderer);
		}
		
		void windowView::moveLeft(float speed){
			if(x >0){
				for(int i = 0; i < 16; i++){
					x -= (speed/16.0);
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
			if(x == 0) shiftLeft = false;
		}
		
		void windowView::moveRight(float speed){
			if(x+width < maxX) {
				for(int i = 0; i < 16; i++){
					x += (speed/16.0);
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
			if(x+width == maxX) shiftRight = false;
		}
		
		void windowView::moveUp(float speed){
			if(y > 0){
				for(int i = 0; i < 16; i++){
					y -= (speed/16.0);
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
			if(y < 1) shiftUp = false;
			cout << y << endl;
			cout << shiftUp << endl;
		}
		
		void windowView::moveDown(float speed){
			if(y + height < maxY){
				for(int i = 0; i < 16; i++){
					y += (speed/16.0);
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
			if(y + height == maxY) shiftDown = false;
		}

bool windowView::getShiftUp(){
	return shiftUp;
}

double windowView::getX(){
	return x;
}

double windowView::getY(){
	return y;
}

double windowView::getMaxX(){
	return maxX;
}

double windowView::getMaxY(){
	return maxY;
}

int windowView::getHeight(){
	return height;
}

int windowView::getWidth(){
	return width;
}
