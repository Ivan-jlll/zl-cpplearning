#include <iostream>
using namespace std;

void getDigits(char *s1, char*s2);

int main() {
	char s1[100];
	cin.getline(s1, 100);
	char s2[100];
	getDigits(s1, s2);
	cout <<"Êý×Ö×Ö·û´®Îª£º" << s2 << endl;
	return 0;
}

void getDigits(char *s1, char*s2) {
	int i = 0, j = 0;
	while (*(s1 + i) != '\0') {
		if (*(s1 + i) <= '9' && *(s1 + i) >= '0')
			*(s2 + j) = *(s1 + i),  j++;
		i++;
	}
	s2[j] = '\0';
}