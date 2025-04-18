#include <iostream>
using namespace std;

void moveLeft(int *a, int n);
void rotateLeft(int *a, int n, int k);

int main() {
	//��������ʼ����
	int n,k;
	cout << "���������鳤�Ⱥ�����λ����";
	cin >> n >> k;
	int *arr1 = new int[n];
	cout << "��λǰ������Ϊ��\n";
	for (int i = 0; i < n; i++) {
		*(arr1 + i) = i + 1;
		cout << arr1[i] << ' ';
	}
	cout << endl;
	//�����������ƺ�����ʹ��������k�Σ�
	cout << "��λ�������Ϊ��\n";
	rotateLeft(arr1, n, k);
	for (int i = 0; i < n; i++) {
		cout << arr1[i] <<' ';
	}
	cout << endl;
	return 0;
}

//��������1λ��
void moveLeft(int *a, int n) {
	int temp;
	temp = *a;
	for (int i = 0; i < n-1; i++) {
		
		*(a + i) = *(a + i + 1);
	}
	*(a + n - 1) = temp;
}

//��������kλ��
void rotateLeft(int *a, int n, int k) {
	for (int i = 1; i <= k; i++) {
		moveLeft(a, n);
	}
}