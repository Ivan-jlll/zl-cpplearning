#include <iostream>
using namespace std;
int main()
{
	int a,power,r;
	float jin;
	cout<<"请输入您的收入：";
	cin>>a;//初始变量a为收入的值；
	power=a/1000;
	switch(power)
	{
		case 0:r=2;break;
		case 1:r=3;break;
		case 2:
		case 3:
		case 4:r=4;break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:r=5;break;
		default:r=6;
	}
	jin=a*r*(0.01);
	cout<<jin<<endl;
	return 0;
}