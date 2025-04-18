#include<iostream>
#include<iomanip>
using namespace std;
struct book
{
	char bookID[20];
	char name[20];
	double price;
};
void input(book bs[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"请输入价格：";
		/*cin>>bs[i].bookID;
		cin>>bs[i].name;*/
		cin>>bs[i].price;
	}
}
double average(book bs[],int n)
{
	double ave,sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=bs[i].price;
	}
	ave=sum/n;
	return ave;
}
int findMax(book bs[],int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(bs[i].price>bs[j].price)j=i;
	}
	return j;
}
void print(book bs[],int n)
{
	cout<<"\t书号\t书名\t\t价格\n";
	for(int i=0;i<n;i++)
	{
		cout<<'\t'<<bs[i].bookID<<'\t'<<bs[i].name<<"\t\t"<<bs[i].price<<endl;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
	}
}
void sort(book bs[],int n)
{
	book bs2;
	int i,j;
	bool flag=true;
	for(i=0;flag&&i<n-1;i++)
	{
		flag=false;
		for(j=0;j<n-1-i;j++)
			if(bs[j].price>bs[j+1].price)
				bs2=bs[j],bs[j]=bs[j+1],bs[j+1]=bs2,flag=true;
	}
}
int main()
{
	int q;double a;
	book books[4]={{"0101","Computer"},{"0102","Programming"},{"0103","Math"},{"0104","English"}};
	input(books,4);
	print(books,4);
	a=average(books,4);
	cout<<"平均价格为："<<a<<endl;
	q=findMax(books,4);
	cout<<"\t书号\t书名\t\t价格\n";
	cout<<'\t'<<books[q].bookID<<'\t'<<books[q].name<<"\t\t"<<books[q].price<<endl;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	sort(books,4);
	print(books,4);
}
