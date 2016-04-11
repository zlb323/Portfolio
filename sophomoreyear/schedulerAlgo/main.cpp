#include <iostream>
#include <string>
#include <memory>

#include "employee.h"
#include "week.h"

using namespace std;


int main()
{
	employee* emps[30];
	week wk1;

	emps[0] = new employee("John");
	emps[1] = new employee("Logan");
	emps[2] = new employee("Zach");
	emps[3] = new employee("West");
	emps[4] = new employee("Ben");

	emps[0]->days[0]->print();


	emps[4]->days[0]->set(1200, 1400);
	emps[4]->days[1]->set(800, 1100);
	emps[4]->days[2]->set(800, 1100);
	emps[4]->days[3]->set(1200, 1100);
	emps[4]->days[4]->set(800, 1800);
	emps[4]->days[5]->set(800, 2000);
	emps[4]->days[6]->set(800, 2000);

	emps[4]->days[0]->print();

	emps[0]->days[0]->set(1700, 2000);
	emps[0]->days[1]->set(1700, 2000);
	emps[0]->days[2]->set(1700, 2000);
	emps[0]->days[3]->set(1700, 2000);
	emps[0]->days[4]->set(1700, 2000);
	emps[0]->days[5]->set(1700, 2000);
	emps[0]->days[6]->set(1700, 2000);

	emps[0]->days[0]->print();


	emps[1]->days[0]->set(0, 1100);
	emps[1]->days[1]->set(0, 1100);
	emps[1]->days[2]->set(00, 1100);
	emps[1]->days[3]->set(00, 1100);
	emps[1]->days[4]->set(00, 1100);
	emps[1]->days[5]->set(00, 1100);
	emps[1]->days[6]->set(00, 1100);

	emps[1]->days[0]->set(1900, 2100);
	emps[1]->days[1]->set(1900, 2100);
	emps[1]->days[2]->set(1900, 2100);
	emps[1]->days[3]->set(1900, 2100);
	emps[1]->days[4]->set(1900, 2100);
	emps[1]->days[5]->set(1900, 2100);
	emps[1]->days[6]->set(1900, 2100);

	emps[2]->days[0]->set(0, 1500);
	emps[2]->days[1]->set(0, 1500);
	emps[2]->days[2]->set(00, 1500);
	emps[2]->days[3]->set(00, 1500);
	emps[2]->days[4]->set(00, 1500);
	emps[2]->days[5]->set(00, 1500);
	emps[2]->days[6]->set(00, 1500);

	emps[3]->days[0]->set(1900, 2400);
	emps[3]->days[1]->set(1900, 2400);
	emps[3]->days[2]->set(1900, 2400);
	emps[3]->days[3]->set(1700, 2400);
	emps[3]->days[4]->set(800, 2400);
	emps[3]->days[5]->set(800, 2400);
	emps[3]->days[6]->set(800, 2400);

	wk1.days[0]->setshift(800, 1600);
	wk1.days[0]->setshift(1200, 1800);
	wk1.days[0]->setshift(1600, 2000);

	wk1.days[1]->setshift(800, 1600);
	wk1.days[1]->setshift(1200, 1800);
	wk1.days[1]->setshift(1600, 2000);

	wk1.days[2]->setshift(800, 1600);
	wk1.days[2]->setshift(1200, 1800);
	wk1.days[2]->setshift(1600, 2000);

	wk1.days[3]->setshift(800, 1600);
	wk1.days[3]->setshift(1200, 1800);
	wk1.days[3]->setshift(1600, 2000);

	wk1.days[4]->setshift(800, 1600);
	wk1.days[4]->setshift(1200, 1800);
	wk1.days[4]->setshift(1600, 2000);

	wk1.days[5]->setshift(800, 1600);
	wk1.days[5]->setshift(1200, 1800);
	wk1.days[5]->setshift(1600, 2000);
	
	wk1.days[6]->setshift(800, 1600);
	wk1.days[6]->setshift(1200, 1800);
	wk1.days[6]->setshift(1600, 2000);

	wk1.generate(emps, 5);

	wk1.print(emps);

	wk1.recheck(emps);

	wk1.print(emps);

	system("pause");
	return 0;
}