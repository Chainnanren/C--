// char* my_strcpy(char* dest, const char* src);
//дһ������ָ��pf���ܹ�ָ��my_strcpy
char* (*pf)(char*, const char*);
//дһ������ָ������pfarr���ܹ����4��my_strcpy�����ĵ�ַ
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
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input) {
		case 1: 
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n",Add(x, y));
			break;
		case 2:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
	} while (input);
	}


int add(int x, int y) {
	return x + y;
}
int main() {
	//ָ������
	int* arr[10];
	//����ָ��
	int* (*pa)[10] = &arr;
	//����ָ��
	int (*padd)(int, int) = add;
	int sum = (*padd)(1, 2);
	printf("%d\n", sum);
	//����ָ�������
	int (*parr[4])(int, int);
		//ָ����ָ�������ָ��
}

//�ص����� 
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
/*ð������ֻ�����ض����͵����飬������������͵�����
  ���磨�ṹ��ʱ��ʱ����ô�����أ�*/
struct stu {
	char name[20];
	int age;
};
int main() {
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	return 0;
}


//qsort���� - �⺯�� - ����
// qsort ��ͷ�ļ���<stdilb.h>
//qsort(Ŀ���������ʼλ�ã�����Ԫ�صĸ�����������ÿ��Ԫ�صĳ��ȣ�����)
/*����һ�������ڵڶ����� ����С��0������
  ����һ�������ڵڶ����� ����0
  ����һ����С�ڵڶ����� ����С��0������*/
void qsort(void* base,
	size_t num,
	size_t width,
	int(*cmp)(const void* e1, const void* e2)
);
int cmp_int(const void* e1, const void* e2) {
	//�Ƚ���������ֵ
	return *(int*)e1 - *(int*)e2;
}
//void* ���͵�ָ�� ���Խ����������͵ĵ�ַ
//void* ���͵�ָ�� ���ܽ��н����ò���
//void* ���� ��ָ�� ���ܽ���+-�����Ĳ���
int main() {
	int a = 10;
	int* pa = &a;
	char ch = 'w';
	void* p = &a;
	//*p = 0;
	//p++��  
	p = &ch;
	return 0;
}

int cmp_int(const void* e1, const void* e2) {
	//�Ƚ���������ֵ
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
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ���� > < == ���Ƚϣ�Ӧ����strcmp����
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


