#include <iostream>
#include <cstring>
using namespace std;
int count_the(char a[])
{
	char b[] = " the ";
	char c[] = " The ";
	int lena = strlen(a);
	int lenb = strlen(b);
	int count=0;
	for (int i = 0; i <= lena - lenb; i++)
	{
		bool flag = true;
		for (int j = 0; j < lenb; j++)
		{
			if (b[j] != a[i + j])
			{
				flag = false; break;
			}
		}
		if (flag) count++;
	}
	for (int i = 0; i <= lena - lenb; i++)
	{
		bool flag = true;
		for (int j = 0; j < lenb; j++)
		{
			if (c[j] != a[i + j])
			{
				flag = false; break;
			}
		}
		if (flag) count++;
	}
	return count;
}
int main()
{
	char a[1000];
	cout << "���������£�\n";
	cin.getline(a, 1000);
	cout << "the�ĸ�����" << count_the(a) << "��";
	return 0;
}