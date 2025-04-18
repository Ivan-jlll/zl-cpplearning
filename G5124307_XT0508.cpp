#include <iostream>
using namespace std;
int min(int a,int b)
{
	return (a>b?b:a);
}
double min(double a,double b)
{
	return (a>b?b:a);
}
int main()
{
	int a,b;
	double c,d;
	cout<<"请输入两个整数：";
	cin>>a>>b;
	cout<<"请输入两个实数：";
	cin>>c>>d;
	cout<<min(a,b)<<endl<<min(c,d)<<endl;
	return 0;
}