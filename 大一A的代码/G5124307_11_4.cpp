#include <iostream>
using namespace std;
int main()
{
	int a[15],b,i=0,k=1,m;
	cout<<"������һ������";
	cin>>b;
	m=b;
	while(m>0)
	{
		a[i++]=m%10;
		m/=10;
	}
	for(int j=0;j<=i;j++)
	{
		if(a[j]==a[i-1-j]) k*=1;
		else k*=2;
	}
	if(k==1)cout<<b<<"�ǻ�����";
	else cout<<b<<"���ǻ�����";
}