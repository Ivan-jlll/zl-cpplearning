#include <iostream>
using namespace std;
int const N = 100;
int main()
{
	int n,a[N],i=0,k;
	cout << "������һ����������\n";
	cin >> n;
	k = n;
	while (n > 0)
	{
		a[i++] = n % 10;
		n /= 10;
	}
	cout << k << "���෴��Ϊ��\n";
	for (int j = 0; j < i; j++)
	{
		cout << a[j];
	}
	cout << endl;
	return 0;
}