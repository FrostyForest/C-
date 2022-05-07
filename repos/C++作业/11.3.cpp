#include<iostream>
#include<fstream>
using namespace std;
class worker {
public:
	int number{ 1 };
	string name{"null"};
	string  telephoneNumber{"12345"};
	int postalCode{510800};
	string address{"null"};
	worker(int number, string name, string telephoneNumber, int postalCode, string address) {
		worker::number = number;
		worker::name = name;
		worker::telephoneNumber = telephoneNumber;
		worker::postalCode = postalCode;
		worker::address = address;
	}
	~worker() {
		cout << "destroyed" << endl;
	};
	worker() {

	};
};
int main()
{
	fstream f;
	f.open("D:\\TXT.dat",ios::out|ios::binary);
	worker *p=new worker(1, "joe", "110", 510800, "huadu");
	worker x(2, "ben", "120", 510800, "tianhe");
	f.write((char*)&x, sizeof(worker));
	f.write((char*)p, sizeof(worker));
	worker endMark(0, "noname", "nonumber", 0, "noaddress");
	f.write((char*)&endMark, sizeof(worker));
	f.close(); 
	delete p;
	ifstream f1;
	f1.open("D:\\TXT.dat", ios::in|ios::binary);
	f1.seekg(0, ios::beg);
	worker* w = new worker() ;
	int number;
	cout << "please enter worker's number"<<endl;
	cin >>number;
	do {
		f1.read((char*)w, sizeof(worker));
		if (number == w->number) {
			cout << w->name << " " << w->telephoneNumber << " " << w->postalCode << " " << w->address << endl;
			break;
		}
	} while (f1&&w->number!=0);
	f1.close();
	return 0;
}
