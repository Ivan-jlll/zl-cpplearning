#include <iostream>
using namespace std;

class Student {
private:
	char Name[20];
	char *Num;
	int Maths, English, Physics, Cpp;
public:
	void setNameNo(char *name, char *no);
	void setScores(int m, int e, int p, int c);
	int total();
	int average();
	void outputInfo();
};

void Student::setNameNo(char *name, char *no) {
	int i = 0;
	for (; *(name + i) != '\0'; i++) {
		*(Name + i) = *(name + i);
	}
	*(Name + i) = '\0';
	if (Num == nullptr) {
		delete Num;
	}
	Num = new char[10];
	Num = no;
}
void Student::setScores(int m, int e, int p, int c) {
	Maths = m; English = e; Physics = p; Cpp = c;
}
int Student::total() {
	return Maths + English + Physics + Cpp;
}
int Student::average() {
	return (total()) / 4;
}
void Student::outputInfo() {
	cout << "Student Name:\t" << Name << endl;
	cout << "Student Number:\t" << Num << endl;
	cout << "Maths score:\t" << Maths << endl;
	cout << "English score:\t" << English << endl;
	cout << "Physics score:\t" << Physics << endl;
	cout << "Cpp score:\t" << Cpp << endl;
	cout << "average score:\t" << average() << endl;
}

int main() {
	char Name1[20];
	cin.getline(Name1,20);
	char No1[20];
	cin.getline(No1, 20);
	Student std1;
	std1.setNameNo(Name1, No1);
	std1.setScores(100, 100, 100, 100);
	std1.outputInfo();
	return 0;
}