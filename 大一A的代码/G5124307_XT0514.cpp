#include <iostream>
using namespace std;
void binary(int n)
{
	if(n==0) cout<<'0';
	else if(n==1) cout<<'1';
	else if(n>=2) 
	{
		binary(n/2);
		cout<<(n%2==0?'0':'1');
	}
}
int main()
{
	int a;
	cout<<"请输入一个十进制数：";
	cin>>a;
	cout<<"该数的二进制数为：";
	binary(a);
	cout<<endl;
	return 0;
}