#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int i=0,int j=0):x(i),y(j){}
	Point& operator++();//重载前置自增
	Point operator++(int);//重载后置自增
	void show() {
		cout << "该点坐标为：( " << x << ", " << y << " )\n";
	}
	friend Point& operator--(Point& p);
	friend Point operator--(Point& p,int);
	//friend ostream& operator<<(ostream& cout, const Point& p);
};
Point& Point::operator++()//重载前置自增
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)//重载后置自增
{
	Point temp(this->x, this->y);
	x++;
	y++;
	return temp;
}

Point& operator--(Point& p) {   //重载前置自减
	p.x--;
	p.y--;
	return p;
}

Point operator--(Point& p, int) {   //重载后置自减
	Point temp(p.x, p.y);
	p.x--;
	p.y--;
	return temp;
}


int main(){
	Point p1(1, 2), p2(2, 1), p3(5,5), p4(4, 3);
	p1++;
	++p2;
	p3--;
	--p4;
	p1.show();
	p2.show();
	p3.show();
	p4.show();
	Point p5(p1++), p6(p3--);
	p5.show();
	p6.show();
	return 0;
}
//返回引用和返回对象的区别：
//1.返回引用是返回调用对象本身，是对调用方进行的修改操作并返回自身；
//2.返回对象时虽然可能对调用方进行了修改，但是最终返回的对象是经过重新创建后并为其赋相应初值，与调用方本质是两个对象；
//后置运算符重载函数只能返回对象的原因：
//调用方已经被修改，但为了保留调用方原始数据在函数局部作用域下创建新的局部变量并进行保存，但是C++不允许返回局部变量的引用，原因是该变量在函数结束时会被销毁；
//而且后置运算符自身也不要求返回引用，创建一个临时变量保存调用方的初值即可。