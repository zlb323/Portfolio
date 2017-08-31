#pragma once
#include "map.h"
#include "windowView.h"
#include "player.h"

class GameHandler{
	
	Player* player;
	windowView* wv;
	map* mp;
	
	bool up;
	volatile bool down; //wether this button is being held down.
	bool left;
	bool right;
	
	volatile bool isDone; // when the handler is terminated end the run() function.
	
	std::thread* charThread; // threads to handle each character movement and positioning
	std::thread* wvThread; //thread for window view;
	public:
	GameHandler( windowView* _wv, Player* _player, map* _map);
	
	void setUp(bool _up);
	void setDown(bool _down);
	void setLeft(bool _left);
	void setRight(bool _right);
	
	void finish();
	
	void run();
};
