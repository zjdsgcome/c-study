#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
	char name[100];

	int age;
} s1,s2; // s1和s2是全局变量


struct {
	char name[100];
	int age;
} nameless; // 匿名结构体类型，只能用nameless


struct Node {
	int data;

	struct Node* next;
};//结构体自引用


typedef struct {
	int id;

	char name[100];
} Teacher;//typedef 原类型 新别名

typedef struct Student HightStudent;//为Student标签定义别名为HighStudent


typedef struct NodeP {
	int data;

	struct NodeP* next;
} Nodexxx;//自引用，总的标签名(NodeP),自引用内部的struct名必须一致

typedef struct NodeP Xxx;//再次起别名


typedef struct NodePoint {
	int data;

	struct NodePoint* next;
}* NodePtr;//定义链表指针类型

typedef struct NodePoint* NodePtrNext;//定义链表指针类型

struct Size {
	char s1;

	char s2;

	int i;
};


struct Size_Next {
	char s1;

	int i;

	char s2;
};

void get_struct_size() {
	//获取结构体大小

	struct Size s1;

	struct Size_Next s2;

	printf("Size size is %zu \n", sizeof(s1));//8

	printf("Size_Next size is %zu \n", sizeof(s2));//12
}




int main(void) {
	s1.age = 100;
	HightStudent s3;//s3是局部变量

	Teacher teacher;//融合
	Xxx first;

	NodePtr ptr;

	NodePtrNext ptrNext;

	get_struct_size();
}