//�����Ķ�̬�ڴ����

//1.��NULLָ��Ľ����ò���
#include<stdio.h>
int main() {
	int* p = (int*)malloc(40);
	//��һmallocʧ���ˣ�p�ͱ���ֵΪNULL
	*p = 0;//err
	int i = 0;
	for (i = 0; i < 10; i++) {
		*(p + i) = i;//NULL�������Ǵ����
	}
	free(p);
	p = NULL;
	return 0;
}

//2.�Զ�̬�����ڴ��Խ�����
int main() {
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL) {
		return 0;
	}
	else {
		int i = 0;
		//���ٵĿռ��iС
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
	}
	free(p);
	p = NULL;
	return 0;
}

//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
int main() {
	int a = 10;
	int* p = &a;
	*p = 20;

	free(p);
	p = NULL;
	return 0;
}

//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
int main() {
	int* p = (int*)malloc(40);
	if (p == NULL) {
		return 0;
	}
	else {
		int i = 0;
		for (i = 0; i < 10; i++) {
			*p++ = i;//err - freeֻ�ܴӿ��ٿռ����ʼλ�ÿ�ʼ�ͷ�
		}
		free(p);
		p = NULL;
	}
	return 0;
}

//5.��ͬһ�鶯̬�ڴ����ͷ�
int main() {
	int* p = (int*)malloc(40);
	if (p == NULL) {
		return 0;
	}
	else {
		int i = 0;
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
		free(p);
		//...
		free(p);
		p = NULL;
	}
	return 0;
}

//6.��̬�����ڴ������ͷţ��ڴ�й©��
#include<windows.h>
int main() {
	while (1) {
		malloc(1);
	}
	return 0;
}