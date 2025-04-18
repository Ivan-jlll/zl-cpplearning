#include <iostream>
using namespace std;
bool isprime(int x)
{
	if(x==2) return true;
	for(int i=2;i<=x/2;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
int main()
{
	int x=100,i=1;
	for(;x<=200;x++)
	{
		if(isprime(x)) 
		{	
			cout<<x<<'\t';
			if(i%8==0) cout<<'\n';
			i++;
		}
	}
	cout<<endl;
	cout<<"100~200内所有素数的个数为："<<i-1<<endl;
	return 0;
}