//指针进阶3
//代码1
(*(void(*)())0)();
/*把0强制转换成：void(*)() - 函数指针类型，调用0地址处的
该函数*/
//代码2
//signal是一个函数声明
/*signal函数的参数有两个，第一个是int。
第二个是函数指针，该函数指针指向的函数的参数是int，返回
类型是void*/
//signal函数的返回类型也是一个函数指针：该函数指针指向的
// 函数的参数是int，返回类型是void
void(*signal(int, void(*)(int)))(int);
//简化
typedef void(*pfun_t)(int);
pfun_t signal(int , pfun_t);

int add(int x, int y) {
	int z = 0;
	z = x + y;
	return z;
}
int main() {
	int a = 10;
	int b = 20;
	int(*pa)(int, int) = add;
	printf("%d\n", pa(2, 3));
	printf("%d\n", add(2, 3));
	printf("%d\n", (*pa)(2, 3)); 
	return 0;
} 

//函数指针数组
int Add(int x, int y) {
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
int main() {
	int* arr[5];
	//需要一个数组，这个数组可以存放4个函数的地址 - 函数指针的数组
	int (*pa)(int, int) = Add;//sub/mul/div
	int (*pa[4])(int, int) = {Add,sub,mul.div};//函数指针的数组
	int i = 0;
	for (i = 0; i < 4; i++) {
		printf("%d\n", pa[i](2, 3));
	}
	return 0;
}
my_strcpy(char* dest, const char* src) {
//写一个函数指针pf，能够指向my_strcpy
//写一个函数指针数组pfArr，能够存放4个my_strcpy函数的地址
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
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", add(x, y));
			break;
		case 2:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", div(x, y));
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
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	//pfarr是一个函数指针数组 - 转移表 
	int(*pfaarr[5])(int, int) = { 0,add,sub,mul,div };
	do {

		menu();
		printf("请选择\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4) {
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			int ret = pfarr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0) {
			printf("退出\n");
		}
		else
			printf("选择错误\n");

	} while (input);
}