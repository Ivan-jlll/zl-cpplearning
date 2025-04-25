#include <iostream>
using namespace std;

class Complex {
private:
	int real;
	int imagine;
public:
	Complex(int i = 0, int j = 0) :real(i), imagine(j) {}
	Complex& operator = (const Complex &com);
	Complex& operator += (const Complex &com);
	friend Complex operator+ (const Complex &com1, const Complex &com2);
	friend Complex operator- (const Complex &com1, const Complex &com2);
	void show();
};
Complex& Complex::operator = (const Complex &com) {
	this->real = com.real;
	this->imagine = com.imagine;
	return *this;
}
Complex& Complex::operator += (const Complex &com) {
	this->real += com.real;
	this->imagine += com.imagine;
	return *this;
}
void Complex::show() {
	if(imagine==0) cout<< "复数表示为：  " << real << endl;
	else cout << "复数表示为：  " << real << '+' << imagine << "i\n";
}

Complex operator+ (const Complex &com1,const Complex &com2) {
	return(Complex(com1.real + com2.real, com1.imagine + com2.imagine));
}

Complex operator- (const Complex &com1, const Complex &com2) {
	return(Complex(com1.real - com2.real, com1.imagine - com2.imagine));
}

int main() {
	Complex com1, com2;
	com1.show();
	com2.show();
	Complex com3(1, 5);
	Complex com4(5, 6);
	com1 = com3;
	com1.show();
	com2 += com4;
	com2.show();
	Complex com5, com6;
	com5 = com4 + com3;
	com6 = com4 - com3;
	com5.show();
	com6.show();
	return 0;
}