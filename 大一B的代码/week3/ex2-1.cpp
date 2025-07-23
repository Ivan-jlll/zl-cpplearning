#include <iostream>
using namespace std;

void sort1(int** ppa, int** ppb, int** ppc);
void sort2(int*& pa, int*& pb, int*& pc);

int main()
{
	int a = 3, b = 2, c = 1;

	int *pa = &a, *pb = &b, *pc = &c;
	sort1(&pa, &pb, &pc);
	cout << *pa << ' ' << *pb << ' ' << *pc << endl;  //输出1 2 3
	cout << a << ' ' << b << ' ' << c << endl; //输出3 2 1

	pa = &a, pb = &b, pc = &c;
	sort2(pa, pb, pc);
	cout << *pa << ' ' << *pb << ' ' << *pc << endl;  //输出1 2 3
	cout << a << ' ' << b << ' ' << c << endl; //输出3 2 1

	return 0;
}

void sort1(int** ppa, int** ppb, int** ppc) {
	
	int* pt1 = nullptr ,*pt2=nullptr, *pt3=nullptr ;
	if (**ppa > **ppb) pt1 = *ppa, *ppa = *ppb, *ppb = pt1;
	if (**ppa > **ppc) pt2 = *ppa, *ppa = *ppc, *ppc = pt2;
	if (**ppb > **ppc) pt3 = *ppb, *ppb = *ppc, *ppc = pt3;
}

void sort2(int*& pa, int*& pb, int*& pc) {
	int* pt1 = nullptr, *pt2 = nullptr, *pt3 = nullptr;
	if (*pa > *pb) pt1 = pa, pa = pb, pb = pt1;
	if (*pa > *pc) pt2 = pa, pa = pc, pc = pt2;
	if (*pb > *pc) pt3 = pb, pb = pc, pc = pt3;
}