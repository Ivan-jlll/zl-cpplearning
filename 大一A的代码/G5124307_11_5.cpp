#include <iostream>
using namespace std;
void dec_to(int num,int base)//num为十进制数，base为转换的进制数
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
	cout<<"请输入十进制数和需要转换的进制：";
	cin>>num>>base;
	dec_to(num,base);
	return 0;
}
