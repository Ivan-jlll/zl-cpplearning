#include <iostream>
using namespace std;
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<j<<"¡Á"<<i<<'='<<i*j<<'\t';
		}
		cout<<'\n';
	}
	return 0;
}