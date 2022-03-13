#include <iostream>
using namespace std;
class student {
	
private:
	int score;
	static double total;
	static int count;
public:
	void scoretotalcount(double s);
	static double sum();
	static double average();

};

void student::scoretotalcount(double s) {
	score = s;
	total = total + s;
	++count;
}

double student::total=0.0;
int student::count=0;

double student::sum() {
	return total;
}

double student::average() {
	return total/count;
}

int main(){
	
	student a; student b; student c;
	a.scoretotalcount(99.5);
	b.scoretotalcount(91.5);
	c.scoretotalcount(60.5);
	cout << "总分是" << a.sum()<<" 平均分是"<<a.average();
	return 0;
}