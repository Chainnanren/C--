//calloc函数
/*函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0
  与函数malloc的区别在于calloc会在返回地址之前把申请的空间的每个字节初始化为全0*/
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
	//释放空间
	free(p);
	return 0;
}

//realloc函数 - 调整动态开辟空间的大小
/*reallco函数使用的注意事项：
	1.如果p指向的空间之后有足够多的内存空间可以追加，则直接追加，后返回p
	2如果p指向的空间之后没有足够的空间可以追加，则realloc函数会重新找一个新的
	内存区域，开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧
	的内存空间，最后返回新开辟的的内存空间地址
	3.得用一个新的变量来接受realloc函数的返回值*/
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
		//如果20个字节满足不了我们的使用，就是用realloc来调整动态开辟的内存
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
	//释放内存
	free(p);
	p = NULL;
	return 0;
}

int main() {
	int* p = realloc(NULL, 40);//等价于malloc函数
	return 0;
}