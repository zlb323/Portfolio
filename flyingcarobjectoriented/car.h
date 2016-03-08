#pragma once
#include <iostream>
#include <string>

#include "Transportation.h"
namespace trans {
	class car : virtual public transportation {
	private:
		std::string wheelType;
	public:
		virtual void setWheelType(std::string _wheelType);
		virtual std::string getWheelType();
		car(std::string _wheelType, int _speed, std::string _driver);
		virtual ~car();
	};
}