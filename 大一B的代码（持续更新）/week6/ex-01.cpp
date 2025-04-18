#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};

// ����ȽϺ���������
// typedef bool (comp)(Point *, Point *);
using comp = bool(Point *, Point *);

Point Input(void);
void Output(Point p);
void PrintPts(Point *pPts[], int N); //����Output���������

double Dist(Point &p1, Point &p2);
void _swap(Point *&p1, Point *&p2); //��������Pointָ�����

//������������f�Ե���������
void SortPts(Point *pPts[], int N, comp *f);

// ��������
bool CompareByDistance(Point *a, Point *b); // ���ݵ㵽ԭ��ľ���Ƚ�, a����ԭ�����ʱ����true
bool CompareLexicographically(Point *a, Point *b); //���ֵ���Ƚϵ�, a���ֵ�����b֮ǰʱ����true
bool CompareBySlope(Point *a, Point *b); // ���ݵ������ԭ���б�ʱȽ�, aб�ʽ�Сʱ����true. (ѡ��)

int main()
{
	Point pt1, pt2, pt3;
	double dist;

	// ����������
	cout << "Input Point 1." << endl;
	pt1 = Input();
	cout << "Input Point 2." << endl;
	pt2 = Input();

	// ����p1, p2 ֮��ľ��벢���
	dist = Dist(pt1, pt2);
	cout << "Point 1 is at ";
	Output(pt1);
	cout << "Point 2 is at ";
	Output(pt2);
	cout << "Distance between Pt 1 and Pt 2 is " << dist << endl;

	// ��Pointָ�������������
	const int N = 6;
	Point Pts[N]{ {2, 4}, {3, 3}, {1, 2}, {5, 1}, {1, 1}, {3, 4} };
	Point *pPts[N];
	for (int i = 0; i < N; ++i)
		pPts[i] = &Pts[i];

	cout << "����������: " << endl;
	SortPts(pPts, N, CompareByDistance);
	PrintPts(pPts, N);
	cout << "���ֵ���: " << endl;
	SortPts(pPts, N, CompareLexicographically);
	PrintPts(pPts, N);

	//��б������(ѡ��)
	cout << "��б������:" << endl;
	SortPts(pPts, N, CompareBySlope); 
	PrintPts(pPts, N);

	return 0;
}
Point Input(void) {
	Point p;
	cin >> p.x >> p.y;
	return p;
}
void Output(Point p) {
	cout << "( " << p.x << " ," << p.y << " )" << endl;
}
double Dist(Point &p1, Point &p2) {
	double dist;
	dist = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
	return dist;
}
void PrintPts(Point *pPts[], int N) {
	for (int i = 0; i < N; i++) {
		//cout << "POINT(" << pPts[i]->x << " ," << pPts[i]->y << ")\n"; //(*pPts + i)->x ��ģ�����
		cout << "POINT(" << (*(pPts + i))->x << " ," << (*(pPts + i))->y << ")\n"; //pPtsΪָ��������!
	}
}
void _swap(Point *&p1, Point *&p2) {
	Point *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
void SortPts(Point *pPts[], int N, comp *f) {
	int i, j;
	bool flag = true;
	for (i = 0; flag && i < N - 1; i++) {
		flag = false;
		for (j = 0; j < N - 1 - i; j++) {
			if (!f(pPts[j], pPts[j+1])) {
				_swap(pPts[j], pPts[j+1]);
				flag = true;
			}
		}
	}
}
// ��������
bool CompareByDistance(Point *a, Point *b) // ���ݵ㵽ԭ��ľ���Ƚ�, a����ԭ�����ʱ����true
{
	double dist_a = (a->x)*(a->x) + (a->y)*(a->y);
	double dist_b = (b->x)*(b->x) + (b->y)*(b->y);
	if (dist_a < dist_b) return true;
	return false;
}
bool CompareLexicographically(Point *a, Point *b) //���ֵ���Ƚϵ�, a���ֵ�����b֮ǰʱ����true
{
	if (a->x < b->x) return true;
	if (a->x == b->x&&a->y < b->y) return true;
	return false;
}
bool CompareBySlope(Point *a, Point *b) // ���ݵ������ԭ���б�ʱȽ�, aб�ʽ�Сʱ����true. (ѡ��)
{
	double k_a, k_b;
	k_a = (a->y) / (a->x);
	k_b = (b->y) / (b->x);
	if (k_a < k_b) return true;
	return false;
}
