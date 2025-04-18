#include<iostream>
using namespace std;
#define N 3
#define M 4
int Andot(int a[][M])
{
	int i,j,k=0,m,dot=0;
	bool flag=false;
	for(i=0;i<N;i++)
	{
		k=0;
		for(j=1;j<M;j++)
		{
			if(a[i][j]>a[i][k]) k=j;
		}
		for(m=0;m<N;m++)
		{
			if(a[m][k]<a[i][k]) 
			{flag=true;break;}
		}
		if(flag==false) 
			{dot=a[i][k];}
	}
	return dot;
}
int main()
{
	int a[N][M]={1,2,3,4,4,6,3,5,3,5,7,6};
	cout<<Andot(a)<<endl;
	return 0;
}