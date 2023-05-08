//指针和数组笔试题解析

//整型数组
int main() {
	//数组名是首元素地址
	/*两个例外
	* 1. sizeof - 数组名表示整个数组
	* 2. &数组名 - 数组名表示整个数组*/
	//一维数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16 - 计算数组总大小
	printf("%d\n", sizeof(a + 0));//4 - 数组名这里表示首元素地址
	printf("%d\n", sizeof(*a));// 4 - 数组名表示首元素地址，*a就是首元素
	printf("%d\n", sizeof(a + 1));//4 - a+1是第二个元素的地址
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4 - &a取出的是数组的地址，但是数组的地址也是地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(&a + 1));//4 - &a+1跳过了一个数组
	printf("%d\n", sizeof(*&a));//16 - &a是数组的地址
	printf("%d\n", sizeof(&a[0]));//4 -  &a[0]是第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4 - &a[0]+1是第二个元素的地址
	return 0;
}

//字符数组
int main() {
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr+0));//4 - arr是首元素的地址,arr+0还是首元素的地址                       
	printf("%d\n", sizeof(*arr));//1 - arr是首元素地址，*arr就是首元素
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4 虽然是数组的地址，但还是地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr+1));//4 - &arr+1是跳过整个数组后的地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr[0]+1));//4 - &arr[0]+1是第二个元素的地址
	return 0;
}

int main() {
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//随机值
	printf("%d\n", strlen(&arr + 1));//随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	 
} 