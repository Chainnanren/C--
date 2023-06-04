//C/C++程序的内存开辟
#include<stdio.h>
int globalvar = 1;//静态区
strtic int staticgloablvar = 1;//静态区
int main() {
	strtic int staticvar = 1;//静态区

	//栈区
	int localvar = 1;
	int num[10] = { 1,2,3,4 };

	//代码段
	char char2[] = "abcd";
	char* pchar = "abcd";

	//堆区
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(sizeof(int));
	int* ptr3 = (int*)realloc(sizeof(int) * 4);
	return 0;
}
/*C/C++程序内存分配的几个区域：
	1.栈区：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行
	结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率
	很高，但是分配的内容容量有限。栈区主要存放运行函数而分配的局部变量、函数
	参数、返回数据、返回地址等
	2.堆区：一般由程序员分配释放，若程序员不释放，程序结束时可能由OS（操作系统）
	回收。分配方式类似于链表
	3.数据段（静态区）：存放全局变量、静态数据。程序结束后由系统释放
	4.代码段：存放函数体（类成员函数和全局函数）的二进制代码*/


/*理解static关键字
 实际上普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁
 但是被static修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，
 直到程序结束才销毁，所以生命周期变长*/