#include <stdio.h>
#include <float.h>

#define PI 3.14

enum {
	MON = 1,
	TUE = 4
} day;

int max(int a, int b) {
	return a - b >=0 ? a : b;
}

int executeCallBack(int a,int b,int (*p)(int,int)) {
	if (p != NULL)
	{
		return p(a, b);
	}
	return 1;
}

int mainNext(void) {
	printf("hello world,pi is %f \n",PI);
	unsigned int round = 100;
	printf("%d \n", round);
	int size = sizeof(float);
	printf("%d \n", size);
	printf("========================= \n");
	printf("float max is %f \n", FLT_MAX);

	printf("=======================\n");

	for (day = MON; day <= TUE; day++) {
		printf("day enum is %d", day);
	}

	printf("===================================\n");

	//point

	int var = 20;

	int* ip = NULL;

	ip = &var;

	printf("ip point var %d",*ip);

	printf("the address of var %p", &var);


	//function point

	int (*p)(int, int) = max;

	int maxInt = p(p(1,2),3);

	printf("max is %ud", maxInt);


	printf("===========================> \n");

	printf("execute callback is %d", executeCallBack(1, 2, NULL));

	return 0;
}


int mainPoint() {


	//0x的作用是告诉c这是个十六进制
	//为什么0x后面是8个1？一个字节由8位组成，十六进制一个就是4位，因此0x后面8个1代表了32个二进制位，假设后面都是F，即0x后面8个F，即表示的10进制数为4,294,967,295，因此使用0x后面8位是合理的
	//其次0x后面跟8位目的也有一个int是4个字节，1个字节=8位，总共是32位，因此0x后面跟8个其实就填满了这32位
	int a = 0x11111111;

	int b = 0x22222222;

	int* p = &a;//声明指针变量

	char* p1 = &b;


	//11 11 11 11 => 00 00 00 00
	*p = 0;//int是4个字节，这样做是从地址p开始，写入sizeof(int)个字节的0，即4字节的0，即4*8=32位二进制皆为0，因此int a 全都变成了0，因为他后面接了8个数，即32位

	//22 22 22 22 => 00 22 22 22
	*p1 = 0;//从地址p1开始，写入1个字节的0,变成了00222222

	//字节序的影响
	//常见的x86/x86-64架构计算机通常采用小端序存储，就是小的是第一位，就是源22222222中最右边的22被放在了第一位

	//在小端序系统中，当从内存中读取一个多字节数据（比如整数）时，CPU和内存管理单元（MMU）的硬件电路会自动地、透明地完成字节顺序的转换，将存储时的“逆序”重新转回“正序”，从而返回给程序正确的数值

	printf("%x \n", a);

	printf("%x", b);
}


int main(void) {
	unsigned int p = 100;

	int* all = &p;

	*all =  *all + 1;


	printf("%d", p);
}