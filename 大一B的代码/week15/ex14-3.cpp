#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("D:\\G5124307 ֣��\\data\\scores.txt");
	int arr[97], n = 0;
	if (!in) {
		cout << "Open infile error!" << endl;
		exit(1);
	}
	while (n < 97 && in >> arr[n]) {
		n++;
	}
	/*while (in>>arr[n]) {
		in >> arr[n++];
	}*/
	in.close();
	ofstream out("D:\\G5124307 ֣��\\data\\result.txt");
	int max=arr[0], min=arr[0], ni=0, ei=0, se=0, si=0, els=0,sum=0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		if (arr[i] >= 0 && arr[i] <= 59) els++;
		else if (arr[i] >= 60 && arr[i] <= 69) si++;
		else if (arr[i] >= 70 && arr[i] <= 79) se++;
		else if (arr[i] >= 80 && arr[i] <= 89) ei++;
		else if (arr[i] >= 90 && arr[i] <= 100) ni++;
		sum += arr[i];
	}
	double ave = double(sum / double(n));
	out.setf(ios::fixed, ios::floatfield);
	out.precision(4);
	out << "��������" << n << endl;
	out << "��߷֣�" << max << endl;
	out << "��ͷ֣�" << min << endl;
	out << "ƽ���֣�" << ave << endl <<endl;
	double per1 = ni / double(n);
	double per2 = ei / double(n);
	double per3 = se / double(n);
	double per4 = si / double(n);
	double per5 = els / double(n);
	out.setf(ios::fixed, ios::floatfield);
	out.precision(0);
	out << setw(12) << "90-100��" << ni << "�� " << "�ٷֱȣ�"<< per1*100 << "%" << endl;
	out << setw(12) << "80-89��" << ei << "�� " << "�ٷֱȣ�" << per2 * 100 << "%" << endl;
	out << setw(12) << "70-79��" << se << "�� " << "�ٷֱȣ�" << per3 * 100 << "%" << endl;
	out << setw(12) << "60-69��" << si << "�� " << "�ٷֱȣ�" << per4 * 100 << "%" << endl;
	out << setw(12) << "0-59��" << els << "�� " << "�ٷֱȣ�" << per5 * 100 << "%" << endl;
	return 0;
}