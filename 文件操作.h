#pragma once

#ifndef FILE_OPERATE_FUN
#define FILE_OPERATE_FUN
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define WRITE_26_WORD_TO_FILE 0


#define WRITE_END_TO_FILE 0


#define mth_fgets_file 0 //fgets test

#define fputs_define 0 //fputs test


#define fgets_put_file 0 //读取用户输入并写入到文件

#define file_operate_flag 0 // 是否允许文件四则运算

#define file_printf_test_flag 0 // fprintf测试

#define file_scanf_test_flag 0 // fscanf测试

#define file_scanf_feof_test_flag 0 // fscanf的提前退出文件读取问题

#define file_scanf_out_of_range 0 // fscanf的边界问题

#define file_random_sort 0 // 生成随机数到文件后读取排序


#define file_write_flag 0//fwrite函数

#define copy_big_file_flag 0 //拷贝大文件

#define file_tell_flag 0 //ftell

#define file_read_after_write_flag 0 //综合测试文件写后读取


#define file_stat_flag 0 //stat函数 

#define file_flush_flag 1 //fflush

#define FILE_URL "C:\\Users\\Administrator\\Desktop\\ctest.txt"

#define BIG_FILE_COPY_URL "C:\\Users\\Administrator\\Desktop\\GoogleSansCode-v6.001.zip"

#define BIG_FILE_COPY_DEST_URL "C:\\Users\\Administrator\\Desktop\\GoogleSansCode111-v6.001.zip"

#define BIG_FILE_COPY_SIZE (1024*8) //8kb

static FILE* get_fp(const char* mode);//获取文件指针

static FILE* get_fp_url(const char* file,const char* mode);

static void fgets_file();//fgets 读取文件

static void read_file_c();

static void write_fputs();

static void read_write();

static void file_operate();//文件四则运算

static void file_printf();//fprintf

static void file_scanf();//fscanf

static void file_scanf_feof();//fscanf的feof提前结束问题

static void file_scanf_out_of_range_test();//fscanf的边界问题

static void file_random_sort_test();//生成随机数到文件后读取排序

static void file_write_test();//fwrite

static void big_file_copy();//大文件读写

static void file_tell_test();//ftell

static void file_write_after_read_test();

static void file_stat_test();

static void file_flush_test();


#define ADD '+'

#define SUBTRACT '-'

#define MULTIPY '*'

#define DIVIDE '/'


typedef struct Operate_s {
	int first_operate;

	char operate_flag;

	int second_operate;

	int operate_result;

} Operate_s;

typedef struct FileWrite_s {
	int age;

	char name[100];

	int class;
} FileWrite;

#endif // !FILE_OPERATE_FUN
