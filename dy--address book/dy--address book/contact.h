#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//#define MAX 1000
#define DEFAULT_SZ 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum Option {
	EXIT,
	ADD,
	DEL,
	SEARECH,
	MODIFY,
	SHOW,
	SORT
};
struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact {
	struct PeoInfo* data;//存放1000个人的信息
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量
};

//声明函数 
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定人的信息
void SearchContact(const struct Contact* ps);

//修改指定人的信息
void ModifyContact(const struct Contact* ps);

//排序所有人的信息
void SortContact(struct Contact* ps);

//释放空间
void DestoryContact(struct Contact* ps);

//打印通讯录中的信息
void ShowContact(const struct Contact* ps);

