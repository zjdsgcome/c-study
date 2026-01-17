#pragma once
#ifndef TONGXUNLU_HEAD
#define TONGXUNLU_HEAD
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum  Operation
{
	VIEW = 1,

	ADD,

	DEL,

	SORT
};

typedef struct Person {
	char name[100];				  //姓名
	int age;                      //年龄
	char sex[30];                 //性别
	char phone[20];               //姓名
	char addr[30];                //地址

} Person;

typedef struct Concat
{
	Person concat_p[100];

	int count;
} Concat;


typedef struct Book {
	int count;

	Person persons[100];
} Book;


void init(Book* book);//init

void view(const Book* book);//view


void add_concat(Book* book);//add

void del_concat(Book* book);


#endif // !TONGXUNLU_HEAD
