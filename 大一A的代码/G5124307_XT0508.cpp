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
	cout<<"����������������";
	cin>>a>>b;
	cout<<"����������ʵ����";
	cin>>c>>d;
	cout<<min(a,b)<<endl<<min(c,d)<<endl;
	return 0;
}