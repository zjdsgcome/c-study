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

static int printArr(int arr[],size_t size) {
	for (int i = 0; i < size; i++) {
		printf("arr %d is %d \n", i, arr[i]);
	}
}


//逆序打印数组
static int printArrReversed(int arr[], size_t size) {
	for (int i = size-1; i >= 0; i--)
	{
		printf("arr %d is %d \n", i, arr[i]);
	}
}

//数组
static int arr() {
	printf("arr \n");
	//相同类型的有序连续存储数据集合
	int arr[] = {1,2,3,4,5,6,7,8,9,10};//编译器自动求取元素个数

	int one_arr[] = { 0 };//此数组只有一个元素

	int custom_size_arr[10];//定义数组长度

	custom_size_arr[0] = 100;
	
	printArr(&custom_size_arr, sizeof(custom_size_arr) / sizeof(int));//第一个值是100，剩下值都是默认随机数

	//数组本身就是地址
	printf("arr address is %p",arr);

	//数组的地址就是数组首元素的地址
	printf("arr index 0 address is  %p \n", &arr[0]);
	printf("arr index 1 address is  %p \n", &arr[1]);//0和1之间差四个字节

	printf("arr index 2 address is  %p \n", &arr[2]);

	printf("arr index 3 address is  %p \n", &arr[3]);

	//数组的大小：sizeof(数组)/sizeof(数组元素类型)
	size_t size = sizeof(arr) / sizeof(int);
	printf("arr size is %zu \n", size);// sizeof运算符返回的类型是 size_t

	//打印指定索引
	printf("arr[0] is %d \n", arr[0]);


	printf("loop print arr \n");

	printArr(&arr,size);

	int reversedArr[] = { 2,3,1,4,5,61,23,3 };

	printf("reversed print arr \n");

	printArrReversed(&reversedArr, sizeof(reversedArr) / sizeof(int));

	printf("two arr \n");//二维数组

	int two_arr[2][3] = { {1,2,3},{2,3,4} };

	return 0;
}

int main(void) {
	
	arr();
	

	return 0;
}

