#include <iostream>
#include <iomanip>
using namespace std;
#define N 3
int count(int a[],int n,int x)
{
	int i,count=0;
	for(i=0;i<n;i++)
		if(x==a[i]) count++;
	return count;
	return 0;
}
int main()
{
	int b[N],num[10],d[(N*3)];
	for(int i=0;i<N;i++)
	{
		b[i]=rand()%900+100;
		cout<<b[i]<<setw(4);
	}
	cout<<'\n';
	for(int i=0,j=0;i<N,j<(3*N);i++)
	{
		while(b[i]>0)
		{
			d[j++]=b[i]%10;
			b[i]/=10;
		}
	}
	for(int j=0;j<10;j++)
	{
		num[j]=count(d,(N*3),j);
		cout<<j<<"的个数有"<<num[j]<<"个\n";
	}
	return 0;
}