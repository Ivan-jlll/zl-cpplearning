#include <iostream>
using namespace std;
#include <cstring>
struct date
{
	int year;
	int mon;
	int day;
};
int main()
{
	date dat;
	int sum=0,i,j,p=0;
	char input[11];// �����������ʽ��YYYY-MM-DD
	int dnump[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int dnumr[12]={31,29,31,30,31,30,31,31,30,31,30,31};// ��ͨ��ݺ������ÿ����������
	cout << "���������ڣ���ʽ��YYYY-MM-DD����\n";
	
	cin.getline(input,11);
	if (strlen(input) != 10 || input[4] != '-' || input[7] != '-') {
        cout << "���ڸ�ʽ������ʹ��YYYY-MM-DD��ʽ��\n";
        return 1;  // ��ʽ����ȷʱ�˳�����
    }
	
	dat.year=(input[0]-'0')*1000+(input[1]-'0')*100+(input[2]-'0')*10+(input[3]-'0');
	dat.mon=(input[5]-'0')*10+(input[6]-'0');
	dat.day=(input[8]-'0')*10+(input[9]-'0');
	if(dat.year%4!=0||(dat.year%100==0&&dat.year%400!=0)) 
	{
		for(i=0;i<dat.mon-1;i++)
			sum+=dnump[i];
		sum+=dat.day;
	}
	else
	{
		for(j=0;j<dat.mon-1;j++)
			sum+=dnumr[j];
		sum+=dat.day;
	}
	cout<<dat.year<<"��"<<dat.mon<<"��"<<dat.day<<"��"<<"�ǵ�"<<sum<<"��\n";
	return 0;
}