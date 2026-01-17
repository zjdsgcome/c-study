#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	int data[1000];

	double d;
} Print_s;

void print_struct_by_val(Print_s s) { //打印结构体以传值的方式进行
	for (size_t i = 0; i < 3; i++)
	{
		printf("打印结构体以传值的方式进行 %d \n", s.data[i]);
	}
}

void print_struct_by_ptr(const Print_s* s) { // 打印结构体，以传地址的方式进行,这种更好一点，因为不需要开辟内存空间
	for (size_t i = 0; i < 3; i++)
	{
		printf("结构体打印以传地址的方式进行 is %d \n", s->data[i]);//箭头操作符

		printf("结构体打印以传地址的方式进行，但是以点操作符进行,%d \n", (*s).data[i]);//必须加括号，因为点操作符比*操作符优先级高
	}
}

//entry
static int str_param() {

	Print_s s = { {1,2,3},2.2 };

	print_struct_by_val(s);
	print_struct_by_ptr(&s);
	return EXIT_SUCCESS;
}