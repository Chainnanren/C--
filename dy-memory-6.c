//�������� - �ṹ�е����һ��Ԫ��������δ֪��С������

/*����������ص�
  1.�ṹ�е����������Աǰ���������һ��������Ա
  2.sizeof���ص����ֽṹ��С����������������ڴ�
  3.�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ����
  �ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С*/

/*�������������
  1.�����ڴ��ͷ�
  2.�����ڷ����ٶ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct S {
	int n;
	int arr[0];//δ֪��С - ���������Ա - ����Ĵ�С�ǿ��Ե�����
};
int main() {
	struct S* ps=(struct S*)malloc(sizeof(struct S)+5*sizeof(int));
	ps->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++) {
		ps->arr[i] = i;
	}
	struct S* ptr = realloc(ps, 44);
	if (ptr != NULL) {
		ps = ptr;
		for (i = 5; i < 10; i++) {
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++) {
			printf("%d ", ps->arr[i]);
		}
	}
	free(ps);
	ps = NULL;
	return 0;
}




struct S {
	int n;
	int* arr;
};
int main() {
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++) {
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", ps->arr[i]);
	}

	int* ptr = realloc(ps->arr,10*sizeof(int));
	if (ptr != NULL) {
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++) {
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", ps->arr[i]);
	}
	//�ͷ��ڴ�
	free(ps->arr);
	ps->arr=NULL;
	free(ps);
	ps=NULL;
}