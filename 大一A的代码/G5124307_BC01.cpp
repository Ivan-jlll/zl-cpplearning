#include <iostream>
using namespace std;
#define N 2
#define M 3
void BubbleSortUp(int b[],int n)
{
	int i,j,t;
	bool flag=true;
	for(i=0;flag&&i<n-1;i++)
	{ 
		flag=false;
		for(j=n-1;j>i;j--)
		{
			if(b[j-1]>b[j])
				t=b[j-1],b[j-1]=b[j],b[j]=t,flag=true;
		}
	}
}
void TdRefOd(int a[N][M],int b[])
{
	int i,j,k=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			b[k++]=a[i][j];
	}
}
void OdRefTd(int b[],int n,int a[N][M])
{
	int i,j,k=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			a[i][j]=b[k++];
	}
}
void OdOutputArr(int b[],int n)
{
	for(int i=0;i<n;i++)
		cout<<b[i]<<'\t';
	cout<<endl;
}
void TdOutputArr(int a[N][M])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			cout<<a[i][j]<<'\t';
		cout<<endl;
	}
}
int main()
{
	int a[N][M]={245,53,5,31,43,46},b[N*M];
	cout<<"The two-dimensional array is:\n";
	TdOutputArr(a);
	TdRefOd(a,b);
	BubbleSortUp(b,N*M);
	cout<<"The correct sort of one-dimensional array is:\n";
	OdOutputArr(b,N*M);
	OdRefTd(b,N*M,a);
	cout<<"The correct sort of two-dimensional array is:\n";
	TdOutputArr(a);
	return 0;
}