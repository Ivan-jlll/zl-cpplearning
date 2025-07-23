#include <iostream>
using namespace std;

struct Statistics {
	int maxVal;
	int minVal;
	double avg;
};

int MaxValue(int a[4][4]);
int MinValue(int a[][4]);
double average(int(*a)[4]);
void describe(int a[4][4], int *maxVal, int *minVal, double *avg);
void describe(int a[4][4], int &maxVal, int &minVal, double &avg);
Statistics describe(int a[4][4]);

int main() {
	int a[][4] = { 4,5,6,8, 4,6,54,996, 6,4,5,4, 9,8,5,6 };
	int b[][4] = { 4,5,6,8, 4,6,54,996, 6,4,5,4, 9,8,5,6 };
	int c[][4] = { 4,5,6,8, 4,6,54,996, 6,4,5,4, 9,8,5,6 };
	Statistics s = describe(c);
	int maxa, maxb, mina, minb;
	double avea, aveb;
	//int *maxa = &maxa, *mina = &mina, *avea = &avea;
	describe(a, &maxa, &mina, &avea);
	describe(b, maxb, minb, aveb);
	cout << maxa << ' ' << mina << ' ' << avea <<endl;
	cout << maxb << ' ' << minb << ' ' << aveb <<endl;
	cout << s.maxVal << ' ' << s.minVal << ' ' << s.avg;
	return 0;
}
int MaxValue(int a[4][4]) {
	int max=0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (max < *(*(a + i) + j)) max = *(*(a + i) + j);
		}
	}
	return max;
}

int MinValue(int a[][4]) {
	int min= *(a[0] + 0);
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (min > *(a[i] + j)) min = *(a[i] + j);
		}
	}
	return min;
}

double average(int(*a)[4]) {
	double ave = 0, sum = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			sum += a[i][j];
		}
	}
	ave = sum / 16;
	return ave;
}

void describe(int a[4][4], int *maxVal, int *minVal, double *avg) {
	*maxVal = MaxValue(a);
	*minVal = MinValue(a);
	*avg = average(a);
}

void describe(int a[4][4], int &maxVal, int &minVal, double &avg) {
	maxVal = MaxValue(a);
	minVal = MinValue(a);
	avg = average(a);
}

Statistics describe(int a[4][4]) {
	Statistics s;
	s.maxVal = MaxValue(a);
	s.minVal = MinValue(a);
	s.avg = average(a);
	return s;
}