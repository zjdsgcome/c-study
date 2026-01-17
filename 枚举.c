#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum Color {
	RED,

	GREEN,

	BLUE
	
};

typedef enum  {
	ONE = 1,//指定枚举从1开始

	TWO,

	THREE
} Number_s;


//联合体

typedef union {
	int a;

	char name;
} Un;

//判断是大端还是小端存储
void big_or_int(void) {
	int i = 1;

	printf( *((unsigned char*)&i) == 1 ? "小端存储": "大端存储");

	//使用联合体判断大小端

	union BigSmall {

		int c;

		char d;
	};

	union BigSmall big_small;

	big_small.c = 1;

	printf(big_small.d == 1 ? "小端存储" : "大端存储");
}



int main_union() {

	enum Color red = RED;//枚举从0开始

	Number_s num = ONE;//指定枚举从1开始

	printf("red is %d", red);


	big_or_int();

	return EXIT_SUCCESS;
}