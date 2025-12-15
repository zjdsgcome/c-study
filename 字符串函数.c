#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void func_str_char();

void func_str_r_char();

void func_str_str();

int main(void) {

	func_str_char();

	func_str_r_char();

	func_str_str();
}

void func_str_char() {
	char str[] = "hello world";

	char* result =  strchr(str, 'w');

	printf("strchar is %s \n", result);//返回world
}

void func_str_r_char() {
	//自右向左找字符的位置

	char str[] = "hello world";

	char* result = strrchr(str, 'o');

	printf("strrchr is %s \n", result);//返回orld
}


void func_str_str() {
	//寻找子串出现的位置

	char str[] = "hello world";

	char* result = strstr(str, "world");

	printf("strstr is %s", result);//返回world
}