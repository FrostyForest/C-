#include <iostream>
using namespace std;
class Box {
private:
	int length,width,height;
public:
	Box(int , int , int );
	void setBox( Box &x,int length,int width,int height);
	int volume() const;
};
Box::Box(int x, int y, int z) {
	length = x;
	width = y;
	height = z;
}
void Box::setBox(Box& x, int length, int width, int height) {
	x.length = length;
	x.width = width;
	x.height = height;
}
int Box::volume() const{
	return height * length * width;
}

int main(){
	Box a(1,2,3);
	int size = a.volume();
	cout << "盒子体积为" << a.volume();
	return 0;
}