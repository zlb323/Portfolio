#pragma once

#include <iostream>
#include <string>

#include "employee.h"

class day;
class shifts;
class employee;

class week {
public:
	day* days[7];
	week();
	void generate(employee* emps[], int maxemps);
	void recheck(employee* emps[]);
	void print(employee* emps[]);
};

class day {
public:
	int top;
	employee* assigned[30];
	int start[30];
	int end[30];
	void assign(employee* emp, int _s, week* wk, int day);
	day();
	shifts* s[30];
	int numOfShifts = 0;
	int _shiftnum = 0;
	void setshift( int _s, int _e);
};

class shifts
{
public:
	int start;
	int end;
	bool filled = false;
	shifts(int);
	int self;
};