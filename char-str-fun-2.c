//strcmp函数
/*第一个字符串大于第二个字符串，则返回大于0的数字
第一个字符串等于第二个字符串，则返回0
第一个字符串小于第二个字符串，则返回小于0的数字*/

//strcmp的实现
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


//strncpy函数 
//拷贝num个字节从元字符串到目标空间 
//如果源字符串小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个
int main() {
	char arr1[10] = "abcdef";
	char arr2[] = "hello world";
	strncpy(arr1, arr2, 4);
	return 0;
}
//helloef

//strncpy函数的实现
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

//strncat函数的实现
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


