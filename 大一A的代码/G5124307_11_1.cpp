#include <iostream>
using namespace std;
bool f(int n,int &m)
{
	int sum1=0,sum2=0;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i==0) 
		{
			sum1+=i;
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		if(sum1%i==0) 
		{
			sum2+=i;
		}
	}
	if(n!=sum1&&sum2==n)
	{
		m=sum1;	return true;
	}
	else return false;
}
int main()
{
	for(int i=1;i<=400;i++)
	{
		int j;
		if(f(i,j)) 
		{cout<<"400以内的亲密对数为："<<i<<' '<<j<<endl;}
	}
	return 0;
}