#include<iostream>
using namespace std;
#include <iomanip>
struct address_list
{
	char num[10];
	char name[20];
	char addr[80];
}addrlist[3];
void input(address_list add[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"名学生的学号、姓名和住址"<<endl;
		cout<<"学号:";
		cin>>add[i].num;
		cout<<"姓名:";
		cin>>add[i].name;
		cin.get();
		cout<<"住址:";
		cin.getline(add[i].addr,80);
	}
}
void output(address_list add[],int n)
{
	cout<<left<<setw(12)<<"学号"<<left<<setw(20)<<"姓名"<<left<<setw(50)<<"住址"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<left<<setw(12)<<add[i].num<<left<<setw(20)<<add[i].name<<left<<setw(50)<<add[i].addr<<endl;
	}
}
int main()
{
	input(addrlist,3);
	output(addrlist,3);
	return 0;
}