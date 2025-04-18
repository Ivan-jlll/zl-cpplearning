#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip()
{
	return rand() % 2;
}
int main()
{
	srand(time(0));
	int n;
	cout << "请输入抛硬币的次数：";
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (flip() == 0)
			sum++;
	}
	cout << "正面的概率为：" << (double)sum / n << endl;
	return 0;
}