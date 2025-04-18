#include <iostream>
using namespace std;
#define MAX2(a,b) ((a>b)?a:b)
#define MAX3(a,b,c) MAX2(MAX2(a,b),c)
int main()
{
	int a,b,c,d,e,max1,max2;
	cout<<"请输入2个数：";
	cin>>a>>b;
	cout<<"请输入3个数：";
	cin>>c>>d>>e;
	max1=MAX2(a,b);
	max2=MAX3(c,d,e);
	cout<<max1<<endl;
	cout<<max2<<endl;
	return 0;
}