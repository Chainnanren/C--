//ָ�����

//1.�ַ�ָ��
#include<stdio.h>
int main() {
	char* p = "abedef";//"abcdef"��һ�������ַ���
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
//���Ϊhaha

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
//���Ϊhehe

//ָ������ ������,�������ָ���
int main() {
	int arr[10] = { 0 };//��������
	char ch[5] = { 0 };//�ַ�����
	int* parr[40];//�������ָ������� - ָ������
	char* pch[5];//����ַ�ָ������� - ָ������
	return 0;
}
//ָ��������÷�
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

//����ָ����÷�
int main() {
	int* p = NULL;//p������ָ�� - ָ�����ε�ָ�� - ���Դ�����εĵ�ַ
	char* pc = NULL;//pc���ַ�ָ�� - ָ���Ը���ָ�� - ���Դ���ַ��ĵ�ַ
	//����ָ�� - ָ�������ָ�� - �������ĵ�ַ
	int arr[10] = { 0 };
	//arr - ��Ԫ�ص�ַ
	//&arr[0] - ��Ԫ�صĵ�ַ
	//&arr - ����ĵ�ַ
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;//����ĵ�ַҪ������
	//�����p��������ָ��
	return 0;
}

int main() {
	char* arr[5];
	char* (*pa)[5] = &arr;
	//*˵��pa��ָ��
	//paָ������������Ԫ��
	//ָ�����������
	//paָ��������Ԫ��������char*
	return 0;
}

int main() {
	char* arr[5];
	char* (*pa)[5] = &arr;

	int arr2[10] = { 0 };
	int(*pa2)[10] = &arr2;
	return 0;
}

//����ָ���ʹ��
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

	int arr[5];//arr��һ��5��Ԫ�ص���������
	int* parr1[10];//parr1��һ�����飬������10��Ԫ��
	//ÿ��Ԫ�ص�������int* parr1��ָ������
	int(*parr2)[10];//parr2��һ��ָ�룬��ָ��ָ����һ��Ԫ��
	//������110��Ԫ�أ�ÿ��Ԫ��������int
	int(*(parr3[10]))[5];
	//parr3��һ�����飬��������10��Ԫ�أ�ÿ��Ԫ����һ������ָ��
	//������ָ��ָ���������5��Ԫ��,ÿ��Ԫ����int
