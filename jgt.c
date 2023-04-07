/* Note:Your choice is C IDE */
#include "stdio.h"
//结构体
//结构的声明

//定义一个结构体类型
//描述一个学生（名字，年龄，电话，性别）
/*struct-结构体变量 stu-结构体标签
struct stu-结构体类型*/
struct stu
{
	//成员变量
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}s1,s2,s3;//s1,s2,s3全局变量
//typedef-给结构体类型改名字
typedef struct stu
{
	//成员变量
	char name[20];
	short age;
	char tele[12];
	char sex[5];
	}stu;//stu是类型
int main()
{
	//创建结构体变量 s-变量
	struct stu s//局部变量;
	//初始化
	struct stu s={"张三","20","18231169269","男"}；//
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