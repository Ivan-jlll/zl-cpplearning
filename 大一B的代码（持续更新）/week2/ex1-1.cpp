#include<iostream>
using namespace std;

void exchange(int *, int *);
void exchange(int &, int &);

int main()
{
	int a = 15, b = 12, c = 9;
	if (a > b) exchange(a, b);
	if (a > c) exchange(a, c);
	if (b > c) exchange(b, c);
	int e = 16, f = 13, g = 116;
	int *pe = &e, *pf = &f, *pg = &g;
	if (e > f) exchange(*pe, *pf);
	if (e > g) exchange(*pe, *pg);
	if (f > g) exchange(*pf, *pg);
	cout << a << '\t' << b << '\t' << c << endl;
	cout << e << '\t' << f << '\t' << g << endl;
	return 0;
}

void exchange(int *p1, int *p2)
{
	int t;
	if (*p1 > *p2) {
		t = *p1; *p1 = *p2; *p2 = t;
	}
}

void exchange(int &a, int &b)
{
	int t;
	if (a > b) {
		t = a; a = b; b = t;
	}
}