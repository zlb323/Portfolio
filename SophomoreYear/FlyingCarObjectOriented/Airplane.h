#pragma once

#include "Transportation.h"

#include <iostream>
#include <string>
namespace trans {
	class airplane : virtual public transportation {
	private:
		int wingSize;
		int numOfPassengers;
		const int maxPassengers;
	public:
		virtual void setWingSize(int _wingSize);
		virtual int getWingSize();
		virtual void boardPass(int _numBoarding);
		virtual void deliverPass(int _numLeave);
		virtual bool isRoom(int _numBoarding);
		airplane(int _wingSize, int _numOfPassengers, int _maxPassengers, int _speed, std::string driver);
		//airplane(int _wingsize, int _numOfPassengers, int _maxPassengers);
		virtual ~airplane();
	};
}