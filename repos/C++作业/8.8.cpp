#include <iostream>
#include <vector>
using namespace std;

class RMB {
protected:
	double rmb;
public:
	RMB() {};
	RMB(double a):rmb(a) {
	};
	void print() {
		cout << rmb<<endl;
	}
	RMB operator+(RMB& b) {
		RMB temp(0.0);
		temp.rmb = rmb + b.rmb;
		return temp;
	}
};


class member {
protected:
	static int number;
	int ownNumber;
	string name;
	int password;
	int phone_number;
public:
	member() {
		ownNumber = number++;
	}
	void input() {
		cout << "input your name" << endl;
		cin >> name;
		cout << "input your password" << endl;
		cin >>password;
		cout << "input your phone number" << endl;
		cin >> phone_number;
	}
	string output_name() {
		return name;
	}
	int output_phonenumber() {
		return phone_number;
	}
	int output_password() {
		return password;
	}
};
int member::number = 0;

class memberCard :public RMB, public member {
public:
	memberCard() {
		RMB (0);
		member ();
		input();
	}
	void recharge(double x){
		rmb = rmb + x;
	}
	void consume(double x) {
		rmb = rmb - x;
	}
	double remain() {
		return rmb;
	}
};
static double sum_of_consume = 0;
static double sum_of_charge = 0;
void build_new_member(vector<memberCard>& x) {
	memberCard a;
	x.push_back(a);
}
void charge(vector<memberCard>& cardlist,string name,double money) {
	for (auto x : cardlist) {
		if (x.output_name() == name) {
			x.recharge(money);
		}
	}
	sum_of_charge = sum_of_charge + money;
}
void consume(vector<memberCard>& cardlist, string name, double money,int password) {
	for (auto x : cardlist) {
		if (x.output_name() == name&&x.output_password()==password&&(x.remain()-money>=0)) {
			x.consume(money);
		}
	}
	sum_of_consume = sum_of_consume + money;
}
void output(const vector<memberCard>& cardlist) {
	cout << "the number of members is " << cardlist.size()<<endl;
	cout << "sum of charge is " << sum_of_charge<<endl;
	cout << "sum of consume is " << sum_of_consume << endl;
	
}
int main(){
	vector<memberCard> cardList;
	memberCard a;
	memberCard b;
	cardList.push_back(a);
	cardList.push_back(b);
	output(cardList);
	return 0;

}