#include <iostream>
#include <cstring>
using namespace std;

bool isLetter(char);
char toUpper(char);
void firstUpper(char *s);

int main() {
	char s[100];
	cin.getline(s, 100);
	firstUpper(s);
	cout << "处理后的字符串为：\n";
	cout << s;
	return 0;
}

bool isLetter(char s){
	if ((s <= 'z'&&s >= 'a') || (s <= 'Z'&&s >= 'A'))
		return true;
	return false;
}

char toUpper(char s) {
	if (s <= 'z'&&s >= 'a')
		return (s - ('a' - 'A'));
	if (s <= 'Z'&&s >= 'A')
		return s;
}

void firstUpper(char *s) {
	int i = 0;
	while (*(s + i) != '\0')
	{
		if (isLetter(*(s + i))) {
			*(s + i) = toUpper(*(s + i));
			for (; isLetter(*(s + i)); i++);
		}
		i++;
	}
}