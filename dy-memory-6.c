//柔性数组 - 结构中的最后一个元素允许是未知大小的数组

/*柔性数组的特点
  1.结构中的柔性数组成员前面必须至少一个其他成员
  2.sizeof返回的这种结构大小不包括柔性数组的内存
  3.包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的
  内存应该大于结构的大小，以适应柔性数组的预期大小*/

/*柔性数组的优势
  1.方便内存释放
  2.有利于访问速度*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct S {
	int n;
	int arr[0];//未知大小 - 柔性数组成员 - 数组的大小是可以调整的
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
	//释放内存
	free(ps->arr);
	ps->arr=NULL;
	free(ps);
	ps=NULL;
}