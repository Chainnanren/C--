//strtok函数
/*char* strtok(char* str,const char* sep)
1.sep参数是个字符串，定义了用作分隔符的字符集合
2.第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
3.strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针
（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改）
4.strrok函数的第一个参数不为NULL，函数将找到str第一个标记，strtok函数将保存它在字符串中的位置
5.strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记
6.如果字符串中不存在更多的标记，则返回NULL指针*/
#include<string.h>
int main() {
	char arr[] = "zpw@bitdu.tech";
	char* p = "@.";
	char* ret = strtok(arr, p);
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);
	return 0;
}

#include<string.h>
int main() {
	char arr[] = "zpw@bitdu.tech";
	char* p = "@.";
	char* ret =NULL;
	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p)) {
		printf("%s\n", ret);
	}
	return 0;
}

//streror函数 - 错误报告函数
//返回错误码，所对应的错误信息
#include<errno.h>
int main() {
	//错误码，每个错误码都有对应的错误信息
	//1 - No error
	//2 - Operation not permitted
	//3 - No such file or directory
	//...
	//errno是一个全局的错误码的变量
	//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
	char* str = strerror(errno);
	printf("%s\n", str);
	return 0;
}

#include<errno.h>
#include<stdio.h>
int main() {
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
	}
	else {
		printf("open file success\n");
	}
	return 0;
}
