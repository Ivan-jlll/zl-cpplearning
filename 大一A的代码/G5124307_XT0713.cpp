#include <iostream>
using namespace std;
int stringlen(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}
int isinchar(char a[], char b[])//假设a为主串，b为子串；
{
	int lena, lenb;
	lena = stringlen(a);
	lenb = stringlen(b);
	if (lena < lenb) return -1;
	int k=-1;
	for (int i = 0; i <= lena-lenb; i++)
	{
		bool flag = true;
		for (int j = 0; j < lenb; j++)
		{
			if (b[j] != a[i+j]) 
			{ flag=false; break; }
		}
		if (flag) return i;
	}
	return -1;
}
int main()
{
	char a[] = { "hello world" };
	char b[] = { "world" };
	int c;
	c = isinchar(a, b);
	if (c == -1)cout << "不是字符串的子串！";
	else cout << "子串在主串中的位置为第" << c << "到第" << c + stringlen(b)-1 << "个字符。" << endl;
}