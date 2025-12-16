#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void func_str_char();

void func_str_r_char();

void func_str_str();

void func_str_tok();


void func_str_a_to();

int main(void) {

	func_str_char();

	func_str_r_char();

	func_str_str();


	func_str_tok();

	func_str_a_to();
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

void func_str_tok() {
	//将字符串替换为\0并返回前面的

	char str[] = "www.baidu.com";

	int len = strlen(str);

	char* p = strtok(str, ".");

	printf("strtok result is %s \n", p);

	for (int i = 0; i < len; i++) {
		printf("str is %c \n", str[i]);
	} 

	//strtok会记住上次调用的位置，因此下次再切分就传NULL就好了
	char str_for_tok[] = "www.baidu.com";

	for (char* l = strtok(str_for_tok, "."); l != NULL; l = strtok(NULL, ".")) {
		printf("str for is %s \n",l);
	}
}


void func_str_a_to() {
	//字符串转数字

	char* str1 = "123";

	int a = atoi(str1);//字符串转int

	printf("atoi result is %d", a);

	char* str2 = "0.123f";

	double b = atof(str2);

	printf("atof result is %lf", b);

	char* str3 = "123L";

	long c = atol(str3);

	printf("atol result is %ld", c);
}