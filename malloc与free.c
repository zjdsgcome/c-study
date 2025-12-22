#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Person {
	char name[200];

	unsigned int age;

} Person;

Person* get_person(void);


void two_arr_malloc(void);

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
		printf("p i is %d \n", *(p+i));//不能使用*p然后p++，因为会修改掉p的指向，后面的free必须需要初始的p
	}
	free(p);//free后的地址一般来讲不会立即消失，需要手动置为NULL

	p = NULL;

	//结构体

	Person* person = get_person();

	if (person != NULL) {
		printf("结构体person age is %u \n", (*person).age);//括号不能少,.运算符优先级很高
		printf("结构体person age is %u \n", person->age);//指针取值的另一种写法
	}

	free(person);

	person = NULL;//释放指针后，置为NULL，防止野指针

	
}

Person* get_person(void) {
	Person* heap_person = (Person*)malloc(sizeof(struct Person));//堆上申请内存，在方法结束后依然存在

	Person stack_person = {"hello world",20};//栈上申请内存，方法结束后就释放了

	if (heap_person != NULL) {
		(*heap_person).age = stack_person.age;//括号不能少,.运算符优先级很高
	}

	return heap_person;
}


void two_arr_malloc(void) {
	//二级指针
	int** p = (int**)malloc(sizeof(int*) * 5);//int** p  = int*[]p  = [int*,int*]
	if (p != NULL) {
		for (size_t i = 0; i < 5; i++)
		{
			p[i] = (int)malloc(sizeof(int)*5);//每一个都是int* int* = (int)malloc(sizeof(int));
		}
		for (size_t i = 0; i < 5; i++) { //先释放内层
			free(p[i]);
			p[i] = NULL;
		}
	}

	free(p);

	p = NULL;

}