#include <iostream>
using namespace std;
int pn(int x,int n)
{
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n > 1) return (2 * n - 1) * x * pn(x, n - 1) - (n - 1)*pn(x, n - 2) / n;

}
int main()
{
	int n, x;
	cout << "请输入n和x的值：\n";
	cin >> n >> x;
	cout << pn(x, n);
}