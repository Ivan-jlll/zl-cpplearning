#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in1("D:\\G5124307 жёаж\\data\\w1.txt");
	int a[10], n = 0;
	if (!in1) {
		cout << "Open file error!";
		exit(1);
	}
	while (n<4 && in1 >> a[n]) {
		n++;
	}
	in1.close();
	ifstream in2("D:\\G5124307 жёаж\\data\\w2.txt");
	int b[10], m = 0;
	if (!in2) {
		cout << "Open file error!";
		exit(1);
	}
	while (m<6 && in2 >> b[m]) {
		m++;
	}
	in2.close();
	int c[10],h=0, i=0, j=0;
	while (h < 10 && i<4 && j<6) {
		if (a[i] > b[j]) c[h++] = b[j++];
		else if (a[i] < b[j]) c[h++] = a[i++];
		else if (a[i] == b[j]) c[h++] = b[j++], c[h++] = a[i++];
	}
	while (h < 10 && i < n) {
		c[h++] = a[i++];
	}
	while (h < 10 && j < m) {
		c[h++] = b[j++];
	}
	ofstream out("D:\\G5124307 жёаж\\data\\w3.txt");
	for (int y = 0; y < 10; y++) {
		out << c[y] << "  ";	
	}
	out << endl;
	return 0;
}