#include <iostream>
using namespace std;

int gcd(int, int); //���������

class fraction
{
private:
	int numerator;   //����
	int denominator; //��ĸ

	void reduce(); //������ʽ����

public:
	fraction(int n = 0, int d = 1); //Ĭ�Ϲ��캯��, Ĭ�ϳ�ʼ��Ϊ0
	fraction add(fraction f2);      //�ӷ�, ����fraction����
	fraction sub(fraction f2);      //����, ����fraction����
	fraction mult(fraction f2);     //�˷�, ����fraction����
	fraction div(fraction f2);      //����, ����fraction����
	void print() const;             // ��a/b��ʽ�������
	void read();                    //�����ж�����Ӻͷ�ĸ������
};

fraction::fraction(int n, int d) : numerator(n), denominator(d)
{
	if (denominator == 0)
	{
		cout << "divided-by-0 error" << endl;
		exit(1); //�˳�����
	}
	reduce(); //�������ʱ����
}

// ���������Ա����ʵ��
void fraction::reduce() {
	int x = gcd(numerator, denominator);
	numerator /= x;
	denominator /= x;
}

fraction fraction::add(fraction f2) {
	int x = gcd(this->denominator, f2.denominator);
	int y = this->denominator*f2.denominator / x;
	this->numerator *= (y / this->denominator);
	f2.numerator *= (y / f2.denominator);
	this->denominator = f2.denominator = y;
	fraction f0(this->numerator + f2.numerator, y);
	f0.reduce();
	return f0;
}

fraction fraction::sub(fraction f2) {
	int x = gcd(this->denominator, f2.denominator);
	int y = this->denominator*f2.denominator / x;
	this->numerator *= (y / this->denominator);
	f2.numerator *= (y / f2.denominator);
	this->denominator = f2.denominator = y;
	fraction f0(this->numerator - f2.numerator, y);
	f0.reduce();
	return f0;
}

fraction fraction::mult(fraction f2) {
	fraction f0(this->numerator*f2.numerator, this->denominator*f2.denominator);
	f0.reduce();
	return f0;
}

fraction fraction::div(fraction f2) {
	fraction f0(this->numerator*f2.denominator, this->denominator*f2.numerator);
	f0.reduce();
	return f0;
}

void fraction::print() const {
	cout << numerator << '/' << denominator << endl;
}

void fraction::read() {
	cin >> numerator;
	cin >> denominator;
	reduce();
}

// ʵ�� gcd ����
int gcd(int x, int y) {
	int res = x % y;
	if (res == 0) return y;
	return gcd(y, res);
}

int main()
{
	fraction f1, f2, f3{ 2, 4 }, f4{ 3 };

	//�ӷ�
	f1.read();
	f1.print(); //���: 1/6
	f2.read();
	f2.print();         //���: 1/2
	f1.add(f2).print(); // ���: 2/3
	f3.print();         //���: 1/2
	f4.print();         //���: 3/1

	// �������Ĳ���
	//����
	fraction f21, f22;
	f21.read();
	f21.print(); //���: 2/3
	f22.read();
	f22.print();         //���: 1/2
	f21.sub(f22).print(); // ���: 1/6
	//�˷�
	fraction f31, f32;
	f31.read();
	f31.print(); //���: 2/3
	f32.read();
	f32.print();         //���: 1/2
	f31.mult(f32).print(); // ���: 1/3
	//����
	fraction f41, f42;
	f41.read();
	f41.print(); //���: 2/3
	f42.read();
	f42.print();         //���: 2/5
	f41.div(f42).print(); // ���: 5/3
	return 0;
}
