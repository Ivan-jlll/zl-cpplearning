#include <iostream>
using namespace std;
void dec_to(int num,int base)//numΪʮ��������baseΪת���Ľ�����
{
	if(num<base) cout<<hex<<num;
	else 
	{
		dec_to(num/base,base);
		cout<<hex<<num%base;
	}
}
int main()
{
	int num,base;
	cout<<"������ʮ����������Ҫת���Ľ��ƣ�";
	cin>>num>>base;
	dec_to(num,base);
	return 0;
}
