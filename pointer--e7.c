//ָ���������������

//��������
int main() {
	//����������Ԫ�ص�ַ
	/*��������
	* 1. sizeof - ��������ʾ��������
	* 2. &������ - ��������ʾ��������*/
	//һά����
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16 - ���������ܴ�С
	printf("%d\n", sizeof(a + 0));//4 - �����������ʾ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));// 4 - ��������ʾ��Ԫ�ص�ַ��*a������Ԫ��
	printf("%d\n", sizeof(a + 1));//4 - a+1�ǵڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4 - &aȡ����������ĵ�ַ����������ĵ�ַҲ�ǵ�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n", sizeof(&a + 1));//4 - &a+1������һ������
	printf("%d\n", sizeof(*&a));//16 - &a������ĵ�ַ
	printf("%d\n", sizeof(&a[0]));//4 -  &a[0]�ǵ�һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4 - &a[0]+1�ǵڶ���Ԫ�صĵ�ַ
	return 0;
}

//�ַ�����
int main() {
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr+0));//4 - arr����Ԫ�صĵ�ַ,arr+0������Ԫ�صĵ�ַ                       
	printf("%d\n", sizeof(*arr));//1 - arr����Ԫ�ص�ַ��*arr������Ԫ��
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4 ��Ȼ������ĵ�ַ�������ǵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n", sizeof(&arr+1));//4 - &arr+1���������������ĵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n", sizeof(&arr[0]+1));//4 - &arr[0]+1�ǵڶ���Ԫ�صĵ�ַ
	return 0;
}

int main() {
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//���ֵ
	printf("%d\n", strlen(arr + 0));//���ֵ
	printf("%d\n", strlen(*arr));//error
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//���ֵ
	printf("%d\n", strlen(&arr + 1));//���ֵ-6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1
	 
} 