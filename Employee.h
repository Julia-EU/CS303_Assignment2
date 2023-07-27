#pragma once
#include <iostream>

using namespace std;

class Employee {
protected:
	float rate = 0;
	float hours = 0;
	float salary = 0; //weekly or monthly
	float vacation_days = 0;
	float contributions = 0;

public:
	float get_rate() {
		return rate;
	}

	void set_rate(float n) {
		rate = n;
	}

	float get_hours() {
		return hours;
	}

	void reset() {
		hours = 0; //set hours back to zero per week or month
	}

	void set_hours(float n) {
		hours = n;
	}

	float get_salary() {
		return salary;
	}

	float get_vacation() {
		return vacation_days;
	}

	float get_contributions() {
		return contributions;
	}

	virtual void calc_salary() = 0; 

	virtual void calc_vacation() = 0;

	virtual void calc_contributions() = 0;
	
};

void Employee::calc_salary() {
	cout << "This is a pure virtual function" << endl;
}

void Employee::calc_vacation() {
	cout << "This is a pure virtual function" << endl;
}

void Employee::calc_contributions() {
	cout << "This is a pure virtual function" << endl;
}

