#include<iostream>
using namespace std;
int main()
{
	bool isPalindrome(const char[]);
	void forward(int, char[]);    //#��
	int n = 0;
	char s[50];
	cout << "������һ����������" << endl;
	cin >> n;
	forward(n, s);
	if (isPalindrome(s))
		cout << "���ַ����ǻ��ġ�" << endl;
	else
		cout << "���ַ������ǻ��ġ�" << endl;
	system("pause");
	return 0;
}

void forward(int n, char s[])
{
	int i = 0, t = 0;
	while (n > 0 && i < sizeof(s))
	{
		t = n % 10;
		n = n / 10;   //#��
		s[i] = static_cast<char>(t + 48);
		i++;
	}
	s[i] = '\0';
	if (n > 0)
		cout << "���鳤�Ȳ��㣡��ȡ�������ݣ�" << endl;
	else
		cout << "�ѽ�������ת��Ϊ�ַ�����" << endl;
	cout << s << endl;
}

bool isPalindrome(const char s[])
{
	static int first = -1, last = -1;
	bool result = true;
	if (first == -1)
	{
		int i = 0;
		while (s[i] != '\0')
			i++;
		if (i > 0)
		{
			first = 0;
			last = i-1;   //#��
		}
		else
			return result;
	}
	if (first < last)
	{
		if (s[first] == s[last])   //#��
		{
			first++;
			last--;
			result = isPalindrome(s);
		}
		else
			result = false;
	}
	//first = -1;   //# ��???
	return result;
}
