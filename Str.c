#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void str() {
	//printf特性是打印字符串必须碰到\0结束

	char str1[6] = { 'h','e','l','l','o','\0' };//第一种定义字符串

	char str2[] = "hello";//第二种定义字符串，这样的不需要加\0,因为会自动加

	printf("%s", str1);

	char write_word[100] = { 0 };//初始化数组，全是\0
	//scanf("%s", write_word);//这样写是因为数组本身就是地址，会写入一连串的字符

	for (size_t i = 0; i < 5; i++) {
		//接受到的每次输入的字符
		scanf("%c", &write_word[i]);//这样是在write_word[i]所代表的地址上赋值
	}

	for (size_t i = 0; i < sizeof(write_word) / sizeof(int); i++) {
		printf("%c", write_word[i]);
	}

	//字符串是字符数组的一种特性
	//printf("%s")打印字符串必须碰到\0结束，这是printf的特性

}


void strTest() {
	char str[11] = { 0 }; // 存入10个字符串，但是设置11长度，最后一个给\0

	int count[26] = { 0 };//26个英文字母出现的次数

	for (size_t i = 0; i < 10; i++)
	{
		scanf("%c", &str[i]);
	}

	printf("str is %s", str);

	for (size_t i = 0; i < 11; i++)
	{
		int index =  str[i] - 'a';//下标
		printf("index is %d\n", index);

		count[index]++;

		printf("storage count is %d \n", count[index]);
	}


	for (size_t i = 0; i < 26; i++)
	{
		if (count[i] != 0) {
			printf("%c appeared count is %d \n", (i + 'a'), count[i]);
		}
	}

	
}

void strMethod(void) {
	//gets 新版c已经没有gets了
	//获取字符串，返回字符串的首地址,获取首地址后，直接到\0就能获取到整个字符串了
	char str[10];
	printf("获取str,%s", fgets(str, sizeof(str), stdin));//获取字符串,实际只能存9个词，因为预留了一个给\0


	int res =  puts(str);//将一个字符串写出到屏幕 参数：待写出到屏幕的字符串,成功返回非负数，失败返回-1

	printf("puts result is  %d \n", res);

	int fputs_res =  fputs(str, stdout);//将一个字符串输出到指定输出,参数：待写出到输出的字符串；输出类型


	printf("fputs result is %d \n", fputs_res);

	char str_len[] = "hello world";

	printf("sizeof(str_len) is %zu", sizeof(str_len));//12,因为包含了\0

	printf("strlen(str_len) is %zu", strlen(str_len));//11，不包含\0
	
}


void str_concat(void) {
	//字符串拼接问题
	char str[6] = "hello";

	char str1[6] = "word";

	char str_c[20] = { 0 };

	int end_len = 0;
	size_t str_len =  strlen(str);

	for (size_t i = 0; i < str_len; i++)
	{
		str_c[i] = str[i];

		end_len++;
	}

	size_t str1_len = strlen(str1);

	for (size_t i = 0; i < str1_len; i++)
	{
		str_c[end_len+i] = str1[i];

	}



	printf("str_concat result is %s", str_c);
}

int main_str(void) {
	//str();
	//strTest();
	//strMethod();
	//str_concat();
	int arr[2] = { 0 };
	return 0;
}