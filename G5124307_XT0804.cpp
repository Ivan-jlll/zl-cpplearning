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
		cout<<"�������"<<i+1<<"��ѧ����ѧ�š�������סַ"<<endl;
		cout<<"ѧ��:";
		cin>>add[i].num;
		cout<<"����:";
		cin>>add[i].name;
		cin.get();
		cout<<"סַ:";
		cin.getline(add[i].addr,80);
	}
}
void output(address_list add[],int n)
{
	cout<<left<<setw(12)<<"ѧ��"<<left<<setw(20)<<"����"<<left<<setw(50)<<"סַ"<<endl;
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