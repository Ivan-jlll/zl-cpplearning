#include <iostream>
#include <iomanip>
using namespace std;
#define N 4
#define M 5
int sumBorder(int a[][M])
{
	int i,j,sum=0;
	for(i=0;i<=N-1;i++)
	{
		for(j=0;j<=M-1;j++)
		{
			if(i==0||i==N-1) sum+=a[i][j];
			else if(j==0||j==M-1) sum+=a[i][j];
		}
	}
	return sum;
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
	cout<<"��������ܱ�Ԫ��֮��Ϊ��"<<sum<<endl;
	return 0;
}