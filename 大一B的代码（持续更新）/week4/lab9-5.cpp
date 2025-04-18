#include <iostream>
using namespace std;

void moveLeft(int *a, int n);
void rotateLeft(int *a, int n, int k);

int main() {
	//完成数组初始化；
	int n,k;
	cout << "请输入数组长度和左移位数：";
	cin >> n >> k;
	int *arr1 = new int[n];
	cout << "移位前的数组为：\n";
	for (int i = 0; i < n; i++) {
		*(arr1 + i) = i + 1;
		cout << arr1[i] << ' ';
	}
	cout << endl;
	//调用数组左移函数，使数组左移k次；
	cout << "移位后的数组为：\n";
	rotateLeft(arr1, n, k);
	for (int i = 0; i < n; i++) {
		cout << arr1[i] <<' ';
	}
	cout << endl;
	return 0;
}

//数组左移1位；
void moveLeft(int *a, int n) {
	int temp;
	temp = *a;
	for (int i = 0; i < n-1; i++) {
		
		*(a + i) = *(a + i + 1);
	}
	*(a + n - 1) = temp;
}

//数组左移k位；
void rotateLeft(int *a, int n, int k) {
	for (int i = 1; i <= k; i++) {
		moveLeft(a, n);
	}
}