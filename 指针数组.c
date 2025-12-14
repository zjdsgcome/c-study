#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void point_arr(void);

void many_level_point(void);

int point_arr_main(void) {
	printf("指针数组 \n");
	point_arr();

	printf("多级指针\n");

	many_level_point();
}

void point_arr(void) {
	printf("指针数组本质就是二级指针");
	int a = 10;

	int b = 20;

	int c = 30;

	int* p = &a;

	int* q = &b;

	int* r = &c;


	int* arr[] = { p,q,r };

	printf("arr[0] is %d \n", *(arr[0]));

	printf("arr[0] is %d \n", *(*(arr + 0)));//arr[0] = *(arr+0)

	printf("arr[0] is %d \n", *(*(arr)));//arr+0 = arr

	printf("arr[0] is %d \n", **arr);//*运算符同级别，去括号

}


void many_level_point(void) {
	printf("多级指针\n");

	int a = 100;

	int* p = &a;//一级指针
	

	int** p2 = &p;//二级指针 如果写成&&a是没有意义的


	int*** p3 = &p2;//三级指针,没有二级指针是无法获取三级指针的

	printf("一级指针值为 %d \n", *p);//一级指针取值

	printf("二级指针为 %d \n", **p2);//二级指针取值

	printf("三级指针为 %d \n", ***p3);//三级指针取值
}