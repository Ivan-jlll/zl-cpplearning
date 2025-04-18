#include <iostream>
#include <cmath>
using namespace std;

//class Point {
//private:
//	int x;    //ºá×ø±ê
//	int y;    //×Ý×ø±ê
//};

class Line {
private:
	int x1;
	int y1;
	int x2;
	int y2;
public:
	void setPoint1(int x, int y) { x1 = x, y1 = y; }
	void setPoint2(int x, int y) { x2 = x, y2 = y; }
	void getPoint1(int *x, int *y) { *x = x1; *y = y1; }
	void getPoint2(int &x, int &y) { x = x2; y = y2; }
	void outputTowPoint();
	double length();
};

void Line::outputTowPoint() {
	cout << "( " << x1 << ", " << y1 << " ) ,";
	cout << "( " << x2 << ", " << y2 << " )\n";
}
double Line::length() {
	double len = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return len;
}
int main() {
	Line l1;
	l1.setPoint1(1, 2);
	l1.setPoint2(2, 1);
	l1.outputTowPoint();
	cout << l1.length() << endl;
	int x1, y1;
	int x2, y2;
	l1.getPoint1(&x1, &y1);
	l1.getPoint2(x2, y2);
	cout << "( " << x1 << ", " << y1 << " ) ,";
	cout << "( " << x2 << ", " << y2 << " )\n";

}