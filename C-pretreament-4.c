// # 和 ##

// # - 把宏的参数插入到字符串中
#define PRINT(X) printf("the value of"#X"is %d\n",X)//把X所对应的内容变成所对应的字符串
int main() {
	int a = 10;
	int b = 20;
	PRINT(a);// #X变成"a"
	PRINT(b);// #X变成"b"
	return 0;
}

// ## - 可以把位于它两边的符号合成一个符号。它允许宏定义从分离的文本片段创建标识符
#define CAT(X,Y) X##Y
int main() {
	int Class84 = 2019;
	printf("%d\n", CAT(Class, 84));
	return 0;
}
//注：这样的连接必须产生一个合法的标识符。否则其结果就是未定义
