#include <iostream>
using namespace std;
template<typename T>
class Vector {
private:
	T *v;
	int len;
public:
	Vector(int size);
	Vector(const T*, int);
	~Vector();
	T& operator[](int i)const;
	Vector& operator =(const Vector&);
	friend Vector operator +(const Vector&, const Vector&);
	friend Vector operator -(const Vector&, const Vector&);
	friend Vector operator *(const Vector&, const Vector&);
	friend ostream& operator <<(ostream& output, const Vector&);
	friend istream& operator >>(istream& input, Vector&);
};

template<typename T>Vector<T>::Vector(int size) {//构造指定长度向量，并初始化数据元素为0
	if (size <= 0 || size > 100) {
		cout << "The size of" << size << "is fail!" << endl;
		exit(0);
	}
	v = new T[size];
	for (int i = 0; i < size; i++) {
		v[i] = 0.0;
	}
	len = size;
}

template<typename T>Vector<T>::Vector(const double* B, int size) {//用浮点数组构造向量
	if (size <= 0 || size > sizeof(B)) {
		cout << "The size of" << size << "is fail!" << endl;
		exit(0);
	}
	v = new T [size];
	for (int i = 0; i < size; i++) {
		v[i] = B[i];
	}
	len = size;
}

template<typename T>Vector<T>::~Vector() {//析构
	delete[] v;
	len = 0;
}

template<typename T> T& Vector<T>::operator[](int i)const {//访问元素
	if (i < 0 || i >= len) {
		cout << "The subscript" << i << "is outside!" << endl;
		exit(0);
	}
	return v[i];
}

template<typename T> Vector& Vector<T>::operator =(const Vector& B) {//向量赋值
	if (len != B.len) {
		cout << "=fail!" << endl;
		exit(0);
	}
	for (int i = 0; i < len; i++) {
		v[i] = B.v[i];
	}
	return *this;
}

Vector operator +(const Vector& A, const Vector& B) {
	if (A.len != B.len) {
		cout << "operator+fail!" << endl;
		exit(0);
	}
	double* N = new double[A.len];
	for (int i = 0; i < A.len; i++) {
		N[i] = A.v[i] + B.v[i];
	}
	return Vector(N, A.len);
}

Vector operator-(const Vector& A, const Vector& B) {
	if (A.len != B.len) {
		cout << "operator+fail!" << endl;
		exit(0);
	}
	double* N = new double[A.len];
	for (int i = 0; i < A.len; i++) {
		N[i] = A.v[i] - B.v[i];
	}
	return Vector(N, A.len);
}

Vector operator*(const Vector& A, const Vector& B) {
	if (A.len != B.len) {
		cout << "operator+fail!" << endl;
		exit(0);
	}
	double* N = new double[A.len];
	for (int i = 0; i < A.len; i++) {
		N[i] = A.v[i] * B.v[i];
	}
	return Vector(N, A.len);
}

ostream& operator <<(ostream& output, const Vector& A) {
	for (int i = 0; i < A.len; i++) {
		output << A.v[i] << " ";
	}
	return output;
}

istream& operator >>(istream& input, Vector& A) {
	for (int i = 0; i < A.len; i++) {
		input >> A.v[i];
	}
	return input;
}

int main() {
	int l;
	cout << "Input the length of Vector:" << endl;
	cin >> l;
	Vector<double> A(l), B(l);
	cout << "Input the elements of Vector A:" << endl;
	cin >> A;
	cout << "Input the elements of Vector B" << endl;
	cin >> B;
	Vector C(l);
	C = A + B;
	cout << C;
	return 0;

}