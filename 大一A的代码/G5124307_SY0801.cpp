#include<iostream>
#include<cmath>
using namespace std;
struct Point{
	double x;
	double y;
};
Point Input()
{
	Point p;
	cin>>p.x;
	cin>>p.y;
	return p;
}
void Output(Point p)
{
	cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}
double Dist(Point &p1,Point &p2)
{
	double len;
	len=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	return len;
}
int main()
{
	double len;
	Point p1={0,0},p2={0,0};
	p1=Input();
	p2=Input();
	Output(p1);
	Output(p2);
	len=Dist(p1,p2);
	cout<<len<<endl;
}