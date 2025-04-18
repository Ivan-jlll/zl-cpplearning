#include <iostream>
#include <cctype>
using namespace std;
const int M = 80;
struct fushu
{
	int shibu;
	int xubu;
};
void input(char a[])
{
	cout << "请输入复数：\n";
	cin >> a;
}
void fushuplus(fushu fs1,fushu fs2,int &a,int &b)
{
	a = fs1.shibu + fs2.shibu;
	b = fs1.xubu + fs2.xubu;
}
void fushuminus(fushu fs1, fushu fs2, int& a, int& b)
{
	a = fs1.shibu - fs2.shibu;
	b = fs1.xubu - fs2.xubu;
}
void trans(char b[], fushu &f)
{
	int i = 0;
	f.shibu = 0; 
	f.xubu = 0;
	while (isdigit(b[i]))
	{
		f.shibu = f.shibu * 10 + b[i] - '0';
		i++;
	}
	i++;
	while (isdigit(b[i]))
	{
		f.xubu = f.xubu * 10 + b[i] - '0';
		i++;
	}
}
int main()
{
	int a = 0, b = 0;
	char shuru1[M], shuru2[M];
	fushu f1, f2;
	input(shuru1);
	input(shuru2);
	trans(shuru1, f1);
	trans(shuru2, f2);
	fushuplus(f1, f2, a, b);
	if (b > 0) cout << "两复数的和为：" << a << "+" << b << "i\n";
	else if (b == 0) cout << "两复数的和为：" << a << "\n";
	else cout << "两复数的和为：" << a  << b << "i\n";
	fushuminus(f1, f2, a, b);
	if (b > 0) cout << "两复数的差为：" << a << "+" << b << "i\n";
	else if (b == 0) cout << "两复数的差为：" << a << "\n";
	else cout << "两复数的差为：" << a  << b << "i\n";
	return 0;
}