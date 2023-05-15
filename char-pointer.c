//free只负责释放空间，不会把指针变量置为NULL
//32位系统下任何类型指针的长度都是4个字节
//指针的数据类型声明的是指针实际指向内容的数据类型
//野指针是指未分配或者已经释放的内存地址
//数组指针是一种指针，是一种指向数组的指针
//指针数组是一种数组

//定义一个函数指针，指向的函数有两个int形参并且返回一个函数指针，返回的指针
//指向一个有一个int形参且返回int的函数   int(*(*F)(int,int))(int)
//一个参数为int*，返回值为int的函数指针：int(*fun)( int*)
int main() {
	char str1[] = "hello bit";
	char str2[] = "hello bit";
	char* str3[] = "hello bit";
	char* str4[] = "hello bit";
	if (str1 ==str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4) 
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	//str1不等于str2  地址不相等
	//str3等于str4    全都指向hello bit首字母的地址
	return 0;
}


//实现一个函数，可以左旋字符串中的k个字符
/*例如：
		ABCD左旋一个字符得到BCDA
		ABCD左旋两个字符得到CDAB*/

//方法1：
#include<stdio.h>
#include<string.h>
void left_move(char arr[],int k) {
	int letf = 0;
	int right = 0;
	int i = 0;
	int len = strlen(arr);
	k %= len;
	for (i = 0; i<k; i++) {
		//旋转一个字符
		char tmp = arr[0];
		//将剩下的字符向前移动
		int j = 0;
		for (j = 0; j < len; j++) {
			arr[j] = arr[j + 1];
		}
		//将字符放到最后
		arr[len-1] = tmp; 
	}

}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr,k);
	printf("%s\n", arr);
	return 0;
}

//方法2：
#include<assert.h>
void reverse(char* left, char* right) {
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k) {
	int len = strlen(arr);
	k %= len;
	//要左旋的字符
	reverse(arr, arr + k - 1);
	//不需要左旋的字符
	reverse(arr + k, arr + len - 1);
	//整体逆序
	reverse(arr, arr + len - 1);
}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}


//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增d的，
//请编写程序在这样的矩形中查找某个数字是否存在
//求：时间复杂度小于o(N)
//o(N)最坏的情况下需要找n次才能找到该数字
struct Point {
	int x;
	int y;
};
struct Point find_num(int arr[3][3], int r, int c, int k) {
	int x = 0;
	int y = c - 1;
	struct Point p = { -1,-1 };
	while (x <= r - 1 && y >= 0) {
		if (k < arr[x][y]) {
			y--;
		}
		else if (k > arr[x][y]) {
			x++;
		}
		else {
			p.x = x;
			p.y = y;
			return p;
		}
	}
	return p;//找不到
}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	scanf("%d", &k);
	struct Point ret = find_num(arr, 3, 3, k);
	printf("%d %d\n", ret.x,ret.y);
	return 0;
}


//方法2：
//返回型参数
#include<stdio.h>
int find_num(int arr[3][3], int *px, int *py, int k) {
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0) {
		if (k < arr[x][y]) {
			y--;
		}
		else if (k > arr[x][y]) {
			x++;
		}
		else {
			*px = x;
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;//找不到
}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;;
	scanf("%d", &k);
	int a = 3;//行
	int b = 3;//列
	int ret = find_num(arr, &a, &b, k);
	if (ret == 1) {
		printf("%d %d\n", a, b);
	}
	else
		printf("找不到\n");
	return 0;
}