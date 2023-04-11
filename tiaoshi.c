/* Note:Your choice is C IDE */
/*
	F5
		启动调试，经常用来直接调到下一个断点处
	F9
		创建断电和取消断电 断电的重要作用，可以
		在程序的任意位置设置断点，这样就可以使得
		程序在想要的位置随意停止执行，继而一步步
		执行下去
	F10
		逐过程，通常用来处理一个过程，一个过程可以
		是一次函数调用，或者是一条yuju
	F11
		逐语句，就是每次都执行一条语句，但是这个快
		捷键可以使我们的执行逻辑进入函数内部
		（最常用的）
	CTRL + F5
		开始执行不调试，如果你想让程序直接运行起来
		而不调使就可以直接使用
	Shift + F11
		跳出语句
*/
#include "stdio.h"
void main()
{
    int i=0;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<=12;i++){
    	printf("hehe\n");
    	arr[i]=0;
    }
    system("puase");
    return 0;
}


#include<stdio.h>
int main() {
	int i = 0;
	int sum = 0;
	int ret = 1;
	int n = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		int j = 0;
		ret = 1;
		for (j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}


//strcpy
#include<stdio.h>
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

#include<stdio.h>
//不需要返回，返回类型为void
void my_strcpy(char* best, char* src) {
	//字符指针解引用能访问一个字符
	//在这个循环中是如此的 '\0' 并没有赋给best
	while (*src != '\0') {
		*best = *src;
		src++;
		best++;
	}
	//这个时候 *src 已经等于 '\0' ,所以
	*best = *src;
}
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//优化 1.
#include<stdio.h>
void my_strcpy(char* best, char* src) {
	/*while (*src != '\0') {
		*best++ = *src++;
	}
	*/
	//当arr1或arr2为NULL时就会把问题规避掉
	if (best != NULL && src != NULL) {
		while (*best++ = *src++) {
			//空语句跳出循环
			;
		}
	}
}
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
//优化 2.
#include<stdio.h>
#include<assert.h>//assert-函数
void my_strcpy(char* dest, char* src) {
	//当arr1或arr2为NULL时就会把问题规避掉
	assert(dest != NULL);//断言
	assert(src != NULL);
	while (*dest++ = *src++) {
		//空语句跳出循环
		;
	}
}
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, NULL);
	printf("%s\n", arr1);
	return 0;
} 

//优化 3.
#include<stdio.h>
#include<assert.h>//assert-函数
//const将变量变为不可修改的常量
void my_strcpy(char* dest, const char* src) {
	//当arr1或arr2为NULL时就会把问题规避掉
	assert(dest != NULL);//断言
	assert(src != NULL);
	while (*dest++ = *src++) {
		//空语句跳出循环
		;
	}
}
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, NULL);
	printf("%s\n", arr1);
	return 0;
}

//const的用法
int main() {
	const int num = 0;
	const int* p = &num;
	/*const 放在指针变量的*左边时，修饰的是*p，也
	就是说：不能通过p来改变*p(num)的值*/
	*p = 20;
	printf("/d\n", num);
	return 0;
}


int main() {
	const int num = 0;
	int* const p = &num;
	/*const 放在指针变量的*右边时，修饰的是指针变量p，也
	就是说：p不能被改变*/
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;
}


//优化 4.
#include<stdio.h>
#include<assert.h>//assert-函数
//const将变量变为不可修改的常量
char* my_strcpy(char* dest, const char* src) {
	//当arr1或arr2为NULL时就会把问题规避掉
	char* ret = dest;
	assert(dest != NULL);//断言
	assert(src != NULL);
	/*把src指向的字符串拷贝到dest指向的空间，包含
	'\0'字符*/
	while (*dest++ = *src++) {
		//空语句跳出循环
		;
	}
	return ret;
}
int main() {
	//strcpy - 字符串拷贝
	char arr1[] = "############";
	char arr2[] = "bit";
	//链式访问
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}

int my_style(const char* str) {
	int count = 0;
	assert(str 1 = NULL);
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
int main() {
	char arr[] = "abcdef";;
	int len = my_style(arr);
	printf("d\n", len);

	return 0;
}

