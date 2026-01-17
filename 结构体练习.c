#include "通讯录.h"
int main_concat_test() {
	Person person[100];

	int operate = 0;

	do
	{

		Book book;

		init(&book);

		printf("欢迎使用通讯录\n");
		printf("******************\n");
		printf("******************\n");

		printf("*******1-- 查看通讯录************ \n");

		printf("*******2-- 添加通讯录************ \n");

		printf("*******3-- 删除通讯录************ \n");

		printf("*******4-- 排序通讯录************ \n");

		printf("*******1-- 查看通讯录************ \n");

		printf("请输入操作数:>");

		scanf("%d", &operate);
		switch (operate) {
		case VIEW:
			view(&book);
			break;
		case ADD:
			add_concat(&book);
			break;
		case DEL:
			del_concat(&book);
			break;
		case SORT://TODO 排序
			printf("todo 排序操作");
			break;
		}
		


	} while (1);

	printf("hello world");
}
