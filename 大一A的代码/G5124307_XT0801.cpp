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
	cout<<"请输入学号、姓名、成绩"<<endl;
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
	cout<<"\t"<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"成绩"<<endl;
	for(int i=0;i<M;i++)
		output(stud[i]);
	for(int j=1;j<M;j++)
	{
		max=stud[k].sc;
		if(stud[j].sc>stud[k].sc) k=j;
	}
	cout<<"最高分为："<<endl;
	cout<<"\t"<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"成绩"<<endl;
	output(stud[k]);
	return 0;
}