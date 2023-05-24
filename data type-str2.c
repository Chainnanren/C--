/*结构体的对齐规则
  1.第一个成员在与结构体变量偏移量为0的地址处
  2.其他成员变量要对齐到某个数字(对齐数)的整数倍的地址处
  （对齐数 = 编译器默认的一个对齐数与该成员大小的较小值）
  * VS默认的值为8
  3.结构体总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍
  4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数处，结构体的
  整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍*/
//结构体内存对齐
struct S1 {
	char c1;
	int a;
	char c2;
};
struct S2 {
	char c1;
	char c2;
	int a;
};
int main() {
	struct S1 s1 = { 0 };
	printf("%d\n", sizeof(s1));
	struct S2 s2 = { 0 };
	printf("%d\n", sizeof(s2));
	return 0;
}
//12 8
struct S3 {
	double d;
	char c;
	int i;
};
int main() {
	printf("%d\n", sizeof(struct S3));
	return 0;
}
//16

//结构体嵌套问题
struct S4 {
	char c1;
	struct S3 s3;
	double d;
};//32

int main() {

	return 0;
}

/*为什么内存对齐？
  1.平台原因：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台
  只能在某些地址处取某些特定的数据，否则抛出硬件异常
  2.性能原因：数据结构（尤其是栈）应该尽可能地在自然边界上对齐。原因在于，
  为了访问未对齐的内存，处理器需要作两次访问；而对齐的内存访问仅需要一次访问*/
//总体来说：
//		结构体的内存对齐是拿空间来换取时间的做法

/*那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：
		让占用空间小的成员尽量集中到一起*/




//修改默认对齐数
//设置默认对齐数为4
#pragma pack(4)
struct S{
	char c1;
	double d;
};

//取消设置的默认对齐数,还原为默认
#pragma pack()

int main() {
	struct S s;
	printf("%d\n", sizeof(s));
	return 0;
}
//结论：
	//结构在对齐方式不合适的时候，我们可以自己更改默认对齐数

//offsetof计算结构体成员相对于结构体起始位置的偏移量（不是函数  是宏）
#include<stddef.h>
struct S {
	char c;
	int i;
	double d;
};
int main() {
	//offsetof();
	printf("%d\n", offsetof(struct S, c));//0
	printf("%d\n", offsetof(struct S, i)); //4
	printf("%d\n", offsetof(struct S, d)); //8
	return 0;
}