#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;
	static int baseHour, baseMinute, baseSecond;
	static int timeToSecond(Time t) {
		int SumSec = 0;
		SumSec += t.hour * 3600 + t.minute * 60 + t.second;
		return SumSec;
	}
public:
	Time(int = 0, int = 0, int = 0);
	static int timeBaseDiffence(Time t) {
		int Sumt = timeToSecond(t);
		int Sumbase = baseHour * 3600 + baseMinute * 60 + baseSecond;
		int diff = Sumt - Sumbase;
		return diff;
	}
	void show();
	friend int diffence(Time t1, Time t2);
};
int Time::baseHour = 1; 
int Time::baseMinute = 10;
int Time::baseSecond = 10;
Time::Time(int i, int j, int k) {
	hour = i;
	minute = j;
	second = k;
}
void Time::show() {
	cout << hour << ':' << minute << ':' << second << endl;
}
int diffence(Time t1, Time t2) {
	int Tst1 = Time::timeToSecond(t1);
	int Tst2 = Time::timeToSecond(t2);
	int diff = Tst1 - Tst2;
	return diff;
}

int main() {
	Time t1(1, 11, 2);
	Time t2(1, 12, 50);
	cout << "t1��ʱ��Ϊ��";
	t1.show();
	cout << "t2��ʱ��Ϊ��";
	t2.show();
	cout << "t1���׼ʱ��Ĳ�ֵΪ��" << Time::timeBaseDiffence(t1) << endl;
	cout << "t2���׼ʱ��Ĳ�ֵΪ��" << Time::timeBaseDiffence(t2) << endl;
	cout << "t1��t2ʱ��Ĳ�ֵΪ��" << diffence(t1, t2);
	return 0;
}