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
	cout << "�����붯̬����ĳ��ȣ�";
	cin >> n;
	int *arr1 = new int[n];
	for (int i = 0; i < n; i++)
		*(arr1 + i) = i + 1;
	cout << "������kֵ�����������ǰk���ͺ�k��Ԫ�صĺͣ�";
	cin >> k;
	int shead, stail;
	shead = fsum(arr1, k);
	stail = fsum(arr1 + n - k, k);
	cout << shead << " ," << stail << endl;
	return 0;
}