#include <iostream>
using namespace std;

int gcd(int, int); //求最大公因子

class fraction
{
private:
	int numerator;   //分子
	int denominator; //分母

	void reduce(); //分数形式化简

public:
	fraction(int n = 0, int d = 1); //默认构造函数, 默认初始化为0
	fraction add(fraction f2);      //加法, 返回fraction对象
	fraction sub(fraction f2);      //减法, 返回fraction对象
	fraction mult(fraction f2);     //乘法, 返回fraction对象
	fraction div(fraction f2);      //除法, 返回fraction对象
	void print() const;             // 以a/b形式输出分数
	void read();                    //命令行读入分子和分母并化简
};

fraction::fraction(int n, int d) : numerator(n), denominator(d)
{
	if (denominator == 0)
	{
		cout << "divided-by-0 error" << endl;
		exit(1); //退出程序
	}
	reduce(); //构造分数时化简
}

// 补足其余成员函数实现
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

// 实现 gcd 函数
int gcd(int x, int y) {
	int res = x % y;
	if (res == 0) return y;
	return gcd(y, res);
}

int main()
{
	fraction f1, f2, f3{ 2, 4 }, f4{ 3 };

	//加法
	f1.read();
	f1.print(); //输出: 1/6
	f2.read();
	f2.print();         //输出: 1/2
	f1.add(f2).print(); // 输出: 2/3
	f3.print();         //输出: 1/2
	f4.print();         //输出: 3/1

	// 补充对类的测试
	//减法
	fraction f21, f22;
	f21.read();
	f21.print(); //输出: 2/3
	f22.read();
	f22.print();         //输出: 1/2
	f21.sub(f22).print(); // 输出: 1/6
	//乘法
	fraction f31, f32;
	f31.read();
	f31.print(); //输出: 2/3
	f32.read();
	f32.print();         //输出: 1/2
	f31.mult(f32).print(); // 输出: 1/3
	//除法
	fraction f41, f42;
	f41.read();
	f41.print(); //输出: 2/3
	f42.read();
	f42.print();         //输出: 2/5
	f41.div(f42).print(); // 输出: 5/3
	return 0;
}
