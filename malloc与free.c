#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(void) {

	int* p = (int*)malloc(10 * sizeof(int));// 申请10个int字节大小的空间

	if (p == NULL) // 防止申请失败
	{
		printf("没申请成功");
		return 1;//没申请成功，直接返回，取消对于NULL指针的引用
	}

	for (size_t i = 0; i < 10; i++)
	{
		p[i] = (int)(i + 100);
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("p i is %d", *(p+i));//不能使用*p然后p++，因为会修改掉p的指向，后面的free必须需要初始的p
	}
	free(p);//free后的地址一般来讲不会立即消失，需要手动置为NULL

	p = NULL;
}