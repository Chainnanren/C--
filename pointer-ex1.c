int main() {
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7
	printf("%d\n", sizeof(arr+0));//4 - arr+0是首元素地址
	printf("%d\n", sizeof(*arr));//1 - *arr是首元素，sizeof(*arr)计算首元素的大小
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4 &arr虽然是数组的地址，但也是地址
	printf("%d\n", sizeof(&arr+1));//4 
	printf("%d\n", sizeof(&arr[0]+1));//4 - &arr[0 ]+1是第二个元素的地址
	return 0;

}

int main() {
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	//&arr 数组的地址，存放在数组指针中 char(*p)[7] = &arr;strlen函数参数类型是 const char*
	printf("%d\n", strlen(&arr));//6 
	printf("%d\n", strlen(&arr + 1)) ;//随机值
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}

int main() {
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8 - 计算指针变量p的大小
	printf("%d\n", sizeof(p + 1));//4 - 得到的是字符b的地址
	printf("%d\n", sizeof(*p));//1 - *p就是字符串的第一个字符'a'
	//int arr[10];   arr[0] == *(arr+0)   p[0] == *(p+0) == 'a'
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4
	printf("%d\n", sizeof(&p[0] + 1));//4
	return 0;
}

int main() {
	char* p = "abcdef";
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//随机值
	printf("%d\n", strlen(&p + 1));//随机值
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}

int main() {
	int  a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16

	//a[0]是第一行的数组名，数组名此时是首元素的地址
	//所以啊a[0]+1就是第一行第二个元素的地址 - 地址大小是4/8个字节
	printf("%d\n", sizeof(a[0]+1));//4 
	printf("%d\n", sizeof(*(a[0]+1)));//4 - *(a[0]+1)是第一行第二个元素

	//a是二维数组的数组名，没有sizeof(数组名)，也没有&(数组名)，所以a是首元素地址
	//而二维数组的首元素是第一行 ，a+1就是第二行的地址
	printf("%d\n", sizeof(a+1));//4
	printf("%d\n", sizeof(*(a+1)));//16 - 计算第二行的大小，单位是字节
	printf("%d\n", sizeof(&a[0]+1));//4 - 第二行的地址
	printf("%d\n", sizeof(*(&a[0]+1)));//16 - 计算第二行的大小
	printf("%d\n", sizeof(*a));//16 - a是首元素地址 - 第一行的地址
	printf("%d\n", sizeof(a[3]));//16 
}

/*总结：
数组名的意义：
			1.sizeof(数组名)，区里的数组名表示整个数组，计算的是整个数组的大小
			2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
			3.除此之外所有的数组名都表示首元素的地址
			4.strlen函数只能求字符数组的大小*/