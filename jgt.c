/* Note:Your choice is C IDE */
#include "stdio.h"
//�ṹ��
//�ṹ������

//����һ���ṹ������
//����һ��ѧ�������֣����䣬�绰���Ա�
/*struct-�ṹ����� stu-�ṹ���ǩ
struct stu-�ṹ������*/
struct stu
{
	//��Ա����
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}s1,s2,s3;//s1,s2,s3ȫ�ֱ���
//typedef-���ṹ�����͸�����
typedef struct stu
{
	//��Ա����
	char name[20];
	short age;
	char tele[12];
	char sex[5];
	}stu;//stu������
int main()
{
	//�����ṹ����� s-����
	struct stu s//�ֲ�����;
	//��ʼ��
	struct stu s={"����","20","18231169269","��"}��//
	stu s2;
	return 0;      
}  
struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};
struct T{
	char ch[20];
	struct S s;
	char *pc;
};
int main(){
	struct T t={"hehe", {100,'w',"hello world",3.14} ,NULL};
	printf("%s\n",t.ch);
	printf("%s\n",t.s.arr);
	return 0;
	}