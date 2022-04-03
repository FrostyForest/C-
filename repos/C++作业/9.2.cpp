#include<iostream>
using namespace std;
class employee {
protected:
	double basic_salary;
public:
	employee(double x) {
		basic_salary = x;
	}
	virtual double monthlySalary() { return basic_salary; };
	virtual ~employee() {};
};
class teacher :public employee{
protected:
	string title;
	double lessonHours;
public:
	teacher(double basicsSalary, string t, double h ) :employee(basicsSalary) {
		title = t;
		lessonHours = h;
	}
	~teacher() {};
	virtual double monthlySalary() {
		double titleSupply;
		if (title == "professor") titleSupply = 50.0;
		if (title == "associate professor") titleSupply = 30.0;
		if (title == "lecturer") titleSupply = 20.0;
		return basic_salary + lessonHours * titleSupply;
	}
};
class administrator :public employee {
protected:
	double jobSalary;
public:
	administrator(double basicsSalary,double m) :employee(basicsSalary) {
		jobSalary = m;
	}
	~administrator() {};
	virtual double monthlySalary() {
		return basic_salary + jobSalary;
	}
};
class laboratory_technician :public employee {
protected:
	double daySupply;
	double workingdays;
public:
	laboratory_technician(double basicsSalary, double dm, double d) :employee(basicsSalary) {
		workingdays = d;
		daySupply = dm;
	}
	~laboratory_technician() {};
	virtual double monthlySalary() {
		return basic_salary + daySupply * workingdays;
	}
};
int main() {
	employee* p;
	teacher a(1000, "professor", 50);
	p = &a;
	cout << p->monthlySalary();
	return 0;
}
