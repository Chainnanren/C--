//�ص���������һ��ͨ������ָ����õĺ���
//�ص�����һ��ͨ������ָ��ʵ��
//�ص�����һ�㲻�Ǻ�����ʵ�ַ����ã������ض��ĳ����£�����һ������
//�ص������ǵ��ú���ָ��ָ��ĺ���
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


// ʵ��һ�����������������ַ����е�k���ַ�
/*���磺
		ABCD����һ���ַ��õ�BCDA
		ABCD���������ַ��õ�CDAB*/

//������ⷨ
void left_move(char* arr, int k) {
	int i = 0;
	int len = strlen(arr);
	k %= len;
	for (i = 0; i < k; i++) {
		//��תһ���ַ�
		char tmp = *arr;
		//��ʣ�µ��ַ���ǰ�ƶ�
		int j = 0;
		for (j = 0; j < len; j++) {
			*(arr+j) = *(arr+j+1);
		}
		//���ַ��ŵ����
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

//������ת��

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
	//Ҫ�������ַ�
	reverse(arr, arr + k - 1);
	//����Ҫ�������ַ�
	reverse(arr + k, arr + len - 1);
	//��������
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


//дһ���������ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת֮����ַ���
//����һ��
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
	//Ҫ�������ַ�
	reverse(arr, arr + k - 1);
	//����Ҫ�������ַ�
	reverse(arr + k, arr + len - 1);
	//��������
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

//strcat���� - �ַ����������� - ����׷������
//��arr1����׷��һ��arr2
#include<string.h>
int main() {
	char arr1[30] = "abc";
	char arr2[] = "def";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
}
//strncat����
int main() {
	char arr1[30] = "abc";
	strncat(arr1, arr1, 3);//������������Ҫ׷�ӵ��ַ�����
}
//��������
int is_left_move(char* str1, char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	//1.��str1�ַ�����׷��һ���ַ���
		strncat(str1, str2, 6);
	//2.�ж�str2ָ����ַ����Ƿ���str1ָ����ַ������Ӵ�
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