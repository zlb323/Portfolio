#include <iostream>
#include <thread>
#include "Player.h"
#include "map.h"

using namespace std;


bool Player::loadFromFile(const char* path, SDL_Renderer* gRenderer){ //load tileSpriteSheet
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

Player::Player(const char* imgPath, SDL_Renderer* gRenderer){
	if(!loadFromFile(imgPath, gRenderer)) cout << "Cannot load image for Player" << endl;
	currentSprite.w = 32;
	currentSprite.h = 32;
	x = 1;
	y = 1;
	speed = 1;
}

void Player::render(SDL_Renderer* gRenderer)
{
	SDL_Rect renderQuad = {y * 40.0, x * 40.0, 40, 40};
	SDL_RenderCopy(gRenderer, mtexture, &currentSprite, &renderQuad);
}

void Player::shiftUp(){
	for(int i = 0; i < 16; i++){
		x -= (1.0/16.0);
		std::this_thread::sleep_for(std::chrono::milliseconds(10/speed));
	}
}
void Player::shiftDown(){
	for(int i = 0; i < 16; i++){
		x += (1.0/16.0);
		std::this_thread::sleep_for(std::chrono::milliseconds(10/speed));
	}
}
void Player::shiftLeft(){
	for(int i = 0; i < 16; i++){
		y -= (1.0/16.0);
		std::this_thread::sleep_for(std::chrono::milliseconds(10/speed));
	}
}
void Player::shiftRight(){
	for(int i = 0; i < 16; i++){
		y += (1.0/16.0);
		std::this_thread::sleep_for(std::chrono::milliseconds((int)(10.0/speed)));
	}
}
void Player::moveUp(bool shift){
	thread* t = NULL;
	if(shift){
		t = new thread(&Player::shiftUp, this);
	}
	currentSprite.y = 96;
	currentSprite.x = 64;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 32;
	if(t != NULL) t->join();
}
void Player::moveRight(bool shift){
	thread* t = NULL;
	if(shift){
		t = new thread(&Player::shiftRight, this);
	}
	currentSprite.y = 64;
	currentSprite.x = 64;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 32;
	if(t != NULL) t->join();
}

void Player::moveDown(bool shift){
	thread* t = NULL;
	if(shift){
		t = new thread(&Player::shiftDown, this);
	}
	currentSprite.y = 0;
	currentSprite.x = 64;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 32;
	if(t != NULL) t->join();
}

void Player::moveLeft(bool shift){
	thread* t = NULL;
	if(shift){
		t = new thread(&Player::shiftLeft, this);
	}
	currentSprite.y = 32;
	currentSprite.x = 64;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 0;
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	currentSprite.x = 32;
	if(t != NULL) t->join();
}

float Player::getX(){
	return x;
}

float Player::getY(){
	return y;
}

float Player::getSpeed(){
	return speed;
}

void Player::setSpeed(float _s){
	speed = _s;
}

void Player::getTerrainEffect(mapTile type){
	if(type == SAND) this->setSpeed(.5);
	else this->setSpeed(1.0);
}
