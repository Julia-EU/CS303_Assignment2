#pragma once
#include "Employee.h"

class non_professional : public Employee {

public:
	non_professional();
	void calc_salary();
	void calc_contributions();
	void calc_vacation();
};


non_professional::non_professional() {
	rate = 0;
	hours = 0;
	salary = 0;
	vacation_days = 0;
	contributions = 0;
}

void non_professional::calc_salary() {
	salary = hours * rate;
}

void non_professional::calc_contributions() {

	if (hours <= 0) {
		cout << "\nThere are not enough hours to deduct health insurance" << endl;
		return;
	}

	if (hours >= 40) {
		contributions += (0.10 * salary);
		salary -= contributions;
	}

	else {
		contributions += (0.05 * salary);
		salary -= contributions;
	}
}

void non_professional::calc_vacation() {
	if (hours >= 40) {
		vacation_days += 1;
	}

	else if (hours >= 25) {
		vacation_days += 0.5;
	}
}

