#include<iostream>
using namespace std;

int x , y, z;
float p, q, r;
char ab, cd , ef;
double aa, bb, cc;//定义int,float,char,double类型的全局变量
int main()
{
	int a, b, c;
	float m, n, o;
	char d, e, f;
	double s, t, i;
	cout << "int类型局部变量的地址为:\n";
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;//观察int类型局部变量的地址；
	cout << "float类型局部变量的地址为:\n";
	cout << &m << endl;
	cout << &n << endl;
	cout << &o << endl;//观察float类型局部变量的地址；
	cout << "char类型局部变量的地址为:\n";
	cout << static_cast<void*>(&d) << endl;
	cout << static_cast<void*>(&e) << endl;
	cout << static_cast<void*>(&f) << endl;//观察char类型局部变量的地址；
	cout << "double类型局部变量的地址为:\n";
	cout << &s << endl;
	cout << &t << endl;
	cout << &i << endl;//观察double类型局部变量的地址；

	cout << "int类型全局变量的地址为:\n";
	cout << &x << endl;
	cout << &y << endl;
	cout << &z << endl; //观察int类型全局变量的地址；
	cout << "float类型全局变量的地址为:\n";
	cout << &p << endl;
	cout << &q << endl;
	cout << &r << endl;//观察float类型全局变量的地址；
	cout << "char类型全局变量的地址为:\n";
	cout << static_cast<void*>(&ab) << endl;
	cout << static_cast<void*>(&cd) << endl;
	cout << static_cast<void*>(&ef) << endl;//观察char类型全局变量的地址；
	cout << "double类型全局变量的地址为:\n";
	cout << &aa << endl;
	cout << &bb << endl;
	cout << &cc << endl;//观察double类型全局变量的地址；
	
	static int h, j, k;
	static float l , p1, q1 ;
	static char r1, u , v;
	static double w, ss, r3 ;
	cout << "int类型静态局部变量的地址为:\n";
	cout << &h << endl;
	cout << &j << endl;
	cout << &k << endl; //观察int类型静态局部变量的地址；
	cout << "float类型静态局部变量的地址为:\n";
	cout << &l << endl;
	cout << &p1 << endl;
	cout << &q1 << endl;//观察float类型静态局部变量的地址；
	cout << "char类型静态局部变量的地址为:\n";
	cout << static_cast<void*>(&r1) << endl;
	cout << static_cast<void*>(&u) << endl;
	cout << static_cast<void*>(&v) << endl;//观察char类型静态局部变量的地址；
	cout << "double类型静态局部变量的地址为:\n";
	cout << &w << endl;
	cout << &ss << endl;
	cout << &r3 << endl;//观察double类型静态局部变量的地址；
	return 0;
}