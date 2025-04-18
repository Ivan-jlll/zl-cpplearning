#include <iostream>
using namespace std;
bool wanshu(int n)
{
	int sum=0;
	if(n<=0||n==1) return false;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i==0) sum+=i;
	}
	if(sum==n) return true;
	else return false;
}
int main()
{
	for(int i=1;i<=1000;i++)
	{
		if(wanshu(i))
		{
			cout<<i<<' '<<"its factors are: ";
			for(int j=1;j<=i/2;j++)
			{
				if(i%j==0) cout<<j<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}