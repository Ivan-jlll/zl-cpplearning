#include <iostream>
using namespace std;
#define N 10
#define M 10
void my_strcpy(char s1[],char s2[])
{
	int i=0;
	while(s2[i]!='\0')
		s1[i]=s2[i++];
	s1[i]='\0';
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
	char s1[N]={'a','f','h','1','5'},s2[M]={'e','r','r','o','r'};
	my_strcpy(s1,s2);
	OdOutputArr(s1);
	OdOutputArr(s2);
	return 0;
}