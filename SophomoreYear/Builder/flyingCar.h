#pragma once

#include <iostream>
#include <string>
#include <memory>

class flyingCar {
private:
	int speed;
	int numPassengers;
	int modelYear;
public:
	class builder;

	flyingCar(int _speed, int _numP, int _modelYear);
	int getspeed();
	int getnumPassengers();
	int getModelYear();
	void setSpeed(int _speed);
	void setNumPassengers(int _numP);
	void setModelYear(int _modelYear);
	void Print();
};

class flyingCar::builder {
private:
	int speed;
	int numP;
	int modelYear;
public:
	static const int defaultSpeed = 10;
	static const int defaultPassengers = 0;
	static const int defaultModelYear = 2016;

	builder();

	builder& setSpeed(int _speed);
	builder& setNumP(int _numP);
	builder& setModelYear(int _modelYear);

	std::shared_ptr<flyingCar> build();
};

