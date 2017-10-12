// Copyright [2013-2017] <xxxxx.Inc>
//
// Author: Nathan

#include <iostream>

#define Mul(x,y) ++x*++y

int main()
{
int a = 1;
int b = 2;
int c = 3;
++b;
printf("%d",++a+b*b+c);
return 0;
}
