#pragma once

#include "Airplane.h"
#include "car.h"

#include <iostream>
#include <string>

namespace trans {
	class flyingCar : virtual public airplane, virtual public car {
	public:
		virtual void brag();
		virtual void fly();
		virtual void drive();
		flyingCar(int _wingSize, int _numOfPassengers, int _maxPassengers, int _speed, std::string driver, std::string _wheelType);
		virtual ~flyingCar();
	};
}