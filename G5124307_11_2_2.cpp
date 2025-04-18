#include "G5124307_11_2_2.h"
int gcd(int a,int b)
{
	int r;
	r=a%b;
	if(r==0) return b;
	else return gcd(b,r);
}