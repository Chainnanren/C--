//结构体传参 
#include<stdio.h>
struct S {
	int a;
	char c;
	double d;
};
void Init(struct S* ps) {
	ps->a = 100;
	ps->c = 'w';
	ps->d = 3.14;
}
//传值
void Print1(struct S tmp) {
	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
}
//传址
void Print2(const struct S* ps) {
	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
}
int main() {
	struct S s;
	Init(&s);
	Print1(s);
	Print2(&s);
	return 0;
}
//结论：
//	结构体传参的时候，要传结构体的地址

/*原因：
	函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销
	如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，所以
	会导致性能的下降*/