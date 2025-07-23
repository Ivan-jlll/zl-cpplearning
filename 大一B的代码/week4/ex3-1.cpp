#include <iostream>
using namespace std;

int fsum(int *array, int n) {
	int i, s = 0;
	for (i = 0; i < n; i++)
		s += array[i];
	return s;
}

int main() {
	int n, k;
	cout << "请输入动态数组的长度：";
	cin >> n;
	int *arr1 = new int[n];
	for (int i = 0; i < n; i++)
		*(arr1 + i) = i + 1;
	cout << "请输入k值，以求出数组前k个和后k个元素的和：";
	cin >> k;
	int shead, stail;
	shead = fsum(arr1, k);
	stail = fsum(arr1 + n - k, k);
	cout << shead << " ," << stail << endl;
	return 0;
}