//ex13-3 �����ַ�����String
#include <iostream>
using namespace std;
void strcpy_m(char* str1, char* str2);
int strlen_m(char* str1);
class String {
private:
	char* str;  //�ַ������׵�ַ������ַ����Ŀռ���Ҫ��̬���롣
	int len;  //�ַ����ĳ��ȡ�
public:
	String(char* = nullptr);  //���캯������̬����洢�ռ����ڴ���ַ�����ֵ��
	String(const String&);  //�������캯����
	~String();  //�����������ͷ��ַ�����̬�ռ䡣
	void set(char* s);  //�����ַ�����ֵ��
	void show();  //��ʾ�ַ�����
	int getLen();  //�����ַ�������ֵ��
	void delChar(char);  //ɾ���ַ������ɲ���ָ�����ַ��������ֶദ������Ҫɾ����
	String& operator=(const String&);  //���ء�=���������ʵ���ַ�����ֵ��
	String& operator+=(const String&);  //���ء�+=���������ʵ�����ַ��������Ӹ�ֵ��
	bool operator==(const String&);  //���ء�==����������Ƚ����ַ�������ȷ���true,���򷵻�false��
	friend String operator+(const String&, const String&);  //���ء�+���������ʵ�����ַ��������ӡ�
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
	//���Ժ���
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