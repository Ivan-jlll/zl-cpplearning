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
	virtual float area() = 0; //���麯�������ڼ������
	virtual void setData(float a, float b = 0) = 0;  //���麯��������������״�ĳߴ�
	virtual void showName() { cout << "shp. " << className; } //�麯����������ʾ��״������
};
const char* Shape::className = "Shape";

class Triangle :public Shape
{
private:
	float w, h; //�ֱ��ʾ�����εĵ׺͸�
public:
	Triangle(float _w, float _h = 0):w(_w), h(_h) {}
	float area() override //��д����ķ��������������ε����
	{
		return w * h * 0.5;
	}

	void setData(float w, float h = 0) override //��д����ķ��������������εĵ׺͸�
	{
		this->w = w; this->h = h;
	}
	void showName() override { cout << "tri. " << className; } //��д����ķ�������ʾ������
};
class Rectangle :public Shape
{
private:
	float w, h; //�ֱ��ʾ���εĿ�͸�
	static const char *className;
public:
	Rectangle(float _w, float _h = 0) :w(_w), h(_h) {}
	float area() override  //��д����ķ�����������ε������
	{
		return w * h;
	}
	void setData(float w, float h = 0) override   //��д����ķ��������þ��εĿ�͸ߡ�
	{
		this->w = w; this->h = h;
	}
	void showName() override { cout << "rect. " << className; } //��д����ķ�������ʾ������

};
const char* Rectangle::className = "Rectangle";
class Square :public Shape
{
private:
	float s; // ��ʾ�����εı߳�
public:
	Square(float _w = 0) :s(_w) {}
	float area() override //��д����ķ��������������ε������
	{
		return s * s;
	}
	void setData(float s, float = 0) override //��д����ķ��������������εı߳���
	{
		this->s = s;
	}
	void showName() override { cout << "sqr " << className; }//��д����ķ�������ʾ������

};
class Circle:public Shape
{
private:
	float r; //��ʾԲ�İ뾶
public:
	Circle(float _w = 0) :r(_w) {}
	float area() //����Բ�������
	{
		return 3.14*r*r;
	}
	void setData(float r, float = 0) //����Բ�İ뾶
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