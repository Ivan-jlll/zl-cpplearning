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
	cout << "��������Ӳ�ҵĴ�����";
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (flip() == 0)
			sum++;
	}
	cout << "����ĸ���Ϊ��" << (double)sum / n << endl;
	return 0;
}