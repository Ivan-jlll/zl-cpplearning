#include <iostream>
using namespace std;
#define M 3
struct student
{
	char xh[10];
	char name[20];
	int sc;
};
student input()
{
	student stud;
	cout<<"������ѧ�š��������ɼ�"<<endl;
	cin>>stud.xh>>stud.name>>stud.sc;
	return stud;
}
void output(student stud)
{
	cout<<"\t\t"<<stud.xh<<"\t\t"<<stud.name<<"\t\t"<<stud.sc<<endl;
}
int main()
{
	student stud[M];
	int max,k=0;
	for(int i=0;i<M;i++)
	{
		stud[i]=input();
	}
	cout<<"\t"<<"ѧ��"<<"\t\t"<<"����"<<"\t\t"<<"�ɼ�"<<endl;
	for(int i=0;i<M;i++)
		output(stud[i]);
	for(int j=1;j<M;j++)
	{
		max=stud[k].sc;
		if(stud[j].sc>stud[k].sc) k=j;
	}
	cout<<"��߷�Ϊ��"<<endl;
	cout<<"\t"<<"ѧ��"<<"\t\t"<<"����"<<"\t\t"<<"�ɼ�"<<endl;
	output(stud[k]);
	return 0;
}