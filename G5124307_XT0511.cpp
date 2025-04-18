#include <iostream>
using namespace std;
void reverse(int a)
{
	if (a>0)
	{
		cout << a % 10;
		reverse(a / 10);
	}
}
int main()
{
	int a;
	cin >> a;
	reverse(a);
	return 0;
}