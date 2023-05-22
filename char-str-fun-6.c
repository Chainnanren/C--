//�ڴ溯��
/*strcpy
  strcat
  strcmp
  strncat
  strncmp
  
  ���������ǣ��ַ���
  ���磺strcpy���ܶ����ν��п���*/


//C���Ա�׼
/*memcpy ֻҪ���� ���ص����ڴ濽���Ϳ��ԣ�Ҳ���Կ����ص����ڴ棩
  memmove �����ص��ڴ�Ŀ���*/

//memcpy�ڴ濽��
/*����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ��
  �������������'\0'��ʱ�򲢲���ͣ����
  ���source��destination�õ����κε��ص������ƵĽ������δ�����*/
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//memcpy������ʵ��
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num) {
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (num--) {
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//memmove���� - �����ص����������
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	memmove(arr + 2, arr, 20);
	return 0;
}

//memove������ʵ��
void* my_memmove(void* dest, void* src, size_t count) {
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;
	if (dest < src) {
		//��ǰ��󿽱�
		while (count--) {
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else {
		//�Ӻ���ǰ����
		while (count--) {
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main() {
	//dest > src && dest < src+count �Ӻ���ǰ���� 
	//dest < src && dest > src-count ��ǰ���󿽱�
	char arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, sizeof(arr1));
	return 0;
}


//memcmp���� - �ڴ�Ƚ�
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,4,5,6 };
	int ret = memcmp(arr1, arr2, 9);
	printf("%d\n", ret);
}

//memset���� - �ڴ����ú���
int main() {
	char arr[] = "";
	//��һ������ - Ŀ�ĵأ��ڶ������� - ���õ��ַ����������������ֽڣ� - ���ö��ٸ��ַ�
	memset(arr, '#', 10);
	return 0;
}