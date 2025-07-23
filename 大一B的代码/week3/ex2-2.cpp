//仔细阅读并理解 local_mean 函数后完善以下程序.
//提示: 利用单步调试或在函数中添加输出语句查看变量取值. 
//从而理解指针运算的规律.代码保存为 ex2 - 2.cpp
#include <iostream>
using namespace std;

double local_mean(double *p, int k);
double local_max(double *p, int k);
double local_min(double *p, int k);

double local_mean(double *p, int k)
{
	double sum = 0.0;
	for (int i = -k; i <= k; i++)
		sum += *(p + i);
	return sum / (2 * k + 1);
}

double local_max(double *p, int k) {
	double max = *(p - k);
	for (int i = -k; i <= k; ++i) {
		if (*(p + i) > max) max = *(p + i);
	}
	return max;
}

double local_min(double *p, int k) {
	double min = *(p-k);
	for (int i = -k; i <= k; ++i) {
		if (*(p + i) < min) min = *(p + i);
	}
	return min;
}

int main()
{
	double arr[] = { 1, 2, 5, 22, 5, -2, -5, -9, -3, 5, 3, -7, 9, 0, 3, -9, 0, 4, 28, 0 };
	double result[30]{};
	int k = 2, N;
	N = sizeof(arr) / sizeof(arr[0]);
	double *p = &arr[k];

	// call local_mean
	// 7    6.4 5   2.2 -2.8    -2.8    -1.8    -2.2    1.4 2   1.6 -0.8    0.6 -0.4    5.2  4.6
	for (int i = 0; i < N - 2 * k; ++i)
		result[i] = local_mean(p + i, k);
	for (int i = 0; i < N - 2 * k; ++i)
		cout << result[i] << '\t';
	cout << endl;

	// call local_max
	// 22   22  22  22  5   5   5   5   9   9   9   9   9   4   28  28
	for (int i = 0; i < N - 2 * k; ++i)
		result[i] = local_max(p + i, k);
	for (int i = 0; i < N - 2 * k; ++i)
		cout << result[i] << '\t';
	cout << endl;

	// call local_min
	// 1    -2  -5  -9  -9  -9  -9  -9  -7  -7  -7  -9  -9  -9  -9  -9
	for (int i = 0; i < N - 2 * k; ++i)
		result[i] = local_min(p + i, k);
	for (int i = 0; i < N - 2 * k; ++i)
		cout << result[i] << '\t';
	cout << endl;

	return 0;
}
