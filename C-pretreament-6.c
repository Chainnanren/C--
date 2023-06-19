//命令行定义
/*许多C的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。例如：当我们根据同一
个源文件要编译出不同的一个程序的不同版本的时候，这个特性有点用处。（假定某个程序声明了一个某个
长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另一个机器内存大写，我们需要一个数组
能够大写）*/

//条件编译
//在编译一个程序的时候如果我们要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令
#include<stdio.h>
#define DEBUG
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
#ifdef DEBUG
		printf("%d\n", arr[i]);
#endif
	}
	return 0;
}


//条件编译指令

/* #if 常量表达式 (比如：0,1，1-1)
	//....
	#endif*/
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = 0;
#if 1
	printf("%d\n", arr[i]);
#endif
	}
	return 0;
}

/*多个分支的条件编译
	#if
	#elif
	#else
	#endif*/
int main() {
#if 1==1
	printf("haha\n");
#elif 2==1
	printf("hehe\n");
#else
	printf("嘿嘿");
#endif
}

/*判断是否被定义*/
int main() {
#if defined(DEUBG)//被定义
	printf("hehe\n");
#endif


#if !defined(DEUBG)//没定义
	printf("hehe\n");
#endif

/*#ifdef DEBUG
	printf("hehe\n");
#endif*/

/*#ifndef DEBUG    -    没定义
printf("hehe\n");
#endif*/
	return 0;
}

/*嵌套指令*/
#if defined(QS_UNIX)
	#ifdef OPTION1
		n1();
	#endif
	#ifdef OPTION2
		n2;
	#endif
#elif defined(QS_UNIX)
	#ifdef OPTION2
		n2();
	#endif
#endif


//文件包含
/*这种替换方式很简单：预处理器先删除这条指令，并用包含文件的内容替换。这样一个源文件被包含
10次，那就实际被编译10次*/

/*头文件包含
	1.本地文件包含
	#include "filename"
	查找策略：先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标
	准位置查找头文件。如果找不到就提示编译失败。

	2.库文件包含
	#include<filename.h>
	查找头文件直接去标准路径下去查找，如果找不到就提示编译失败*/
	

//避免头文件被多次引用
//方法一：
#ifndef __TEST_H__
#define __TEST_H__
		int Add(int x, int y);
#endif

//方法二：
#pragma once
		int Add(int x, int y);

/*预处理阶段所用到的指令 - 预处理指令
  1.条件编译指令
  2.#include
  3.#define
  ...*/