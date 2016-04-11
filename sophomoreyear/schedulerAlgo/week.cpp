#include <iostream>
#include <string>
#include <vector>

#include "week.h"

using namespace std;

void day::assign(employee* emp, int _s, week* wk, int day)
{
	assigned[top] = emp;
	emp->in[day] = true;
	this->s[_s]->filled = true;
	emp->s[day] = s[_s];
	top++;
	emp->current += (this->s[_s]->end - this->s[_s]->start);
}

week::week()
{
	for (int i = 0; i < 7; i++)
	{
		days[i] = new day;
	}
}

day::day()
{
	for (int i = 0; i < 30; i++)
	{
		s[i] = new shifts(i);
	}
	top = 0;
}

void day::setshift( int _s, int _e)
{
	s[_shiftnum]->start = _s;
	s[_shiftnum]->end = _e;
	_shiftnum++;
}


void week::generate(employee* emps[], int maxemps)
{
	for (int i = 0; i < maxemps; i++)//employee loop
	{
		for (int j = 0; j < 7; j++)//day loop
		{
			if (!emps[i]->in[j])//check if employee already works that day
			{
				for (int k = 0; k < 30; k++)//shift loop
				{
					if (!emps[i]->in[j])//check if employee already works that day
					if (!this->days[j]->s[k]->filled)//check if shift isn't filled already
					{
						if (emps[i]->days[j]->check(this->days[j]->s[k]->start, this->days[j]->s[k]->end))//checks if employee availability lines up with shift
						{
							if(emps[i]->checkmax(this->days[j]->s[k]->end - this->days[j]->s[k]->start)) this->days[j]->assign(emps[i], k, this, j);//assigns employee to shift if under max hours
						}
					}
				}
			}
		}
	}
}

bool find(int i, int j, week* now, employee* emps[], vector<int> in);

void week::recheck(employee* emps[])
{
	vector<int> in;
	bool wrong[7][3] = { true };
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 3; i++)
		{
			if (this->days[j]->s[i]->filled == false) find(i, j, this, emps, in);
		}
	}

}

bool find(int i, int j, week* now, employee* emps[], vector<int> in) {
	bool temp = false;
	for (int k = 0; k < 5; k++)
	{
		temp = false;
		cout << "1";
		for (std::vector<int>::iterator it = in.begin(); it != in.end(); ++it) if (k == *it)
		{
			temp = true;
		}
		if (temp) continue;
		if (emps[k]->days[j]->check(now->days[j]->s[i]->start, now->days[j]->s[i]->end))//find employee that can work that shift
		{
			cout << "2";
			if ((emps[k]->current + (now->days[j]->s[i]->end - now->days[j]->s[i]->start)) <= emps[k]->max)//check if that employee has available hours
			{
				cout << "3";
				for (int u = 0; u < 5; u++)
				{
					cout << "4";
					if (emps[u]->s[j] == now->days[j]->s[i])
					{
						cout << "5";
						emps[u]->s[j] = NULL;
						emps[u]->in[j] = false;
					}
				}
				now->days[j]->assign(emps[k], i, now, j);
				return true;
			}
			else
			{
				for (int shif = 0; shif < 7; shif++)
				{
					cout << "6";
					if (emps[k]->s[shif != NULL]) {
						if ((emps[k]->s[shif]->end - emps[k]->s[shif]->start) >= ((now->days[j]->s[i]->end - now->days[j]->s[i]->start) + (emps[k]->max - emps[k]->current)))//checks if by replacing this shift if he has enough hours to fill shift in question
							cout << "j";
							if (emps[k]->s[shif] == now->days[shif]->s[(emps[k]->s[shif]->self)])
							{
								in.push_back(k);
								cout << k;
								cout << "8";
								if (find(emps[k]->s[shif]->self, shif, now, emps, in)) {
									now->days[j]->assign(emps[k], i, now, j);
								}
								break;
							}

					}
				}
			}
		}
	}
	return false;
}

shifts::shifts(int s) {
	start = NULL;
	end = NULL;
	self = s;
}

void week::week::print(employee* emps[])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!(emps[j]->s[i] == NULL))
			{
				cout << emps[j]->name << " works day# " << i << " from " << emps[j]->s[i]->start << " to " << emps[j]->s[i]->end << endl;
			}
		}
		cout << endl;
	}
}