#include "Transportation.h"

#include <iostream>
#include <string>
namespace trans {
	void transportation::setSpeed(int _speed) {
		speed = _speed;
	}

	int transportation::getSpeed() {
		return speed;
	}

	void transportation::setDriver(std::string _driver) {
		driver = _driver;
	}

	std::string transportation::getDriver() {
		return driver;
	}

	transportation::transportation(int _speed, std::string _driver)
		: speed(_speed), driver(_driver) {}

	transportation::~transportation() {}
}