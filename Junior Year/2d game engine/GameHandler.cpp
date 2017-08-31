#include <string>
#include <thread>
#include <future>
#include <iostream>
#include "gameHandler.h"
using namespace std;

GameHandler::GameHandler(windowView* _wv, Player* _player, map* _map){
	wv = _wv;
	player = _player;
	mp = _map;
	isDone = false;
	up = false;
	down = false;
	left = false;
	right = false;
	wvThread = NULL;
}
	
void GameHandler::setUp(bool _up){
	up = _up;
}
void GameHandler::setDown(bool _down){
	down = _down;
}
void GameHandler::setLeft(bool _left){
	left = _left;
}
void GameHandler::setRight(bool _right){
	right = _right;
}

void GameHandler::finish(){
	isDone = true;
}

void GameHandler::run(){
	while(!isDone){
		player->getTerrainEffect(mp->getTileType(player->getX() + wv->getY(), player->getY() + wv->getX()));

		if(wvThread != NULL) {
			wvThread->join();
			wvThread = NULL;
		}
		else{
		if(up){
			if(!(mp->isBlocked(player->getX() +wv->getY(), player->getY()+wv->getX()))){
				if((player->getX() < 3) && (wv->getY() >0)){
					wvThread = new thread(&windowView::moveUp, wv, player->getSpeed());
					player->moveUp(false);
				}
				else{
					player->moveUp(true);
				}
			}
		}
		 if(right){
			 if(!(mp->isBlocked(player->getX()+wv->getY(), (player->getY() +wv->getX() +1)))){
				if((player->getY() > 12) && (wv->getX() + wv->getWidth() < wv->getMaxX())){
					wvThread = new thread(&windowView::moveRight, wv, player->getSpeed());
					player->moveRight(false);
				}
				else{ 
					player->moveRight(true);
				}
			}
		}
		if(left){
			if(!(mp->isBlocked(player->getX()+wv->getY(), player->getY()+wv->getX() -1))){
				if((player->getY() < 3) && (wv->getX() > 0)){
					wvThread = new thread(&windowView::moveLeft, wv, player->getSpeed());
					player->moveLeft(false);
				}
				else{
					player->moveLeft(true);
				}
			}
		}
		if(down){
			if(!(mp->isBlocked(player->getX() +wv->getY() +1, player->getY()+wv->getX()))){
				if((player->getX() > 8) && (wv->getY() + wv->getHeight() < wv->getMaxY())) {
					wvThread = new thread(&windowView::moveDown, wv, player->getSpeed());
					player->moveDown(false);
				}
				else{
					player->moveDown(true);
				}
			}
		}
		}
	
	}
}
