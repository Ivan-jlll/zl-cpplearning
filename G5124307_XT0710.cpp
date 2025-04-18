#include <iostream>
using namespace std;
#define M 5
int add(int a[M][M])
{
	int i,j,sum=0;
	for(i=0;i<M;i++)
	{
		sum+=a[i][i];
		sum+=a[i][M-1-i];	
	}
	if(M%2!=0) sum-=a[M/2][M/2];
	return sum;
}
int main()
{
	int a[M][M]={1,2,3,4,5,2,3,4,5,6,3,4,5,6,7,4,5,6,7,8,5,6,7,8,9};
	cout<<add(a)<<endl;
}