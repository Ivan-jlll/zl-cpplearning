#include <iostream>
using namespace std;
int fact(int n)
{
	int i=1,jc=1;
	for(;i<=n;i++)
	{
		jc*=i;
	}
	return jc;
}
int main()
{
	int sum=0,n,i=1;
	cin>>n;
	for(;i<=n;i++)
	{
		sum+=fact(i);
	}
	cout<<sum<<endl;
	return 0;
}