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


int mainY(void) {
	//实型

	float a = 3.14f;

	//默认保留6位小数，加小数可以指定精度
	printf("float a is %f \n", a);


	printf("float a is %.2f \n", a);


	double b = 3.1415926;


	printf("double b is %lf \n", b);

	printf("double b is %.4lf \n", b);


	int eight = 032;

	printf("eight is %d \n", eight);


	int address = 0x1A3F;

	printf("address is %d \n", address);
}



int mains(void) {
	//格式符

	int a = 10;

	printf("a is %d \n", a);//%d表示十进制整数

	printf("a is %u \n", a);//%u表示无符号十进制整数


	long b = 10l;


	printf("b is %ld \n", b);//%ld表示长整型

	printf("b is %lu \n", b);//%lu表示无符号长整型


	long long c = 10ll;

	printf("c is %lld \n", c);//%lld表示长长整型

	printf("c is %llu \n", c);//%llu表示无符号长长整型


	char x = 's';

	printf("x is %c \n", x);//%c表示字符型


	char str[] = "hello";

	printf("str is %s \n", str);//%s表示字符串


	char next = 333332;


	printf("next is %d \n", next);//char类型在打印时会被提升为int类型，因此这里使用%d打印是正确的,但是如果char的值超过了int的范围，打印出来的值就会不正确

	printf("next is %c \n", next);//超过了char的范围，打印出来的值就会不正确


	char chars[] = { 'h','e','\0'};

	char test[20] = "dddddddddddd";

	printf("chars is %s \n", chars);//%s表示字符串


	

}

//scanf函数的使用，不安全的用法，容易引起缓冲区溢出，在VS直接无法启动
void scanfNotSafe() {
	//char scanfChar[5];


	//scanf("%s", scanfChar);//注意这里的&符号不能加，因为scanfChar本身就是一个地址

	//printf("scanfChar is %s \n", scanfChar);
}

int plusPlus() {
	printf("ddd");
	int a = 3;
	s(a++);//a++会先传值，再自增

	int b = 3;

	s(++b);//++b会先自增，再传值

	//自增的区别只在当前行中存在，即下面的c和d
	int c = 3;

	c++;

	printf("c is %d", c);


	int d = 3;

	++d;

	printf("d is %d", d);
}

int mainVoid() {
	
	int a = 32;

	float b = 3.14f;

	printf("a is %.2llf", a + b);//类型提升，int提升为float，再进行运算

	int one = 352;

	char two = one;//int类型赋值给char类型，发生了类型降级,char最大是255，因此会发生数据丢失

	printf("two is %d \n", two);

	float price = 3.6f;

	int weight = 4;


	double sum = price * weight;//float类型提升为double类型，再进行运算

	printf("sum is %.2lf \n", sum);

	double sumTrans = (int)(price * weight);//强制类型转换，先进行运算，再转换为int类型，小数点后面的被截断

	printf("sumTrans is %llf \n", sumTrans);
}


int s(int a) {
	printf("a is %d \n", a);
}

