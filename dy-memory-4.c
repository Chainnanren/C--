//几个经典的笔试题

//1.
#include<stdio.h>
void GetMemory(char* p) {
	p = (char*)malloc(100);
}
void test(void) {
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");//程序崩溃
	printf(str);
}
int main() {
	test();
	return 0;
}
/*1.运行代码程序会出现崩溃的现象 
  2.程序存在内存泄漏的问题
  （str以值传递的形式给p，p是GetMemory函数的形参，只能函数内部有效
   等GetMemory函数返回之后，动态开辟内存尚未释放并且无法找到，所以会造成内存泄漏）*/

//更改 1.
#include<stdio.h>
void GetMemory(char** p) {
	*p = (char*)malloc(100);
}
void test(void) {
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");//程序崩溃
	printf(str);
	free(str);
	str = NULL;
}
int main() {
	test();
	return 0;
}

//更改 2.
#include<stdio.h>
char* GetMemory(char* p) {
	p = (char*)malloc(100);
	return p;
}
void test(void) {
	char* str = NULL;
	str = GetMemory(str);
	strcpy(str, "hello world");//程序崩溃
	printf(str);
	free(str);
	str = NULL;
}
int main() {
	test();
	return 0;
}

//2. - 返回栈空间的地址的问题
char* GetMemory(void) {
	char p[] = "helloworld";
	return p;
}
void test(void) {
	char* str = NULL;
	str = GetMemory();//返回时p的空间会销毁，并设成随机值
	printf(str);
}
int main() {
	test();
	return 0;
}

int* test() {
	static int a = 10;//static使空间生命周期延长 - 静态区
	return &a;
}
int main() {
	int* p = test();
	*p = 20;
	return 0;
}

int* test() {
	//堆区 - 函数结束后ptr会销毁，但malloc开辟的空间不会销毁，并将此空间传给了指针变量p
	int* ptr = malloc(100);
	return ptr;
}
int main() {
	int* p = test();
	return 0;
}

//3.
void GestMemory(char** p, int num) {
	*p = (char*)malloc(num);
}
void test(void) {
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);//忘记释放动态开辟的内存，导致内存泄露
}
int main() {
	test();
	return 0;
}

//4.
void test(void) {
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	//更改
	str = NULL;
	/*free释放了动态开辟的内存，但没有将str置为NULL，所以str仍然指向
	动态开辟的首地址，从而导致非法访问内存*/
	if (str != NULL) {
		strcpy(str, "world");
		printf(str);//最终输出结果是 world
	}
}
int main() {
	test();
	return 0;
}

int main() {

	return 0;
}