#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void point_str(void);

void point_str_address(void);


void str_len(char[]);

int str_cmp(char[], char[]);//比较字符串大小

void str_cp(char* source, char* dest);//字符串拷贝

char* str_trim(char* source);

int str_appear_count(char* str, char* appear_str);


void revert_str(char* str);//字符串逆序返回

int main_str_p(void) {
	point_str();//指针字符串是常量，不可修改

	point_str_address();//指针字符串的地址都是一致的

	str_len("hello world");//字符串长度
	
	printf("字符串大小比较结果为 %d \n" ,str_cmp("hello worldz", "hello worl"));//字符串长度比较

	char* str = "source";


	char dest[100] = {0};

	str_cp(str, dest);

	printf("目标数组拷贝 %s \n",dest);//将字符串拷贝

	printf("字符串去空格 %s", str_trim("h e l l o"));

	char str_z[100] = "helloplololo";


	char* appear_str = "lo";

	char* appear = strstr(str_z, appear_str);

	printf("appear %s", appear);

	printf("%s在%s中出现的次数为%d \n",appear_str,str_z, str_appear_count(str_z, appear_str));


	char* revert_str_origin = "hello";

	revert_str(revert_str_origin);

	printf("字符串逆序输出 %s \n", revert_str_origin);

	char strcpy_src[100] = "helloworld";

	char strcpy_dest[100] = { 0 };

	printf("字符串拷贝 strcpy %s", strcpy(strcpy_dest, strcpy_src));//不安全，如果给的dest空间不够大，会写出

	char strncpy_dest[50] = { 0 };

	printf("字符串拷贝，但是strncpy %s \n", strncpy(strncpy_dest, strcpy_src, 5));//把src拷贝到dest，但是只拷贝n字节


	char str_concat_dest[100] = "hello";


	char str_concat_src[100] = "world";

	printf("字符串拼接 strcat ,%s \n", strcat(str_concat_dest, str_concat_src));

	char str_nconcat_dest[100] = "hello";
	printf("字符串拼接 strncat, %s \n",strncat(str_nconcat_dest,str_concat_src,3));//把src的前n个字符拷贝到dest，并返回新字符串


	char str_cmp_src[100] = "hella";

	char str_cmp_dest[100] = "helle";

	printf("字符串比较 %d \n", strcmp(str_cmp_src, str_cmp_dest));//比较两个字符串，如果相等返回0，如果不相等，进一步比较s1和s2对应位的ascall码，s1>s2 返回1，s1<s2返回-1


	char  str_ncmp_src[100] = "hello";

	char str_ncmp_dest[100] = "hellz";

	printf("字符串strncmp比较,%d \n", strncmp(str_ncmp_src, str_ncmp_dest, 3));//比较两个字符串，但是只比较前n个字符


	char s_print_f_buf[100];

	sprintf(s_print_f_buf, "%d%c%d=%d", 10, '+', 34, 10 + 34);//将后面的结果写入前面

	printf("sprintf写入后结果 %s \n", s_print_f_buf);


	char s_scan_f_buf[] = "10+24=34";

	int s_scanf_a, s_scanf_b, s_scanf_c;

	int s_scanf_res =  sscanf(s_scan_f_buf, "%d+%d=%d", &s_scanf_a, &s_scanf_b, &s_scanf_c);//从第一个参数读取字符串按照第二个参数格式化字符串返回第三个参数的值


	printf("sscanf 调用后结果a:%d,b:%d,c:%d,sscanf返回结果:%d \n",s_scanf_a,s_scanf_b,s_scanf_c,s_scanf_res);
}

void revert_str(char* str) {
	//源字符串逆序
	//hello -> olleh
	char* str_start = str;

	char* str_end = str + strlen(str) - 1;

}

int str_appear_count(char* str, char* appear_str) {
	//appear_str在str中出现的次数

	int count = 0;
	char* p =  strstr(str, appear_str);

	while (p) {
		count++;
		p += strlen(appear_str);

		p = strstr(p, appear_str);
	}

	return count;
}



char* str_trim(char* source) {
	//字符串去空格
	char dst[100] = { 0 };

	int i = 0;

	int dst_i = 0;

	while (*source != '\0') {

		if ( *source != ' ') {
			dst[dst_i] = *source;

			dst_i++;
		}

		source++;
	}

	return dst;
}

void str_cp(char* source, char* dest) {
	//字符串拷贝
	
	int i = 0;

	while (source[i] != 0) {

		dest[i] = source[i];

		i++;
	}

	//最后补\0

	dest[i] = 0;
}

int str_cmp(char a[], char b[]) {
	//比较字符串长度,相同返回0，不同则依次比较ascall码，大于则立即返回1，否则返回-1

	int i = 0;

	while (a[i] == b[i]) {
		if (a[i] == '\0') {
			return 0;//同时相等且同时为\0
		}
			i++;
	}
	return a[i] - b[i] > 0 ? 1 : -1;
	
}

void str_len(char a[]) {
	printf("字符长度为 %zu", strlen(a));
}

void point_str(void) {
	//指针与字符串

	char str[] = "hello";


	char* str1 = "hello";//字符串常量，不可修改


	//str[0] = 'H';

	//str1[0] = 'H';

	printf("str is %s", str);


	printf("str1 is %s", str1);


}


void point_str_address(void) {
	char str[] = "hello";


	char str1[] = "hello";


	char* m = "hello";

	char* n = "hello";

	printf("\n");

	printf("str is %p \n", str);

	printf("str1 is %p \n", str1);


	printf("m is %p \n", m);


	printf("n is %p \n", n);


}