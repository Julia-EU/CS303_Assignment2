#pragma once
#include "Employee.h"

class professional : public Employee {

public:
	professional();
	void calc_salary();
	void calc_contributions();
	void calc_vacation();
};


professional::professional() {
	hours = 0;
	salary = 4200.00;
	vacation_days = 0;
	contributions = 0;
}

void professional::calc_salary() {
	if (hours >= 40) {
		salary += 4200.00;
	}
}

void professional::calc_contributions() {
	contributions += 0.10 * salary;
	salary -= contributions;
}

void professional::calc_vacation() {
	if (hours >= 40) {
		vacation_days += 1;
	}

	else if (hours >= 35) {
		vacation_days += 0.75;
	}
}
