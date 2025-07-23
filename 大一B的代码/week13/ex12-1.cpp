#include <iostream>
using namespace std;

class Point {
protected:
	int x, y;
public:
	Point(int _x=0,int _y=0):x(_x),y(_y){}
	Point(const Point &p);
	void setPoint(int, int);
	void getPoint(int *, int *);
	void show();
	~Point(){
	}
};
Point::Point(const Point &p) {
	x = p.x;
	y = p.y;
}
void Point::setPoint(int a, int b) {
	x = a; y = b;
}
void Point::getPoint(int *xp, int *yp) {
	*xp = x; *yp = y;
}
void Point::show() {
	cout << "点坐标为: " << "( " << x << ", " << y << " )\n";
}

class Circle : public Point
{
protected:
	int radius;
public:
	Circle(int a=0,int b=0,int c=0):Point(a,b),radius(c){}
	Circle(const Circle &c) {
		x = c.x; y = c.y; radius = c.radius;
	}
	void setRadius(int r) {
		radius = r;
	}
	void getRadius(int &r) {
		r = radius;
	}
	double area() {
		return 3.1415*radius*radius;
	}
	void show() {
		cout << "圆心坐标为: " << "( " << x << ", " << y << " )\n";
		cout << "圆半径为: " << radius << endl;
		cout << "圆的面积为: " << area() << endl;
	}
};

class Cylinder :public Circle
{
protected:
	int height;
public:
	Cylinder(int a = 0, int b = 0, int r = 0, int h = 0):Circle(a,b,r),height(h) {}
	Cylinder(const Cylinder &cy) {
		x = cy.x; y = cy.y; radius = cy.radius; height = cy.height;
	}
	void setHeight(int h) {
		height = h;
	}
	void getHeight(int *hp) {
		*hp = height;
	}
	double volume() {
		return area()*height;
	}
	void show() {
		cout << "圆心坐标为: " << "( " << x << ", " << y << " )\n";
		cout << "半径为: " << radius << endl;
		cout << "圆柱的高为: " << height << endl;
		cout << "圆柱的体积为: " << volume() << endl;
	}
};

int main() {
	Cylinder cy1, cy2, cy3, cy4(0, 0, 4, 5);
	cy1.show(); cout << endl; cy2.show(); cout << endl; cy3.show(); cout << endl; cy4.show(); cout << endl;
	
	cy1.setPoint(1, 1);
	int a=2, b=6;
	cy1.getPoint(&a, &b);
	cout << "getPoint函数得到圆心坐标为: " << "( " << a << ", " << b << " )\n";
	cout << endl;
	cy1.show();
	cout << endl;
	cout << "Point show成员函数调用: \n";
	cy1.Point::show();
	cout << endl;
	
	cy2.setRadius(8);
	int r;
	cy2.getRadius(r);
	cout << "Circle getRadius 函数得到半径为: " << r << endl;
	cout << endl;
	cy2.show();
	cout << endl;
	cout << "area 函数圆的面积为: " << cy2.area() << endl;
	cout << "Circle show成员函数调用: \n";
	cy2.Circle::show();
	cout << endl;

	cy3.setRadius(1);
	cy3.setHeight(1);
	int h;
	cy3.getHeight(&h);
	cout << "cylinder getHEight 函数得到高为: " << h << endl;
	cout << endl;
	cout << "volume 函数体积为: " << cy3.volume() << endl;
	cout << endl;
	cout << "Cylinder show成员函数调用: \n";
	cy3.Cylinder::show();
	return 0;
}