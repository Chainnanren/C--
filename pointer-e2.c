//ָ�����2
//���������ָ�����
#include<stdio.h> 
//һά���鴫��
void test(int arr[])
{}
void test(int arr[10])
{}
void test(int* arr)
{}
void test2(int* arr[20])
{}
void test2(int** arr)
{}
int main() {
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test2(arr2);
	return 0;
}
//��ά���鴫��
void test(int arr[3][5])
{}
void test(int arr[3][5])//�п���ʡ�ԣ��в���ʡ��
{}
void test(int (*arr)[5])
{}
void test()
{}
int main() {
	int arr[3][5] = { 0 };
	test(arr);//��ά���鴫��
	test2(arr);
	return 0;
} 

//һ��ָ�봫��
void print(int* p, int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d\n", *(p + i));
	}
}
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//һ��ָ��p����������
	print(p, sz);
}
void test1(int* p)
{}
void test2(char* p)
{}
int main() {
	int a = 10;
	int* p1 = &a;
	test1(&a);
	test1(p1);
	char ch = 'w';
	char* pc = &ch;
	test(&ch);
	teest2(pc);
	return 0;
}
//����ָ�봫��
void test(int** ptr) {

	printf("%d\n", **ptr);
}
int main() {
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);
	test(&p);
}

void test(int** p)
{}
int main() {
	int* ptr;
	int** pp = &ptr;
	test(&ptr);
	test(pp);
	int* arr[10];
	test(arr);//ָ������Ҳ����
	return 0;
}

//����ָ�� - ָ�������ָ��
//����ָ�� - ָ�����ĵ�ָ��
int add(int x, int y) {
	int z = 0;
	z = x + y;
	return z;
}
int main() {
	int a = 10;
	int b = 20;
	printf("%d\n", add(a, b));
	//&������ �� ������ ���Ǻ����ĵ�ַ
	printf("%p\n", &add);
	printf("%p\n", add);
	int (*pa)(int, int) = add;
	return 0;
}

print(char* str) {
	printf("%s\n", str);
}
int main(){
	void (*p)(char*) = printf;
	(*p)("hello world");
	return 0;
}