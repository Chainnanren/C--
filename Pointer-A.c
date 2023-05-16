//回调函数就是一个通过函数指针调用的函数
//回调函数一般通过函数指针实现
//回调函数一般不是函数的实现方调用，而是特定的场景下，由另一方调用
//回调函数是调用函数指针指向的函数
int main() {
	int a[5] = { 5,4,3,2,1 };
	int* ptr = (int*)(&a + 1);
	printf ("%d,%d\n", *(a + 1), *(ptr - 1));
	return 0;
}
//4 1 

int main() {
	int aa[2][5] = { { 10,9,8,7,6, },{5, 4, 3, 2, 1} };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2=(int*)(*(aa + 1));
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//1 6


// 实现一个函数，可以左旋字符串中的k个字符
/*例如：
		ABCD左旋一个字符得到BCDA
		ABCD左旋两个字符得到CDAB*/

//暴力求解法
void left_move(char* arr, int k) {
	int i = 0;
	int len = strlen(arr);
	k %= len;
	for (i = 0; i < k; i++) {
		//旋转一个字符
		char tmp = *arr;
		//将剩下的字符向前移动
		int j = 0;
		for (j = 0; j < len; j++) {
			*(arr+j) = *(arr+j+1);
		}
		//将字符放到最后
		*(arr+len-1) = tmp;
	}

}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}

//三部翻转法

#include<assert.h>
void reverse(char* left, char* right) {
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k) {
	int len = strlen(arr);
	k %= len;
	//要左旋的字符
	reverse(arr, arr + k - 1);
	//不需要左旋的字符
	reverse(arr + k, arr + len - 1);
	//整体逆序
	reverse(arr, arr + len - 1);
}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}


//写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串
//方法一：
#include<assert.h>
void reverse(char* left, char* right) {
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr, int k) {
	int len = strlen(arr);
	k %= len;
	//要左旋的字符
	reverse(arr, arr + k - 1);
	//不需要左旋的字符
	reverse(arr + k, arr + len - 1);
	//整体逆序
	reverse(arr, arr + len - 1);
}
int is_left_move(char* s1, char* s2) {
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++) {
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0) {
			return 1;
		}
		return 0;
	}

}
int main() {
	char arr1[] = "ABCDEF";
	char arr2[] = "CDEFAB";
	int k = 0;
	scanf("%d", &k);
	int ret=is_left_move(arr1, arr2);
	if (ret = 1)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}

//strcat函数 - 字符串操作函数 - 不能追加自身
//在arr1后面追加一个arr2
#include<string.h>
int main() {
	char arr1[30] = "abc";
	char arr2[] = "def";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
}
//strncat函数
int main() {
	char arr1[30] = "abc";
	strncat(arr1, arr1, 3);//第三个参数是要追加的字符长度
}
//方法二：
int is_left_move(char* str1, char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	//1.在str1字符串中追加一个字符串
		strncat(str1, str2, 6);
	//2.判断str2指向的字符串是否是str1指向的字符串的子串
		char* ret = strstr(str1, str2);
		if (ret == NULL) {
			return 0;
		}
		else {
			return 1;
		}
	}
int main() {
		char arr1[30] = "abcdef";
		char arr2[] = "cdefab";
		int ret = is_left_move(arr1, arr2);
		if (ret == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		return 0;

	}