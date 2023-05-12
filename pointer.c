//二级指针是用来存放一级指针地址的
//二级指针大小：32位平台是4个字节 64位平台是8个字节
//整形指针+1向后偏移一个整型
//指针 - 指针得到的是指针和指针之间的元素个数
//指针数组要给数组设立大小
int main() {
	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	unsigned long* pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
	return 0;
}
//6 12


//写一个函数，可以逆序一个字符串的内容
#include<stdio.h>
#include<string.h>
#include<assert.h>
void BackWard(char* str) {
	assert(str);
	char* left = str;
	int len = strlen(str);
	char* right = str + len - 1;
	while (left<right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
int main() {
	char arr[256] = { 0 };
	scanf("%s", &arr);//不能读取空格
	gets(arr);//读取一行，不关注空格
	//逆序函数
	BackWard(arr);
	printf(" % s\n", arr);
	return 0;
}




//求Sn=a+aa+aaa+aaaa+aaaaa的前五项之和，其中a是一个数字
int main() {
	int a = 0;
	int n = 0;
	int sum = 0;
	int i = 0;
	int ret = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++) {
		ret = ret * 10 + a;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}



//判断水仙花数
#include<math.h>
int main() {
	int i = 0;
	for (i = 0; i <= 100000; i++) {
		//判断i是否为水仙花数(自幂数)
		//1.计算i的位数
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp /= 10) {
			n++;
		}
		//2.计算i的每一位的n次方之和
		tmp = i;
		while (tmp) {
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//3.比较i和sum
		if (i == sum) {
			printf("%d ", i);
		}


	}
	return 0;
}



//用C语言在屏幕上输出一个菱形的图案
#include<stdio.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);
	//打印上半部分
	for (i = 0; i < line; i++) {
		//打印空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++) {
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");

	}
	//打印下半部分
	for (i = 0; i < line - 1; i++) {
		//打印空格
		int j = 0;
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}



