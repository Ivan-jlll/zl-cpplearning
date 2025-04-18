#include <iostream>
#include <iomanip>
using namespace std;
void InitialArr(int a[],int n)//对数组元素赋初值
{
	int i=0;
	for(;i<n;i++)
		a[i]=rand()%20;
}
void OutputArr(int a[],int n)//输出数组元素
{
	int i=0;
	for(;i<n;i++)
		cout<<a[i]<<setw(4);
	cout<<endl;
}
void SelectSort(int a[],int n)//选择排序
{
	int i,j,p,t;
	for(i=0;i<n-1;i++)
	{
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[p]) p=j;
		}
		if(p!=i)
		{	t=a[p];a[p]=a[i];a[i]=t;}
	}
}
void BubbleSort(int a[],int n)//冒泡排序

{
	int i,j,t;
	bool flag=true;
	for(i=0;flag&&i<n-1;i++)
	{
		flag=false;
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
				flag=true;
			}
	}
}
int merge(int a[],int b[],int c[],int m,int n)//归并排序，返回归并后的数组元素个数
{
	int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
    return k; 
}
int main()
{
	int a[12],b[8],c[20];
	InitialArr(a,12);
	InitialArr(b,8);
	OutputArr(a,12);
	OutputArr(b,8);
	SelectSort(a,12);
	BubbleSort(b,8);
	merge(a,b,c,12,8);
    OutputArr(c,20);
}