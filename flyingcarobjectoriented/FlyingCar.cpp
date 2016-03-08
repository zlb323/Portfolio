#include "FlyingCar.h"

#include <iostream>
#include <string>

namespace trans {
	void flyingCar::brag() {
		std::cout << "I have a Flying Car!!!" << std::endl;
	}
	void flyingCar::fly() {
		std::cout << "Flying car is now flying!!!" << std::endl;
	}
	void flyingCar::drive() {
		std::cout << "Flying car is now driving!!!" << std::endl;
	}
	flyingCar::flyingCar(int _wingSize, int _numOfPassengers, int _maxPassengers, int _speed, std::string _driver, std::string _wheelType)
		: airplane(_wingSize, _numOfPassengers, _maxPassengers, _speed, _driver), car(_wheelType, _speed, _driver), transportation(12, _driver) {}

	flyingCar::~flyingCar() {
		std::cout << "Flying car flies away into the sunset..." << std::endl;
	}
}