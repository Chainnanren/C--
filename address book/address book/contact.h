#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
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
	struct PeoInfo data[MAX];//���1000���˵���Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};

//�������� 
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);

//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps);

//�޸�ָ���˵���Ϣ
void ModifyContact(struct Contact* ps);

//���������˵���Ϣ
void SortContact(struct Contact* ps);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);
