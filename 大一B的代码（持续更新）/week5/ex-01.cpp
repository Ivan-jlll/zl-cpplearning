//例9.31-9.33 
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	void sort(const char*[], int);
	void print(const char*[], int);//函数原型声明
	const char *name[] = { "George","Mary","Susan","Tom","Davis" };
	int n = 5;
	sort(name, n);
	print(name, n);
	return 0;
}
void sort(const char *name[], int n) {
	const char *ptr; int i, j, k;
	const char **pname = name;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(*(pname + k), *(pname + j)) > 0) k = j;
		}
		if (k != i) {
			ptr = *(pname + i); *(pname + i) = *(pname + k); *(pname + k) = ptr;
		}
	}
}
void print(const char *name[], int n) {
	const char **pname = name;
	for (int i = 0; i < n; i++) {
		cout << *(pname + i) << endl;
	}
}