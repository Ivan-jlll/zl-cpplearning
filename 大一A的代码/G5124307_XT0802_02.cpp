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
	char input[11];// 期望的输入格式：YYYY-MM-DD
	int dnump[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int dnumr[12]={31,29,31,30,31,30,31,31,30,31,30,31};// 普通年份和闰年的每月天数数组
	cout << "请输入日期（格式：YYYY-MM-DD）：\n";
	
	cin.getline(input,11);
	if (strlen(input) != 10 || input[4] != '-' || input[7] != '-') {
        cout << "日期格式错误，请使用YYYY-MM-DD格式。\n";
        return 1;  // 格式不正确时退出程序
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
	cout<<dat.year<<"年"<<dat.mon<<"月"<<dat.day<<"日"<<"是第"<<sum<<"天\n";
	return 0;
}