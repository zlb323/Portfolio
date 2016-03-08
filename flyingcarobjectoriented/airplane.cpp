#include "Airplane.h"

#include <iostream>
#include <string>

namespace trans {
	void airplane::setWingSize(int _wingSize) {
		wingSize = _wingSize;
	}

	int airplane::getWingSize() {
		return wingSize;
	}

	void airplane::boardPass(int _numBoarding) {
		if(isRoom(_numBoarding)) numOfPassengers += _numBoarding;
		else std::cout << "not enough room for all these passengers!!" << std::endl;
	}

	void airplane::deliverPass(int _numLeave) {
		numOfPassengers -= _numLeave;
	}

	bool airplane::isRoom(int _numBoarding) {
		if ((numOfPassengers + _numBoarding) <= maxPassengers) return true;
		else return false;
	}
	airplane::airplane(int _wingSize, int _numOfPassengers, int _maxPassengers, int _speed, std::string _driver)
		: wingSize(_wingSize), numOfPassengers(_numOfPassengers), maxPassengers(_maxPassengers), transportation(_speed, _driver) {}
	//airplane::airplane(int _wingSize, int _numOfPassengers)
	airplane::~airplane() {
		std::cout << "Airplane crashes into the Andes!!" << std::endl;
	}
}