#include <iostream>
#include <string>

#include "employee.h"

using namespace std;

bool availability::check(int _s, int _e) {
	for (int i = 0; i < 10; i++)
	{
		if (_s >= start[i]) {
			if (_e <= end[i]) return true;
		}
	}
	return false;
}

bool employee::checkmax(int x)
{
	if ((current+x) <= max) return true;
	else return false;
}

employee::employee(std::string _name)
	: name(_name) {
	for (int i = 0; i < 7; i++)
	{
		days[i] = new availability;
	}
	for (int i = 0; i < 7; i++){
		in[i] = false;
	}
}

availability::availability() {
	start[0] = 0;
	end[0] = 2400;
	for (int i = 1; i < 10; i++)
	{
		start[i] = 9999;
		end[i] = 9999;
	}
	top = 3;
}

void availability::set(int _s, int _e) {//sends in start and end times of UNAVAILABLE section
	int temp;
	for (int i = 0; i < 10; i++)
	{
		if ((_s >= start[i]) && (_s < end[i]))
		{
			temp = end[i];
			end[i] = _s;
			top++;
			if (_e < temp)
			{
				start[i+1] = _e;
				end[i+1] = temp;
			}
		}
	}
}

void availability::print()
{
	cout << "is available from: " << endl;
	for (int i = 0; i < 10; i++)
	{
		if ((start[i] > 2400) || (start[i] <0)) break;
		cout << start[i] << " to " << end[i] << endl;
	}

}