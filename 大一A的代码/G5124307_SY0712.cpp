#include <iostream>
using namespace std;
#define N 10
#define M 10
void interCross(char s1[],char s2[],char s3[])
{
	int i=0,j=0,k=0;
	while(s1[i]!='\0'&&s2[j]!='\0')
	{
		s3[k++]=s1[i++];
		s3[k++]=s2[j++];
	}
	while(s1[i]!='\0')
		s3[k++]=s1[i++];
	while(s2[j]!='\0')
		s3[k++]=s2[j++];
	s3[k]='\0';
}
void OdOutputArr(char s3[])
{
	int i=0;
	while(s3[i]!='\0')
	{
		cout<<s3[i];
		i++;
	}
	cout<<endl;
}
int main()
{
	char s1[N]={'a','b','c','d','e','\0'},s2[M]={'1','2','3','\0'},s3[80];
	interCross(s1,s2,s3);
	OdOutputArr(s3);
	return 0;
}