//什么是文件
/*文件分为两种：程序文件、数据文件
  程序文件：包括源程序文件（后缀为.c），目标文件等等
  数据文件：内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件*/

//文件名包含3部分：文件路径+文件名主干+文件后缀
/*文件类型：
  1.文本文件
  2.二进制文件：数据在内存中以二进制的形式存储，如果不加转换的输出到外存*/
#include<stdio.h>
int main() {
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	//取a 占四个字节 存一个 到pf中
	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
	folose(pf);
	pf = NULL;
	return 0;
}
/*文件缓冲区
  ANSIC标准采用“缓冲文件系统”处理数据文件的，所谓缓冲文件系统
  是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块“文
  件缓冲区”。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓
  冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文
  件中读取数据输入到内存缓冲区，然后再从缓冲区逐个地将数据送到程
  序数据区。缓冲区的大小根据C编译系统决定的*/

/*文件指针
  缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”
  每个被使用文件都在内存中开辟了一个相应的文件信息区，用来存放文件
  的相关信息（如文件的名字，文件状态及文件当前的位置等）。这些信息是
  保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE*/

/*可以创建一个FILE*指针变量
  FILE* pf
  定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息
  区（是一个结构体变量）。通过该文件信息区中的信息就能够访问该文件。
  也就是说：通过文件指针变量能够找到与它关联的文件*/