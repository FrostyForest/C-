#include <iostream>
using namespace std;
class Point {
private:
	
public:
	double x;
	double y;
	Point(double a,double b) {
		x = a;
		y = b;
	}
};

class line {
private:
	double a;
	double b;
public:
	line(double x, double y) {
		a = x;
		b = y;
	}
	void print() {
		cout << "y=" << a << "x+" << b << endl;
	}
	friend	Point setPoint(line& l0, line& l1);
};

Point setPoint(line& l0, line& l1) {
	double x = (1 * -l1.b - 1 * -l0.b) / (-l0.a - (-l1.a));
	double y= (-l1.a * -l0.b - (-l0.a) * -l1.b) / (-l0.a - (-l1.a));
	return Point(x, y);
}

int main(){
	line l0(1, 0);
	line l1(-1, 1);
	l0.print();
	l1.print();
	Point c = setPoint(l0, l1);
	cout << "交点横坐标为" << c.x << " 交点纵坐标为" << c.y << endl;
	return 0;
	
}