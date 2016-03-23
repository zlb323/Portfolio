#include <iostream>
#include <string>
#include <memory>

#include "flyingCar.h"

using namespace std;

int main(int args, char argv[])
{
	flyingCar::builder Car;
	Car.setSpeed(13).setNumP(4).setModelYear(2116);
	shared_ptr<flyingCar> newCar = Car.build();
	newCar->Print();
	system("pause");
	return 0;
}