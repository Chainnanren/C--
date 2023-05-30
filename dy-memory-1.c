#define _CRT_SECURE_NO_WARNINGS
//动态内存管理

/*为什么存在动态内存分配
	1.空间开辟大小是固定的
	2.数组在申明的时候，必须指定数组的大小，她所需要的内存在编译时分配*/
/*int a = 10; 局局变量 - 栈区
  int g_a=10; 全局变量 - 静态区*/
/*栈区： 局部变量 函数的形式参数
  堆区： 动态内存分配
  静态区：全局变量 静态变量*/

//动态内存函数的介绍
//malloc函数 - 动态内存开辟
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
int main() {
	//向内存申请10个整形的空间
	int* p = (int*)malloc(10 * sizeof(int));
	//申请失败返回空指针
	if (p == NULL) {
		//打印错误原因的一个方式
		printf("%s\n", strerror(errno));
	}
	else {
		//正常使用空间
		int i = 0;
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++) {
			printf("%d ", *(p + i));
		}
	}
	//当动态申请的空间不再使用的时候，就应该还给操作系统

	//free函数 - 用来做动态内存的释放和回收
	/*如果参数p指向的空间不是动态开辟的，那free函数的行为是未定义的
	  如果参数p是NULL指针，则函数什么都不做*/
	free(p);
	p = NULL;
	return 0;
}