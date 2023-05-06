// char* my_strcpy(char* dest, const char* src);
//写一个函数指针pf，能够指向my_strcpy
char* (*pf)(char*, const char*);
//写一个函数指针数组pfarr，能够存放4个my_strcpy函数的地址
char* (*pfarr[4])(char*, const char*);
void menu() {
	printf("******************\n");
	printf("** 1.add   2.sub**\n");
	printf(" **3.mul   4.div **\n");
	printf("***** 0. exit ****\n");
	printf("******************\n"); 
}
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int main() {
	int input=0;
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
			printf("%d\n",Add(x, y));
			break;
		case 2:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("请输入两个操作数\n");
			scanf("%d%d", &x, &y);
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
	}
	} while (input);
	return 0;
}

int main() {

	int input = 0;
	int x = 0;
	int y = 0;
	int (*pfarr[5])(int, int);
	do {
		menu();
		printf("请选择");
		scanf("%d", &input);
	} while (input);
	}


int add(int x, int y) {
	return x + y;
}
int main() {
	//指针数组
	int* arr[10];
	//数组指针
	int* (*pa)[10] = &arr;
	//函数指针
	int (*padd)(int, int) = add;
	int sum = (*padd)(1, 2);
	printf("%d\n", sum);
	//函数指针的数组
	int (*parr[4])(int, int);
		//指向函数指针数组的指针
}

//回调函数 
void bubble_sort(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz-1; i++) {
		int j = 0;
		for (j = 0; j < sz-1-i; j++) {
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
		}
	}
}
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = 0;
	int i = 0;
	bubble_sort(arr, sz);
	sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		printf("%d\n", arr[i]);
	}
}


void bubble_sort(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
		}
	}
}
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = 0;
	int i = 0;
	bubble_sort(arr, sz);
	sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		printf("%d\n", arr[i]);
	}
}
/*冒泡排序只能排特定类型的数组，当遇到别的类型的数字
  比如（结构体时）时该怎么排序呢？*/
struct stu {
	char name[20];
	int age;
};
int main() {
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	return 0;
}


//qsort函数 - 库函数 - 排序
// qsort 的头文件是<stdilb.h>
//qsort(目标数组的起始位置，数组元素的个数，数组内每个元素的长度，函数)
/*当第一个数大于第二个数 返回小于0的数字
  当第一个数等于第二个数 返回0
  当第一个数小于第二个数 返回小于0的数字*/
void qsort(void* base,
	size_t num,
	size_t width,
	int(*cmp)(const void* e1, const void* e2)
);
int cmp_int(const void* e1, const void* e2) {
	//比较两个整形值
	return *(int*)e1 - *(int*)e2;
}
//void* 类型的指针 可以接受任意类型的地址
//void* 类型的指针 不能进行解引用操作
//void* 类型 的指针 不能进行+-整数的操作
int main() {
	int a = 10;
	int* pa = &a;
	char ch = 'w';
	void* p = &a;
	//*p = 0;
	//p++；  
	p = &ch;
	return 0;
}

int cmp_int(const void* e1, const void* e2) {
	//比较两个整形值
	return *(int*)e1 - *(int*)e2;
}
void test1() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = 0;
	int i = 0;
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		printf("%d\n", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2) {
	/*if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return return -1;*/
		
	return ((int)(*(float*)e1 - *(float*)e2));
}
void test2() {
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int j = 0;
	for (j = 0; j < sz; j++) {
		printf("%f ", f[j]);
	}
}


int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
};
int cmp_stu_by_name(const void* e1, const void* e2) {
	//比较名字就是比较字符串
	//字符串比较不能直接用 > < == 来比较，应该用strcmp函数
	return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
}
struct stu {
	char name[20];
	int age;
};
void test3() {
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main() {
	test1();
	test2();
	test3();
	return 0;
}


