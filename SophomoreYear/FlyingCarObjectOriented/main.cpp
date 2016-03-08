#include <iostream>
#include <string>

#include "Transportation.h"
#include "car.h"
#include "Airplane.h"
#include "FlyingCar.h"

int main(int argc, char ** argv)
{
	{
		trans::transportation *herbie;
		herbie = new trans::car("all-terrain", 4, "dan");
		std::cout << herbie->getDriver() << std::endl;
		delete herbie;
	}
	{
		trans::transportation *plane;
		plane = new trans::airplane(3, 3, 3, 3, "John");
		std::cout << plane->getSpeed() << std::endl;
		delete plane;
	}
	{
		trans::transportation *pegasus = new trans::flyingCar(3, 3, 3, 3, "Macevoy", "Racing");
		std::cout << pegasus->getDriver() << std::endl;
		pegasus->setDriver("W");
		std::cout << pegasus->getDriver() << std::endl;
		delete pegasus;
	}
	system("pause");
	return 0;
}