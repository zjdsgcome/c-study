#include<stdio.h>


//最大值
int maxP(int a, int b) {
	return a > b ? a : b;
}


int modify(int *a) {
	*a = 100;
	return *a;
}

int maxPoint(int a, int b, int (*p)(int, int)) {
	if (p != NULL) {
		return p(a, b);
	}
	return 0;
}

int main(void) {
		//Company main function
	printf("函数指针\n");
	printf("max is %d \n", maxPoint(10, 20, maxP));//传入函数指针

	struct Person
	{
		int age;

		char name[20];

		int sex;
	} p;

	int a = 10;

	int result = modify(&a);

	printf("a=%d\n", a);

	printf("result=%d\n", result);

	p.age = 18;
	

	return 0;
}