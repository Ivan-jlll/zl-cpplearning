#include <iostream>
using namespace std;
void print1(int n,char c)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)  
		{
			cout<<c;
		}
		cout<<endl;
	}
}
void print2(int n,char c)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5-i;j++)  
			cout<<' ';
		for(int j=1;j<=2*i-1;j++)
			cout<<c;
		cout<<endl;
	}
}
int main()
{
	print1(5,'*');
	cout<<endl;
	print2(5,'*');
	return 0;
}