#include<iostream>
using namespace std;
#define A 3
#define B 3
#define C 1000
bool isin(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
		if(x==a[i]) return true;
	return false;
}
void intersection(int a[],int an,int b[],int bn,int c[],int &cn)
{
	int k=0;
	for(int i=0;i<an;i++)
	{
		if(isin(b,bn,a[i])) c[k++]=a[i];
	}
	cn=k;
}
void Union(int a[],int an,int b[],int bn,int c[],int &cn)
{
	int k=0;
	for(int i=0;i<an;i++)
	{
		c[k++]=a[i];
	}
	for(int j=0;j<bn;j++)
	{
		if(isin(a,an,b[j])) continue;
		else c[k++]=b[j];
	}
	cn=k;
}
void difference(int a[],int an,int b[],int bn,int c[],int &cn)
{
	int k=0;
	for(int i=0;i<an;i++)
	{
		if(isin(b,bn,a[i])) continue;
		else c[k++]=a[i];
	}
	cn=k;
}
bool same(int a[],int b[],int n)
{
	int k=1;
	for(int i=0;i<n;i++)
	{
		if(isin(b,n,a[i])) k*=1;
		else k+=2;
	}
	if(k==1) return true;
	else return false;
}
int main()
{
	int a[A]={6,2,3};
	int b[B]={3,2,6};
	int cn=0;
	int c[C];
	if(A==B&&same(a,b,B)){
		cout<<"两集合相同！！\n"; return -1;
	}
	intersection(a,A,b,B,c,cn);
	cout<<"两集合的交集为：\n";
	for(int i=0;i<cn;i++)
		cout<<c[i]<<'\t';
	cout<<endl;
	Union(a,A,b,B,c,cn);
	cout<<"两集合的并集为：\n";
	for(int i=0;i<cn;i++)
		cout<<c[i]<<'\t';
	cout<<endl;
	difference(a,A,b,B,c,cn);
	cout<<"两集合的差集为：\n";
	for(int i=0;i<cn;i++)
		cout<<c[i]<<'\t';
	cout<<endl;
	return 0;
}