#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
	char Name[20];
	char *Num;
	int Maths, English, Physics, Cpp;
public:
	void setNameNo(const char *name, const char *no);
	void setScores(int m, int e, int p, int c);
	int total();
	int average();
	void outputInfo();
	Student(char *name = nullptr, char *num = nullptr, int m = 0, int e = 0, int p = 0, int c = 0); 
	Student(Student &);
	~Student() {
		if (Num != nullptr) delete[] Num;
		cout << "destucting student: " << Name << endl;
	}
};

Student::Student(char *name, char *num , int m , int e , int p , int c ) {
	if (name != nullptr) {
		int j = 0;
		while (*(name + j) != '\0') {
			*(Name + j) = *(name + j);
			j++;
		}
		*(Name + j) = '\0';
	}
	Num = new char[10];
	if (num != nullptr) {
		int j = 0;
		while (*(num + j) != '\0') {
			*(Num + j) = *(num + j);
			j++;
		}
		*(Num + j) = '\0';
	}
	if (name == nullptr) *(Name + 1) = '\0';
	if (num == nullptr) Num = nullptr;
	Maths = m;
	English = e;
	Physics = p;
	Cpp = c;
}

Student::Student(Student &std) {
	if (std.Name == nullptr) *(Name + 1) = '\0';
	if (std.Num == nullptr) Num = nullptr;
	if (std.Name != nullptr) {
			int j = 0;
			while (*(std.Name + j) != '\0') {
				*(Name + j) = *(std.Name + j);
				j++;
			}
			*(Name + j) = '\0';
		}
	if (std.Num != nullptr) {
		Num = new char[10];
		//*Num = *std.Num;
		int j = 0;
		while (*(std.Num + j) != '\0') {
			*(Num + j) = *(std.Num + j);
			j++;
		}
		*(Num + j) = '\0';
	}
	Maths = std.Maths; English = std.English; Physics = std.Physics; Cpp = std.Cpp;
}

void Student::setNameNo(const char *name, const char *no) {
	int i = 0;
	for (; *(name + i) != '\0'; i++) {
		*(Name + i) = *(name + i);
	}
	*(Name + i) = '\0';
	if (Num == nullptr) {
		delete[] Num;
	}
	Num = new char[10];
	int j = 0;
	while (*(no + j) != '\0') {
		*(Num + j) = *(no + j);
		j++;
	}
	*(Num + j) = '\0';
	
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
	Student std1;
	std1.setNameNo("zhangsan", "G5124418");
	std1.setScores(100, 100, 100, 100);
	std1.outputInfo();
	Student std2(std1);
	std2.outputInfo();
	return 0;
}