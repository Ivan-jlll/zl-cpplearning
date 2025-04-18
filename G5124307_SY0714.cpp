#include <iostream>
using namespace std;
#include <cstring>
#define M 80
void reverse(char s[])
{
	int len,i;
	len=strlen(s);
	for(i=0;i<len/2;i++)
	{
		int m;
		m=s[i],s[i]=s[len-1-i],s[len-1-i]=m;
	}
	s[len]='\0';
	i=0;
	while(s[i]!='\0')
		cout<<s[i++];
	cout<<endl;
}
int main()
{
	char s[M];
	strcpy(s,"abcdefghijk");
	reverse(s);
	return 0;
}