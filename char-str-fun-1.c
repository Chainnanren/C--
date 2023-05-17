/*���ַ�������
*	strlen*/
/*���Ȳ������Ƶ��ַ�������
	strcpy
	strcat
	strcmp*/
/*���������Ƶ��ַ�����������
	strncpy
	strncat
	strncmp*/
/*�ַ�������
	strstr
	strtok*/
/*������Ϣ����
	strerror*/
/*�ַ�����*/
/*�ڴ��������
	memcpy
	memmove
	memset
	memcmp*/
//�ַ���ͨ�����ڳ����ַ����л����ַ�������
//�ַ���������������Щ���������޸ĵ��ַ�������



//strlen����
/*1.�ַ�����'\0'��Ϊ������־��strlen�������ص������ַ�����'\0ǰ����ֵ��ַ�����
2.����ָ����ַ���������'\0'����
3.ע�⺯���ķ���ֵΪsize_t,���޷��ŵ�*/
//size_t my_strlen(const char* str);  //size-t == unsigned int �޷�������
// ����strlen("abc")-strlen("abcdef")��Ȼ���޷����������Դ�����

//ʵ��strlen������д��
/*1.�������ķ���
2.�ݹ�
3.ָ��-ָ��*/
#include<assert.h>
int my_strlen(const char* str) {
	int count=0;
	assert(str != NULL);
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
int main() {
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}
//�ݹ飺��������ʱ�������ַ�������


//strcpy���� - �ַ�������
/*1.Դ�ַ���������'\0'����
2.�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
3.Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
4.Ŀ��ռ����ɱ�*/

//ģ��ʵ��strcpy
char* my_strlen(char* best,const char* src) {
	assert(best != NULL);
	assert(src != NULL);
	char* ret = best;
	//����srcָ����ַ�������˹��ָ��Ŀռ䣬����'\0'
	while (*src!='\0') {
		*best = *src;
		best++;
		src++;
	}
	*best = *src;
	//����Ŀ�Ŀռ����ʼλ��
	return ret;
}
int main() {
	int arr1[] = "abcdefhig";
	int arr2[] = "bit";
	my_strlen(arr1, arr2);
	printf("%d\n", arr1);
	return 0;
}

//strcat���� - �ַ���׷��
/*1.Դ�ַ���������'\0'����
  2.Ŀ��ռ�������㹻���ܹ��������ַ���������
  3.Ŀ��ռ������޸�*/
int main() {
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//ģ��ʵ��strcat
my_strcat(char* dest, const char* src) {
	char* ret = dest;
	//���ֶ��Զ���
	assert(dest!=NULL);
	assert(src);
	//1.�ҵ�Ŀ���ַ�����'\0'
	while (*dest != '\0') {
		*dest++;
	}
	//2.׷��
	while (*dest++ = *src++) {
		;
	}
	return ret;
}
int main() {
	char arr1[30] = "hello";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}