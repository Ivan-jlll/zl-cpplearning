#include <iostream>
using namespace std;
#define M 80
int main()
{
	char str1[M];
	int i,j=0,k=0,l=0,m=0,n=0,p=0;
	cout<<"������һ���ַ���:\n";
	cin.getline(str1,M);
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i]>=65&&str1[i]<=90) j++;
		else if(str1[i]>=97&&str1[i]<=122) k++;
		else if(str1[i]>=48&&str1[i]<=57) l++;
		else if(str1[i]==' ') m++;
		else n++;
	}
	cout<<"�ַ����д�д��ĸ���ֵĴ���Ϊ��"<<j<<endl;
	cout<<"�ַ�����Сд��ĸ���ֵĴ���Ϊ��"<<k<<endl;
	cout<<"�ַ����������ַ����ֵĴ���Ϊ��"<<l<<endl;
	cout<<"�ַ����пո���ֵĴ���Ϊ��"<<m<<endl;
	cout<<"�ַ����������ַ����ֵĴ���Ϊ��"<<n<<endl;
	return 0;
}