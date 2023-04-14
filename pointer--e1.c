//指针进阶

//1.字符指针
#include<stdio.h>
int main() {
	char* p = "abedef";//"abcdef"是一个常量字符串
	*p = 'w';
	printf("%s\n", p);
	return 0;
}

int main() {
	char arr1[] = "abcdef";
	char arr2[] = "acbdef";
	char* p1 = "abedef";
	char* p2 = "abcdef";
	if (arr1 == arr2) {
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
}
//结果为haha

int main() {
	char arr1[] = "abcdef";
	char arr2[] = "acbdef";
	char* p1 = "abedef";
	char* p2 = "abcdef";
	if (p1 == p2) {
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
}
//结果为hehe

//指针数组 是数组,用来存放指针的
int main() {
	int arr[10] = { 0 };//整型数组
	char ch[5] = { 0 };//字符数组
	int* parr[40];//存放整形指针的数组 - 指针数组
	char* pch[5];//存放字符指针的数组 - 指针数组
	return 0;
}
//指针数组的用法
int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int* arr[4] = { &a,&b,&c,&d };
	return 0;
}
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2, 3, 4, 5, 6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[] = { arr1,arr2,arr3 };
	int i = 0;
	for (i = 0; i < 3; i++) {
		int j = 0;
		for (j = 0; j < 5; j++) {
			printf("%d", *(parr[i] + j));
		}
		printf("\n");

	}

}

//数组指针的用法
int main() {
	int* p = NULL;//p是整形指针 - 指向整形的指针 - 可以存放整形的地址
	char* pc = NULL;//pc是字符指针 - 指向自负的指针 - 可以存放字符的地址
	//数组指针 - 指向数组的指针 - 存放数组的地址
	int arr[10] = { 0 };
	//arr - 首元素地址
	//&arr[0] - 首元素的地址
	//&arr - 数组的地址
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;//数组的地址要存起来
	//上面的p就是数组指针
	return 0;
}

int main() {
	char* arr[5];
	char* (*pa)[5] = &arr;
	//*说明pa是指针
	//pa指向的数组是五个元素
	//指针变量的名字
	//pa指向的数组的元素类型是char*
	return 0;
}

int main() {
	char* arr[5];
	char* (*pa)[5] = &arr;

	int arr2[10] = { 0 };
	int(*pa2)[10] = &arr2;
	return 0;
}

//数组指针的使用
void print1(int arr[3][5], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*p)[5], int x, int y) {
	int i = 0;
	for (i = 0; i < x; i++) {
		int j = 0;
		for (j = 0; j < y; j++) {
			printf("%d ", *(*(p + i) + j));
		}
	}
	int main() {
		int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
		print1(arr, 3, 5);
		print2(arr, 3, 5);
		return 0;
	}

	int arr[5];//arr是一个5个元素的整型数组
	int* parr1[10];//parr1是一个数组，数组有10个元素
	//每个元素的类型是int* parr1是指针数组
	int(*parr2)[10];//parr2是一个指针，该指针指向了一个元素
	//数组有110个元素，每个元素类型是int
	int(*(parr3[10]))[5];
	//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针
	//该数组指针指向的数组有5个元素,每个元素是int
