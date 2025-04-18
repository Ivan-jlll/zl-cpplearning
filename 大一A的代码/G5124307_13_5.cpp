#include<iostream>
using namespace std;
int zuhenum(int n,int k)
{	
	if (k==0||k==n)
        return 1;
    return zuhenum(n-1, k-1) + zuhenum(n-1,k);
}
void yanghui(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		int p=1;
		for(j=0;j<=i;j++)
		{
			cout<<zuhenum(i,j)<<'\t';
		}
		cout<<endl;
	}
}
int main()
{
	int a;
	cout<<"Lines are:";
	cin>>a;
	yanghui(a);
	return 0;
}