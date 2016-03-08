#include "car.h"

#include <iostream>
#include <string>
namespace trans {
	void car::car::setWheelType(std::string _wheelType) {
		wheelType = _wheelType;
	}

	std::string car::car::getWheelType() {
		return wheelType;
	}

	car::car::car(std::string _wheelType, int _speed, std::string _driver)
		: wheelType(_wheelType), transportation(_speed, _driver) {}

	car::car::~car() {
		std::cout << "car crushed!!" << std::endl;
	}
}