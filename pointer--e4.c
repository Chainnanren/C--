//指向函数指针数组的指针
int main() {
	int arr[10] = { 0 };
	int (*p)[10]= &arr;//取出数组的地址

	int (*pf)(int, int);//函数指针
	int (*pfarr[4])(int, int);//pfarr是一个数组 - 函数指针的数组
	//ppfaarr是一个指向函数指针数组的指针
	int (*(*ppfarr)[4])(int, int) = &ppfarr;
	//pfarr是一个数组指针，指针指向的数组有4个元素
	//指向的数组的每个元素的类型是一个函数指针int(*)(int,int)
	return 0;
}
//回调函数
void print(char* str) {
	printf("hehe:%s", str);
}
void test(void(*p)(char*)) {
	printf("test\n");
	p("bit");
}
int main() {
	test(print);
	return 0;
}

void Bubblesort(int arr[], int sz) {
	//......
}
//qsort - 可以排序任意类型的数据
int main() {
	//冒泡排序函数
	//冒泡排序函数只能排序整型数组
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, sz);
	return 0;
}
void menu() {
	printf("****************************\n");
	printf("*** 1.add ******** 2.sub ***\n");
	printf("*** 3.mul ******** 4.div ***\n");
	printf("****************************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int calc(int (*pa)(int,int)){
	int x = 0;
	int y = 0;
	printf("请输入两个操作数\n");
	scanf("%d%d", &x, &y);
	printf("%d\n", pa(x, y));
}
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			cale(add);
			break;
		case 2:
			cale(sub);
			break;
		case 3:
			cale(mul);
			break;
		case 4:
			cale(div);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
