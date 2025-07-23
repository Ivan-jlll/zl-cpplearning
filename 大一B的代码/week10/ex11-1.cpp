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
	cout << "t1的时间为：";
	t1.show();
	cout << "t2的时间为：";
	t2.show();
	cout << "t1与基准时间的差值为：" << Time::timeBaseDiffence(t1) << endl;
	cout << "t2与基准时间的差值为：" << Time::timeBaseDiffence(t2) << endl;
	cout << "t1与t2时间的差值为：" << diffence(t1, t2);
	return 0;
}