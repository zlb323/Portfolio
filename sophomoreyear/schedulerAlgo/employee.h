#pragma once

#include <string>
#include <iostream>

#include "week.h"

class availability;

class shifts;

class employee {
public:
	availability *days[7];
	std::string name;
	employee(std::string);
	int max = 4000;
	int current = 0;
	bool in[7];
	shifts *s[7];
	bool checkmax(int);
};

class availability {
public:
	int start[10];
	int end[10];
	int top;
public:
	bool check(int _s, int _e);
	availability();
	void set(int _s, int _e);
	void print();
};