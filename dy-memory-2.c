//calloc����
/*�����Ĺ�����Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0
  �뺯��malloc����������calloc���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int main() {
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL) {
		printf("%s\n", strerror(errno));
	}
	else {
		int i = 0;
		for (i = 0; i < 10; i++) {
			printf("%d\n", *(p + i));
		}
	}
	//�ͷſռ�
	free(p);
	return 0;
}

//realloc���� - ������̬���ٿռ�Ĵ�С
/*reallco����ʹ�õ�ע�����
	1.���pָ��Ŀռ�֮�����㹻����ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	2���pָ��Ŀռ�֮��û���㹻�Ŀռ����׷�ӣ���realloc������������һ���µ�
	�ڴ����򣬿���һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷž�
	���ڴ�ռ䣬��󷵻��¿��ٵĵ��ڴ�ռ��ַ
	3.����һ���µı���������realloc�����ķ���ֵ*/
int main() {
	int* p = (int*)malloc(20);
	if (p == NULL) {
		printf("%s\n", strerror(errno));
	}
	else {
		int i = 0;
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
		//���20���ֽ����㲻�����ǵ�ʹ�ã�������realloc��������̬���ٵ��ڴ�
		int* ptr = realloc(p, 40);
		if (ptr != NULL) {
			p = ptr;
			int i = 0;
			for (i = 5; i < 10; i++) {
				*(p + i) = i;
			}
			for (i = 0; i < 10; i++) {
				printf("%d\n", *(p + i));
			}
		}
	}
	//�ͷ��ڴ�
	free(p);
	p = NULL;
	return 0;
}

int main() {
	int* p = realloc(NULL, 40);//�ȼ���malloc����
	return 0;
}