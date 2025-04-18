#include<iostream>
using namespace std;
int main()
{
	bool isPalindrome(const char[]);
	void forward(int, char[]);    //#①
	int n = 0;
	char s[50];
	cout << "请输入一个正整数：" << endl;
	cin >> n;
	forward(n, s);
	if (isPalindrome(s))
		cout << "该字符串是回文。" << endl;
	else
		cout << "该字符串不是回文。" << endl;
	system("pause");
	return 0;
}

void forward(int n, char s[])
{
	int i = 0, t = 0;
	while (n > 0 && i < sizeof(s))
	{
		t = n % 10;
		n = n / 10;   //#②
		s[i] = static_cast<char>(t + 48);
		i++;
	}
	s[i] = '\0';
	if (n > 0)
		cout << "数组长度不足！截取部分数据：" << endl;
	else
		cout << "已将正整数转换为字符串；" << endl;
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
			last = i-1;   //#③
		}
		else
			return result;
	}
	if (first < last)
	{
		if (s[first] == s[last])   //#④
		{
			first++;
			last--;
			result = isPalindrome(s);
		}
		else
			result = false;
	}
	//first = -1;   //# ⑤???
	return result;
}
