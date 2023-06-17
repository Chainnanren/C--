//带副作用的宏参数
	/*当宏参数在宏的定义中出现过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候就可能
	出现危险，导致不可预测的后果。副作用就是表达式求值的时候出现的永久性效果。例如：
		x+1;  不带副作用
		x++;  带有副作用*/
#include<stdio.h>
#define MAX(X,Y) (X)>(Y)?(X):(Y)
int main() {
	int a = 10;
	int b = 11;
	int max = MAX(a, b);
	printf("%d\n", max);
	return 0;
}

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int main() {
	int a = 10;
	int b = 11;
	int max = MAX(a++, b++);//b++先使用再加1 10>11 所以b再++ 变成13
	printf("%d\n", max);//12
	printf("%d\n", a);//11
	printf("%d\n", b);//13
	return 0;
}


//宏和函数的对比

//函数
int Max(int x, int y) {
	return (x > y ? x : y);
}

//宏
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int main() {
	int a = 10;
	int b = 10;
	int max = Max(a, b);
	printf("max=%d\n", max);
	max = MAX(a, b);
	printf("max=%d\n", max);
	return 0;
}

/*宏通常被应用于执行简单的运算
	那为什么不用函数来完成任务？
		1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。所以宏
		比函数在程序的规模和速度方面更胜一筹
		2.更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反
		之这个宏可以适用于整形、长整型、浮点型等。宏与类型是无关的*/

/*当然和宏相对于函数也有劣势的地方
	1.每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度
	2.宏是没法调试的
	3.宏由于类型无关，也就不够严谨
	4.宏可能会带来运算符优先级的问题，导致程序容易出错*/ 

//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到
#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
int main() {
	int* p = MALLOC(10, int);
	return 0;
}

/*命名约定
	一般来讲函数的宏的使用语法很相似。所以语言本身没法帮我们区分二者。那我们平时的一个习惯：
		把宏名全部大写 函数名不要全部大写*/

// #undef - 这条指令用于移除一个宏定义

#define MAX 100
int main() {
	printf("%d\n", MAX);
	#undef MAX
	return 0;
}