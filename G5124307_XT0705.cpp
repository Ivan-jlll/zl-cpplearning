#include <iostream>
using namespace std;
void turnss(int a)
{
	char siteen[15] = { '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char b[80] = { '0' };
	int i = 0;
	while (a != 0)
	{
		b[i++] = siteen[a % 16 - 1];
		a /= 16;
	}
	cout << "��ʮ��������Ӧ��ʮ��������Ϊ��";
	for (; i >= 0; i--)
	{
		cout<< b[i];
	}
	cout << endl;
}
int main()
{
	int a;
	for (int j = 1; j <= 5; j++) 
	{
		cout << "������һ��ʮ��������";
		cin >> a;
		turnss(a);
	}
	return 0;
}