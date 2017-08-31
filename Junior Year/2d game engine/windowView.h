#pragma once


class windowView{
	private:
		volatile double x;
		volatile double y;
		int width;
		int height;
		int maxX;
		int maxY;
		bool shiftUp;
		bool shiftRight;
		bool shiftDown;
		bool shiftLeft;
	public:
		windowView(int w, int h, int _maxX, int _maxY);
		void render(map _m, tile _t, SDL_Renderer* gRenderer);
		void moveLeft(float);
		void moveRight(float);
		void moveUp(float);
		void moveDown(float);
		
		bool getShiftUp();
		double getX();
		double getY();
		double getMaxX();
		double getMaxY();
		int getHeight();
		int getWidth();
		
		
};

