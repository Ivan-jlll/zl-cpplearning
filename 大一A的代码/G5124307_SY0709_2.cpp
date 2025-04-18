#include <iostream>
#include <iomanip>
using namespace std;
#define N 4
#define M 5
int sumBorder(int a[][M])
{
	int i,j,sum1=0,sum2=0;
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=M-1;j++)
		{
			sum1+=a[i][j];
		}
	}
	for(i=1;i<N-1;i++)
	{
		for(j=1;j<M-1;j++)
		{
			sum2+=a[i][j];
		}
	}
	return (sum1-sum2);
}
void outputArr(int a[][M])
{
	int i,j;
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=M-1;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}
int main()
{
	int a[N][M]={{3,6,4,6,1},{8,3,1,3,2},{4,7,1,2,7},{2,9,5,3,3}};
	int sum;
	sum=sumBorder(a);
	outputArr(a);
	cout<<"该数组的周边元素之和为："<<sum<<endl;
	return 0;
}