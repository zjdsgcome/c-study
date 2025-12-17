#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static void no_static_val() {
	  int a = 100;
	  printf("a++ is %d \n", a++);//后置++，每次都是100，因为每次都被int a = 100初始化了
}

static void static_val() { // static函数只能这个文件内部使用
	static int a = 100;

	printf("b++ is %d \n", a++);//static静态局部变量只定义一次，也就是说第二次进来的时候就不执行初始化了，还拿上次的a
}

int main_val(void) {
	for (int i = 0; i < 100; i++) {
		no_static_val();
	}

	for (size_t i = 0; i < 10; i++)
	{
		static_val();
	}
}