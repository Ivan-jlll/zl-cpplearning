//ex13-3 建立字符串类String
#include <iostream>
using namespace std;
void strcpy_m(char* str1, char* str2);
int strlen_m(char* str1);
class String {
private:
	char* str;  //字符串的首地址。存放字符串的空间需要动态申请。
	int len;  //字符串的长度。
public:
	String(char* = nullptr);  //构造函数，动态申请存储空间用于存放字符串的值。
	String(const String&);  //拷贝构造函数。
	~String();  //析构函数，释放字符串动态空间。
	void set(char* s);  //设置字符串的值。
	void show();  //显示字符串。
	int getLen();  //返回字符串长度值。
	void delChar(char);  //删除字符串中由参数指定的字符，若出现多处，均需要删除。
	String& operator=(const String&);  //重载“=”运算符，实现字符串赋值。
	String& operator+=(const String&);  //重载“+=”运算符，实现两字符串的连接赋值。
	bool operator==(const String&);  //重载“==”运算符，比较两字符串，相等返回true,否则返回false。
	friend String operator+(const String&, const String&);  //重载“+”运算符，实现两字符串的连接。
};
String::String(char* str) {
	this->str = new char[100];
	if (str != nullptr) {
		strcpy_m(this->str, str);
		this->len = strlen_m(str);
	}
	else {
		this->str[0] = '\0';
		this->len = 0;
	}
}
String::String(const String &Str) {
	this->str = new char[100];
	if (Str.str != nullptr) {
		strcpy_m(this->str, Str.str);
		this->len = Str.len;
	}
	else {
		this->str[0] = '\0';
		this->len = 0;
	}
}
String::~String() {
	if (str != nullptr) {
		delete[] str; str = nullptr;
	}
	cout << "The object is destructing!\n";
}
void String::set(char* s) {
	strcpy_m(this->str, s);
	len = strlen_m(s);
}
void  String::show() {
	if (str == nullptr) {
		cout << "None!\n"; 
		return;
	}
	cout << "The String: " << str << '\t' << "The Lenth: " << len << endl;
}
int String::getLen() {
	return len;
}
void  String::delChar(char s) {
	if (str == nullptr) {
		cout << "None!\n";
		return;
	}
	int i = 0, j = 0;
	while (*(str + i) != '\0') {
		if (*(str + i) != s)  str[j++] = str[i];
		i++;
	}
	*(str + j) = '\0';
	len = j;
}
String& String::operator=(const String &Str) {
	if (this == &Str) return *this;
	delete[] this->str;
	this->str = new char[100];
	strcpy_m(this->str, Str.str); 
	this->len = Str.len;
	return *this;
}
String& String::operator+=(const String &Str) {
	int i = 0;
	if (Str.str == nullptr) return *this;
	while (*(Str.str+i) != '\0') {
		*(this->str + this->len + i) = *(Str.str + i);
		i++;
	}
	*(this->str + this->len + i) = '\0';
	this->len += Str.len;
	return *this;
}
bool String::operator==(const String &Str) {
	int i = 0;
	if (Str.str == nullptr && this->str == nullptr) return true;
	else if (Str.str == nullptr && this->str != nullptr) return false;
	else
		while (*(Str.str + i) != '\0') {
			if (*(Str.str + i) != *(this->str + i)) return false;
			i++;
		}
	return true;
}

void strcpy_m(char* str1, char* str2) {
	int i = 0;
	if (!str1) return;
	if (!str2) {
		str1[0] = '\0';
		return;
	}
	else
		while (*(str2 + i) != '\0'&&i<=99) {
			*(str1 + i) = *(str2 + i);
			i++;
		}
	*(str1 + i) = '\0';
}

int strlen_m(char* str1) {
	int i = 0;
	if (str1 == nullptr) return 0;
	else
		while (*(str1 + i) != '\0') {
			i++;
		}
	return i;
}

String operator+(const String &Str1, const String &Str2) {
	String Str;
	int i = 0, j = 0;
	strcpy_m(Str.str, Str1.str);
	i = strlen_m(Str.str);
	while (*(Str2.str+j) != '\0') {
		*(Str.str + i + j) = *(Str2.str + j);
		j++;
	}
	*(Str.str + i + j) = '\0';
	Str.len = Str1.len + Str2.len;
	return Str;
}

int main() {
	//测试函数
	char s1[8] = { 'a','b','c','d','e','f','g','\0' };
	char s2[9] = { 'a','c','b','d','f','b','k','p','\0'};
	String str1, str2(s1);
	String str3(str2);
	str1.show(); str2.show(); str3.show();
	str1.set(s2); str1.show();
	cout << str1.getLen() << '\t' << str2.getLen() << '\t' << str3.getLen() << endl;
	str1.delChar('b'); str1.show();
	str1 = str2; str1.show(); str2.show();
	String str4(s2);
	str4 += str1; str1.show(); str4.show();
	if (str1 == str2) cout << "true\n";
	else  cout << "false\n";
	if (str4 == str2) cout << "true\n";
	else  cout << "false\n";
	String str5 = str4 + str1;
	str5.show();
	return 0;
}