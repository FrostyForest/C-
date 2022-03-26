#include<iostream>
using namespace std;
class Employee {
protected:
	int number;
	string name;
	double basicSalary = 2000;
public:
	Employee() {
	}
	double pay(){
		return basicSalary;
	}
	void print() {
		cout << "your monthly salary is " << pay()<<endl;
	}
	void input() {
		cout << "input your number " << endl;
		cin >> number;
		cout << "input your name " << endl;
		cin >> name;
	}
};

class Salesman: public Employee{
protected:
	double sales;
	double commrate = 5.0 / 1000.0;
public:
	Salesman(){}
	void input() {
		Employee::input();
		cout << "input your sales " << endl;
		cin >> sales;
	}
	double pay() {
		return  Employee::pay()+sales * commrate;
	}
	void print() {
		cout << "your monthly salary is " << pay() << endl;
	}
	
};

class Salesmanager :public Salesman {
protected:
	double jobSalary = 3000;
public:
	Salesmanager() {

	}
	double pay() {
		return Salesman::pay() + jobSalary;
	}
	void print() {
		cout << "your monthly salary is " << pay()<<endl;
	}
};
int main() {
	Salesmanager a;
	a.input();
	a.print();
	Salesman b;
	b.input();
	b.print();
	return 0;
}
