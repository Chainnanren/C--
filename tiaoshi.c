/* Note:Your choice is C IDE */
/*
	F5
		�������ԣ���������ֱ�ӵ�����һ���ϵ㴦
	F9
		�����ϵ��ȡ���ϵ� �ϵ����Ҫ���ã�����
		�ڳ��������λ�����öϵ㣬�����Ϳ���ʹ��
		��������Ҫ��λ������ִֹͣ�У��̶�һ����
		ִ����ȥ
	F10
		����̣�ͨ����������һ�����̣�һ�����̿���
		��һ�κ������ã�������һ��yuju
	F11
		����䣬����ÿ�ζ�ִ��һ����䣬���������
		�ݼ�����ʹ���ǵ�ִ���߼����뺯���ڲ�
		����õģ�
	CTRL + F5
		��ʼִ�в����ԣ���������ó���ֱ����������
		������ʹ�Ϳ���ֱ��ʹ��
	Shift + F11
		�������
*/
#include "stdio.h"
void main()
{
    int i=0;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<=12;i++){
    	printf("hehe\n");
    	arr[i]=0;
    }
    system("puase");
    return 0;
}


#include<stdio.h>
int main() {
	int i = 0;
	int sum = 0;
	int ret = 1;
	int n = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		int j = 0;
		ret = 1;
		for (j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}


//strcpy
#include<stdio.h>
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

#include<stdio.h>
//����Ҫ���أ���������Ϊvoid
void my_strcpy(char* best, char* src) {
	//�ַ�ָ��������ܷ���һ���ַ�
	//�����ѭ��������˵� '\0' ��û�и���best
	while (*src != '\0') {
		*best = *src;
		src++;
		best++;
	}
	//���ʱ�� *src �Ѿ����� '\0' ,����
	*best = *src;
}
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//�Ż� 1.
#include<stdio.h>
void my_strcpy(char* best, char* src) {
	/*while (*src != '\0') {
		*best++ = *src++;
	}
	*/
	//��arr1��arr2ΪNULLʱ�ͻ�������ܵ�
	if (best != NULL && src != NULL) {
		while (*best++ = *src++) {
			//���������ѭ��
			;
		}
	}
}
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
//�Ż� 2.
#include<stdio.h>
#include<assert.h>//assert-����
void my_strcpy(char* dest, char* src) {
	//��arr1��arr2ΪNULLʱ�ͻ�������ܵ�
	assert(dest != NULL);//����
	assert(src != NULL);
	while (*dest++ = *src++) {
		//���������ѭ��
		;
	}
}
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, NULL);
	printf("%s\n", arr1);
	return 0;
} 

//�Ż� 3.
#include<stdio.h>
#include<assert.h>//assert-����
//const��������Ϊ�����޸ĵĳ���
void my_strcpy(char* dest, const char* src) {
	//��arr1��arr2ΪNULLʱ�ͻ�������ܵ�
	assert(dest != NULL);//����
	assert(src != NULL);
	while (*dest++ = *src++) {
		//���������ѭ��
		;
	}
}
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	my_strcpy(arr1, NULL);
	printf("%s\n", arr1);
	return 0;
}

//const���÷�
int main() {
	const int num = 0;
	const int* p = &num;
	/*const ����ָ�������*���ʱ�����ε���*p��Ҳ
	����˵������ͨ��p���ı�*p(num)��ֵ*/
	*p = 20;
	printf("/d\n", num);
	return 0;
}


int main() {
	const int num = 0;
	int* const p = &num;
	/*const ����ָ�������*�ұ�ʱ�����ε���ָ�����p��Ҳ
	����˵��p���ܱ��ı�*/
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;
}


//�Ż� 4.
#include<stdio.h>
#include<assert.h>//assert-����
//const��������Ϊ�����޸ĵĳ���
char* my_strcpy(char* dest, const char* src) {
	//��arr1��arr2ΪNULLʱ�ͻ�������ܵ�
	char* ret = dest;
	assert(dest != NULL);//����
	assert(src != NULL);
	/*��srcָ����ַ���������destָ��Ŀռ䣬����
	'\0'�ַ�*/
	while (*dest++ = *src++) {
		//���������ѭ��
		;
	}
	return ret;
}
int main() {
	//strcpy - �ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	//��ʽ����
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}

int my_style(const char* str) {
	int count = 0;
	assert(str 1 = NULL);
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
int main() {
	char arr[] = "abcdef";;
	int len = my_style(arr);
	printf("d\n", len);

	return 0;
}

