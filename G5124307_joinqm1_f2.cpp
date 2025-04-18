#include<iostream>
#include<iomanip>
#include <cstdlib>
using namespace std;
void structure(double *bufer, int row, int col);
void count(double *bufer, double *min, int row, int col);
void output(double *bufer, double *min, int row, int col);
int const M = 3;
int const N = 4;
int main() {
   double arry[M * N];
   double min[N];
   structure(arry, M, N);
   count(arry, min, M, N);
   output(arry, min, M, N);
   return 0;
}
void structure(double *bufer, int row, int col)
{
	int k=0;double p,t;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			p=rand();
			t=rand();
			bufer[k++]=p/t;
		}
	}
}
void count(double *bufer, double *min, int row, int col)
{
	int k,p=0;
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row-1;j++)
		{
			if(bufer[i]>bufer[i+col*(j+1)]) k=i+col*(j+1);
			else k=i;
		}
		min[p++]=bufer[k];
	}
}
void output(double *bufer, double *min, int row, int col)
{
	for(int i=0;i<row*col;i++)
	{
		cout<<setw(12)<<bufer[i];
		if((i+1)%4==0) cout<<endl;
	}
	for(int j=0;j<col;j++)
	{
		cout<<setw(12)<<min[j];
	}
	cout<<endl;
}