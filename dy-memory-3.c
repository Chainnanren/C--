//常见的动态内存错误

//1.对NULL指针的解引用操作
#include<stdio.h>
int main() {
	int* p = (int*)malloc(40);
	//万一malloc失败了，p就被赋值为NULL
	*p = 0;//err
	int i = 0;
	for (i = 0; i < 10; i++) {
		*(p + i) = i;//NULL解引用是错误的
	}
	free(p);
	p = NULL;
	return 0;
}

//2.对动态开辟内存的越界访问
int main() {
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL) {
		return 0;
	}
	else {
		int i = 0;
		//开辟的空间比i小
		for (i = 0; i < 10; i++) {
			*(p + i) = i;
		}
	}
	free(p);
	p = NULL;
	return 0;
}

//3.对非动态开辟内存使用free释放
int main() {
	int a = 10;
	int* p = &a;
	*p = 20;

	free(p);
	p = NULL;
	return 0;
}

//4.使用free释放动态开辟内存的一部分
int main() {
	int* p = (int*)malloc(40);
	if (p == NULL) {
		return 0;
	}
	else {
		int i = 0;
		for (i = 0; i < 10; i++) {
			*p++ = i;//err - free只能从开辟空间的起始位置开始释放
		}
		free(p);
		p = NULL;
	}
	return 0;
}

//5.对同一块动态内存多次释放
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

//6.动态开辟内存忘记释放（内存泄漏）
#include<windows.h>
int main() {
	while (1) {
		malloc(1);
	}
	return 0;
}