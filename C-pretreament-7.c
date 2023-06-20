//offset

#include<stdio.h>
#include<stddef.h>
struct S {
	char c1;
	int a;
	char c2;
};
int main() {
	printf("%d\n", offsetof(struct S, c1));
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", offsetof(struct S, c2));
	return 0;
}

//offsetof函数的模拟实现
struct S {
	char c1;
	int a;
	char c2;
};
#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
int main() {
	printf("%d\n", OFFSETOF(struct S, c1));
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, c2));
	return 0;
}