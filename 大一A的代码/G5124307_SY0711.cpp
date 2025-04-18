#include <iostream>
using namespace std;
#define M 80
int main()
{
	char str1[M];
	int i,j=0,k=0,l=0,m=0,n=0,p=0;
	cout<<"请输入一行字符串:\n";
	cin.getline(str1,M);
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]>=65&&str1[i]<=90) j++;
		else if(str1[i]>=97&&str1[i]<=122) k++;
		else if(str1[i]>=48&&str1[i]<=57) l++;
		else if(str1[i]==' ') m++;
		else n++;
	}
	cout<<"字符串中大写字母出现的次数为："<<j<<endl;
	cout<<"字符串中小写字母出现的次数为："<<k<<endl;
	cout<<"字符串中数字字符出现的次数为："<<l<<endl;
	cout<<"字符串中空格出现的次数为："<<m<<endl;
	cout<<"字符串中其他字符出现的次数为："<<n<<endl;
	return 0;
}