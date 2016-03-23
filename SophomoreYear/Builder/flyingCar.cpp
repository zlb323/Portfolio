#include <iostream>
#include <string>

#include "flyingCar.h"

using namespace std;

void flyingCar::setSpeed(int _speed)
{
	speed = _speed;
}
void flyingCar::setNumPassengers(int _numP)
{
	numPassengers = _numP;
}
void flyingCar::setModelYear(int _modelYear)
{
	modelYear = _modelYear;
}
flyingCar::flyingCar(int _speed, int _numP, int _modelYear)
	:speed(_speed), numPassengers(_numP), modelYear(_modelYear) {}

int flyingCar::getspeed()
{
	return speed;
}
int flyingCar::getnumPassengers()
{
	return numPassengers;
}
int flyingCar::getModelYear()
{
	return modelYear;
}
void flyingCar::Print() {
	cout << "this Flying Car has a speed of: " << speed << endl << numPassengers << " Passengers and" << endl
		<< "was made in " << modelYear << endl;
}

flyingCar::builder& flyingCar::builder::setSpeed(int _speed)
{
	this->speed = _speed;
	return *this;
}
flyingCar::builder& flyingCar::builder::setNumP(int _numP)
{
	this->numP = _numP;
	return *this;
}
flyingCar::builder& flyingCar::builder::setModelYear(int _modelYear)
{
	this->modelYear = _modelYear;
	return *this;
}
std::shared_ptr<flyingCar> flyingCar::builder::build()
{
	shared_ptr<flyingCar> knew (new flyingCar(this->speed, this->numP, this->modelYear));
	return knew;
}

flyingCar::builder::builder()
	:speed(defaultSpeed), numP(defaultPassengers), modelYear(defaultModelYear) {}