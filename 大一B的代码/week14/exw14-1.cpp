#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	static const char *className;
public:
	/*Shape(const char* claN = "Shape") {
		className = claN;	
	}*/
	virtual float area() = 0; //纯虚函数，用于计算面积
	virtual void setData(float a, float b = 0) = 0;  //纯虚函数，用于设置形状的尺寸
	virtual void showName() { cout << "shp. " << className; } //虚函数，用于显示形状的类名
};
const char* Shape::className = "Shape";

class Triangle :public Shape
{
private:
	float w, h; //分别表示三角形的底和高
public:
	Triangle(float _w, float _h = 0):w(_w), h(_h) {}
	float area() override //重写基类的方法，计算三角形的面积
	{
		return w * h * 0.5;
	}

	void setData(float w, float h = 0) override //重写基类的方法，设置三角形的底和高
	{
		this->w = w; this->h = h;
	}
	void showName() override { cout << "tri. " << className; } //重写基类的方法，显示类名。
};
class Rectangle :public Shape
{
private:
	float w, h; //分别表示矩形的宽和高
	static const char *className;
public:
	Rectangle(float _w, float _h = 0) :w(_w), h(_h) {}
	float area() override  //重写基类的方法，计算矩形的面积。
	{
		return w * h;
	}
	void setData(float w, float h = 0) override   //重写基类的方法，设置矩形的宽和高。
	{
		this->w = w; this->h = h;
	}
	void showName() override { cout << "rect. " << className; } //重写基类的方法，显示类名。

};
const char* Rectangle::className = "Rectangle";
class Square :public Shape
{
private:
	float s; // 表示正方形的边长
public:
	Square(float _w = 0) :s(_w) {}
	float area() override //重写基类的方法，计算正方形的面积。
	{
		return s * s;
	}
	void setData(float s, float = 0) override //重写基类的方法，设置正方形的边长。
	{
		this->s = s;
	}
	void showName() override { cout << "sqr " << className; }//重写基类的方法，显示类名。

};
class Circle:public Shape
{
private:
	float r; //表示圆的半径
public:
	Circle(float _w = 0) :r(_w) {}
	float area() //计算圆的面积。
	{
		return 3.14*r*r;
	}
	void setData(float r, float = 0) //设置圆的半径
	{
		this->r = r;
	}

};
int main()
{
	Shape *p;
	Triangle t(3, 4);
	Rectangle r(5, 6);
	Square s(7);
	Circle c(8);

	p = &t;
	p->showName();
	cout << " area: " << p->area();
	p->setData(6, 8);
	cout << " -> " << p->area() << endl;

	p = &r;
	p->showName();
	cout << " area: " << p->area();
	p->setData(10, 8);
	cout << " -> " << p->area() << endl;

	p = &s;
	p->showName();
	cout << " area: " << p->area();
	p->setData(5);
	cout << " -> " << p->area() << endl;

	p = &c;
	p->showName();
	cout << " area: " << p->area();
	p->setData(1);
	cout << " -> " << p->area() << endl;
	return 0;
}