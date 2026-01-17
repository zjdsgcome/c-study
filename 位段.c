#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct  {//位段
	char _a : 3; // 只占两个bit(比特)位
	char _b : 4;
	char _c : 5;

	char _d : 4;
} A;

int mainD() {

	A a = {0};
	a._a = 10;

	a._b = 12;
	
	a._c = 3;

	a._d = 4;
	return EXIT_SUCCESS;
}