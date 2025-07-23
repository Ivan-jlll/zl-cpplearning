#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool palin(char *);

int main() {
	char str[100];
	cin.getline(str, 100);
	if (palin(str)) cout << "是回文！\n";
	if (!palin(str)) cout << "不是回文！\n";
	return 0;
}

bool palin(char *str) {
	char* head, *tail,*pstr;
	int n = strlen(str);
	char copystr[100];
	for (int i = 0; i < n; i++) {
		*(copystr + i) = *(str + i);
	}
	head = pstr = copystr;
	tail = copystr + n - 1;
	for (int i = 0; i < n; i++) {
		if (*(pstr + i) <= 'Z'&&*(pstr + i) >= 'A') {
			*(pstr + i) += ( 'a' - 'A');
		}
	}
	while (head < tail) {
		while (!isalpha(*head)) {
			head++;
		}
		while (!isalpha(*tail)) {
			tail--;
		}
		if (*head != *tail) {
			return false;
		}
		if (*head == *tail) {
			head++;
			tail--;
		}
	}
	return true;
}