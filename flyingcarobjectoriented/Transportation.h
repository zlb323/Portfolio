#pragma once
#include <iostream>
#include <string>
namespace trans {
	class transportation {
	private:
		int speed;
		std::string driver;
	public:
		virtual void setSpeed(int _speed);
		virtual int getSpeed();
		virtual void setDriver(std::string _driver);
		virtual std::string getDriver();
		transportation(int, std::string);
		virtual ~transportation();
	};
}