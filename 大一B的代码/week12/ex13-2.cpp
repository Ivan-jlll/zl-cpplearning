#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int i=0,int j=0):x(i),y(j){}
	Point& operator++();//����ǰ������
	Point operator++(int);//���غ�������
	void show() {
		cout << "�õ�����Ϊ��( " << x << ", " << y << " )\n";
	}
	friend Point& operator--(Point& p);
	friend Point operator--(Point& p,int);
	//friend ostream& operator<<(ostream& cout, const Point& p);
};
Point& Point::operator++()//����ǰ������
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)//���غ�������
{
	Point temp(this->x, this->y);
	x++;
	y++;
	return temp;
}

Point& operator--(Point& p) {   //����ǰ���Լ�
	p.x--;
	p.y--;
	return p;
}

Point operator--(Point& p, int) {   //���غ����Լ�
	Point temp(p.x, p.y);
	p.x--;
	p.y--;
	return temp;
}


int main(){
	Point p1(1, 2), p2(2, 1), p3(5,5), p4(4, 3);
	p1++;
	++p2;
	p3--;
	--p4;
	p1.show();
	p2.show();
	p3.show();
	p4.show();
	Point p5(p1++), p6(p3--);
	p5.show();
	p6.show();
	return 0;
}
//�������úͷ��ض��������
//1.���������Ƿ��ص��ö������ǶԵ��÷����е��޸Ĳ�������������
//2.���ض���ʱ��Ȼ���ܶԵ��÷��������޸ģ��������շ��صĶ����Ǿ������´�����Ϊ�丳��Ӧ��ֵ������÷���������������
//������������غ���ֻ�ܷ��ض����ԭ��
//���÷��Ѿ����޸ģ���Ϊ�˱������÷�ԭʼ�����ں����ֲ��������´����µľֲ����������б��棬����C++�������ؾֲ����������ã�ԭ���Ǹñ����ں�������ʱ�ᱻ���٣�
//���Һ������������Ҳ��Ҫ�󷵻����ã�����һ����ʱ����������÷��ĳ�ֵ���ɡ�