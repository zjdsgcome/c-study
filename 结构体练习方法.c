#include "通讯录.h"
#include <stdlib.h>
#include <string.h>
void init(Book* book) {
	book->count = 0;
	memset(book->persons, 0, sizeof(book->persons));
}


void view(const Book* book) {
	for (int i = 0; i < book->count; i++) {
		printf("addr is %s ,\t age is %d , \t name is %s , \t phone is %s ,\t sex is %s \n",
			book->persons[i].addr,
			book->persons[i].age,
			book->persons[i].name,
			book->persons[i].phone,
			book->persons[i].sex
			);
	}
}

void add_concat(Book* book) {
	printf("请输入地址>");

	scanf("%s", book->persons[book->count].addr);//数组本身即地址

	printf("\n请输入年龄>");

	scanf("%d", &(book->persons[book->count].age));

	printf("\n请输入电话>");

	scanf("%s", book->persons[book->count].phone);

	printf("\n请输入性别");

	scanf("%s", book->persons[book->count].sex);


	book->count++;

	view(book);
}

static int find_by_name(Book* book,char name[]) {
	for (int i = 0; i < book->count; i++) {
		if (strcmp(book->persons[i].name, name) == 0) {
			return i;
		}
	}

	return -1;
}


void del_concat(Book* book) {

	char del_name[50] = {0};

	printf("请输入删除name>");
	
	scanf("%s", &del_name);

	int del_pos = find_by_name(book,del_name);

	for (int i = del_pos; i < book->count-1; i++) {//-1防止数组下标越界
	
		book->persons[i] = book->persons[i + 1];
	}

	book->count--;
}