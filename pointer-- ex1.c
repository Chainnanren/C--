int main() {
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//7
	printf("%d\n", sizeof(arr+0));//4 - arr+0����Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));//1 - *arr����Ԫ�أ�sizeof(*arr)������Ԫ�صĴ�С
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4 &arr��Ȼ������ĵ�ַ����Ҳ�ǵ�ַ
	printf("%d\n", sizeof(&arr+1));//4 
	printf("%d\n", sizeof(&arr[0]+1));//4 - &arr[0 ]+1�ǵڶ���Ԫ�صĵ�ַ
	return 0;

}

int main() {
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));//6
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	//&arr ����ĵ�ַ�����������ָ���� char(*p)[7] = &arr;strlen�������������� const char*
	printf("%d\n", strlen(&arr));//6 
	printf("%d\n", strlen(&arr + 1)) ;//���ֵ
	printf("%d\n", strlen(&arr[0] + 1));//5
	return 0;
}

int main() {
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8 - ����ָ�����p�Ĵ�С
	printf("%d\n", sizeof(p + 1));//4 - �õ������ַ�b�ĵ�ַ
	printf("%d\n", sizeof(*p));//1 - *p�����ַ����ĵ�һ���ַ�'a'
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
	printf("%d\n", strlen(&p));//���ֵ
	printf("%d\n", strlen(&p + 1));//���ֵ
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}

int main() {
	int  a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16

	//a[0]�ǵ�һ�е�����������������ʱ����Ԫ�صĵ�ַ
	//���԰�a[0]+1���ǵ�һ�еڶ���Ԫ�صĵ�ַ - ��ַ��С��4/8���ֽ�
	printf("%d\n", sizeof(a[0]+1));//4 
	printf("%d\n", sizeof(*(a[0]+1)));//4 - *(a[0]+1)�ǵ�һ�еڶ���Ԫ��

	//a�Ƕ�ά�������������û��sizeof(������)��Ҳû��&(������)������a����Ԫ�ص�ַ
	//����ά�������Ԫ���ǵ�һ�� ��a+1���ǵڶ��еĵ�ַ
	printf("%d\n", sizeof(a+1));//4
	printf("%d\n", sizeof(*(a+1)));//16 - ����ڶ��еĴ�С����λ���ֽ�
	printf("%d\n", sizeof(&a[0]+1));//4 - �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0]+1)));//16 - ����ڶ��еĴ�С
	printf("%d\n", sizeof(*a));//16 - a����Ԫ�ص�ַ - ��һ�еĵ�ַ
	printf("%d\n", sizeof(a[3]));//16 
}

/*�ܽ᣺
�����������壺
			1.sizeof(������)���������������ʾ�������飬���������������Ĵ�С
			2.&���������������������ʾ�������飬ȡ��������������ĵ�ַ
			3.����֮�����е�����������ʾ��Ԫ�صĵ�ַ
			4.strlen����ֻ�����ַ�����Ĵ�С*/