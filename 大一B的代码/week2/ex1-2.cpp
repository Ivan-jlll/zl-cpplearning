#include<iostream>
using namespace std;

int x , y, z;
float p, q, r;
char ab, cd , ef;
double aa, bb, cc;//����int,float,char,double���͵�ȫ�ֱ���
int main()
{
	int a, b, c;
	float m, n, o;
	char d, e, f;
	double s, t, i;
	cout << "int���;ֲ������ĵ�ַΪ:\n";
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;//�۲�int���;ֲ������ĵ�ַ��
	cout << "float���;ֲ������ĵ�ַΪ:\n";
	cout << &m << endl;
	cout << &n << endl;
	cout << &o << endl;//�۲�float���;ֲ������ĵ�ַ��
	cout << "char���;ֲ������ĵ�ַΪ:\n";
	cout << static_cast<void*>(&d) << endl;
	cout << static_cast<void*>(&e) << endl;
	cout << static_cast<void*>(&f) << endl;//�۲�char���;ֲ������ĵ�ַ��
	cout << "double���;ֲ������ĵ�ַΪ:\n";
	cout << &s << endl;
	cout << &t << endl;
	cout << &i << endl;//�۲�double���;ֲ������ĵ�ַ��

	cout << "int����ȫ�ֱ����ĵ�ַΪ:\n";
	cout << &x << endl;
	cout << &y << endl;
	cout << &z << endl; //�۲�int����ȫ�ֱ����ĵ�ַ��
	cout << "float����ȫ�ֱ����ĵ�ַΪ:\n";
	cout << &p << endl;
	cout << &q << endl;
	cout << &r << endl;//�۲�float����ȫ�ֱ����ĵ�ַ��
	cout << "char����ȫ�ֱ����ĵ�ַΪ:\n";
	cout << static_cast<void*>(&ab) << endl;
	cout << static_cast<void*>(&cd) << endl;
	cout << static_cast<void*>(&ef) << endl;//�۲�char����ȫ�ֱ����ĵ�ַ��
	cout << "double����ȫ�ֱ����ĵ�ַΪ:\n";
	cout << &aa << endl;
	cout << &bb << endl;
	cout << &cc << endl;//�۲�double����ȫ�ֱ����ĵ�ַ��
	
	static int h, j, k;
	static float l , p1, q1 ;
	static char r1, u , v;
	static double w, ss, r3 ;
	cout << "int���;�̬�ֲ������ĵ�ַΪ:\n";
	cout << &h << endl;
	cout << &j << endl;
	cout << &k << endl; //�۲�int���;�̬�ֲ������ĵ�ַ��
	cout << "float���;�̬�ֲ������ĵ�ַΪ:\n";
	cout << &l << endl;
	cout << &p1 << endl;
	cout << &q1 << endl;//�۲�float���;�̬�ֲ������ĵ�ַ��
	cout << "char���;�̬�ֲ������ĵ�ַΪ:\n";
	cout << static_cast<void*>(&r1) << endl;
	cout << static_cast<void*>(&u) << endl;
	cout << static_cast<void*>(&v) << endl;//�۲�char���;�̬�ֲ������ĵ�ַ��
	cout << "double���;�̬�ֲ������ĵ�ַΪ:\n";
	cout << &w << endl;
	cout << &ss << endl;
	cout << &r3 << endl;//�۲�double���;�̬�ֲ������ĵ�ַ��
	return 0;
}