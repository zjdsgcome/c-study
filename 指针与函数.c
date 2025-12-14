#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int m = 100;

int swap(int*, int*);

int fun_param_is_arr(int arr[],size_t);//数组做函数参数

int* fun_point_back(int,int);//指针做函数返回值

int main_ponit_fun(void) {

	int m = 3, n = 2;

	printf("交换前 %d,%d \n", m, n);

	swap(&m, &n);

	printf("交换后 %d,%d \n", m, n);

	int arr[] = { 1,2,3 };

	fun_param_is_arr(arr,sizeof(arr));

	printf("指针做函数返回值 \n");

	int* fun_point_back_res =  fun_point_back(3,2);

	printf("指针做函数返回值调用结果返回 %d",*fun_point_back_res);

	return 0;
	

}

int fun_param_is_arr(int arr[],size_t arr_size) {

	//等于fun_param_is_arr(int* arr);//传递的不再是整个数组，而是数组的首地址

	//sizeof取得是指针变量，指针变量在32位长度是4，64位是8
	size_t size =  sizeof(arr);

	printf("size is %zu \n", size);

	//传递大小后
	for (int i = 0; i < arr_size/sizeof(int); i++) {
		printf("arr %d is %d \n", i, arr[i]);
	}

	return 1;
}


int swap(int* a, int* b) {

	int tmp = 0;

	tmp = *a;

	*a = *b;

	*b = tmp;

	return 0;

}

int* fun_point_back(int a,int b) {

	//不可以，因为局部变量在函数执行结束后就被释放
	/*int c = 100;

	int* p = &c;

	return */


	return &m;
}
