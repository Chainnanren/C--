//strcmp����
/*��һ���ַ������ڵڶ����ַ������򷵻ش���0������
��һ���ַ������ڵڶ����ַ������򷵻�0
��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������*/

//strcmp��ʵ��
my_strcmp(char* arr1, char* arr2) {
	assert(*arr1 && *arr2);
	while (arr1 == arr2) {
		if (*arr1 == '\0') {
			return 0;
		}
		arr1++;
		arr2++;
	}
	if (arr1 > arr2) {
		return 1;
	}
	else
		return -1;
}
int main() {
	char str1[] = "abcdef";
	char str2[] = "bcdefg";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}

_strcmp(char* arr1, char* arr2) {
	assert(*arr1 && *arr2);
	while (arr1 == arr2) {
		if (*arr1 == '\0') {
			return 0;
		}
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}
int main() {
	char str1[] = "abcdef";
	char str2[] = "bcdefg";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}


//strncpy���� 
//����num���ֽڴ�Ԫ�ַ�����Ŀ��ռ� 
//���Դ�ַ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��0��ֱ��num��
int main() {
	char arr1[10] = "abcdef";
	char arr2[] = "hello world";
	strncpy(arr1, arr2, 4);
	return 0;
}
//helloef

//strncpy������ʵ��
char* my_strncpy(char* dest, const char* source, size_t count) {
	char* start = dest;
	while (count && (*dest++ == *source++)) {
		count--;
	}
	if (count)
		while (--count)
			*dest++ = '\0';
	return start;
}

//strncat������ʵ��
char* my_strncat(char* front, const char* back, size_t count) {
	char* start = front;
	while (*front++)
		;
	front--;
	while (count--)
		if (!(*front++ = *back++))
			return start;
	*front = '\0';
	return start;
}


