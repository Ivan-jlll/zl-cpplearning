#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ofstream out("D:\\G5124307 жёаж\\data\\table.txt");
	out.setf(ios::right);
	out << setw(12) << "Number" << setw(12) << "Square" << setw(16) << "Square root"<<endl;
	out << "--------------------------------------------------\n";
	for (int i = 1; i <= 100; i++) {
		double root = sqrt(i);
		out.setf(ios::fixed, ios::floatfield);
		out.precision(3);
		out.setf(ios::right);
		out << setw(12) << i << setw(16) << i * i << setw(16) << root << endl;
	}
	return 0;
}