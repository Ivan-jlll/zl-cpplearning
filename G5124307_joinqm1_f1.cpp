#include <cstdlib>
#include <iostream>					//1
using namespace std;
#define N 20						//2
void rndarr(int*);					//3
void fabsminus(int*, int&, int&);
int main() {
  int Arr[N], i, first = 0;
  cout << "ԭʼ����Ϊ: \n";			
  rndarr(Arr);						//4		
  fabsminus(Arr, i, first);			//5
  if (i == -1) {					
    cout << "���������޸���\n";		//6
  } else {
    cout << "��" << i+1 << "��Ԫ��Ϊ�����еĵ�һ������: " << first << endl;//7
  }
  cout << "����������Ϊ��\n";
  for (int i = 0; i < N; i++) {
    cout << Arr[i] << '\t';			//8
    if ((i + 1) % 4 == 0) {
      cout << endl;
    }
  }
  return 0;
}
void rndarr(int arr[]) {
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 25 - 12;		//9
    cout << arr[i] << '\t';			//10
    if ((i + 1) % 4 == 0) {
      cout << endl;
    }
  }
}
void fabsminus(int* p, int& k, int& val) {
  k = -1;
  for (int i = 0; i < N; i++) {
    if (p[i] < 0) {
      k   = i;
      val = p[i];			//11
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (p[i] < 0) {				//12
      p[i] = -p[i];
    }
  }
}
