#include <iostream>
using namespace std;
int main()
{
	float a,b,c,max;
	cout<<"请输入三个数：";
	cin>>a>>b>>c;
	max=a;
	if(max<b) 
	{
		max=b;
		if(max<c) max=c;
	}
	else
	{
		if(max<c) max=c;
	}
	cout<<max<<endl;
	return 0;
}
