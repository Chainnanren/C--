/*求字符串长度
*	strlen*/
/*长度不受限制的字符串函数
	strcpy
	strcat
	strcmp*/
/*长度受限制的字符串函数介绍
	strncpy
	strncat
	strncmp*/
/*字符串查找
	strstr
	strtok*/
/*错误信息报告
	strerror*/
/*字符操作*/
/*内存操作函数
	memcpy
	memmove
	memset
	memcmp*/
//字符串通常放在常量字符串中或者字符数组中
//字符串常量适用于那些对它不做修改的字符串函数



//strlen函数
/*1.字符串以'\0'作为结束标志，strlen函数返回的是在字符串中'\0前面出现的字符个数
2.参数指向的字符串必须以'\0'结束
3.注意函数的返回值为size_t,是无符号的*/
//size_t my_strlen(const char* str);  //size-t == unsigned int 无符号整形
// 所以strlen("abc")-strlen("abcdef")仍然是无符号数，所以大于零

//实现strlen的三种写法
/*1.计数器的方法
2.递归
3.指针-指针*/
#include<assert.h>
int my_strlen(const char* str) {
	int count=0;
	assert(str != NULL);
	while (*str != '\0') {
		count++;
		str++;
	}
	return count;
}
int main() {
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}
//递归：不创建临时变量求字符串长度


//strcpy函数 - 字符串拷贝
/*1.源字符串必须以'\0'结束
2.会将源字符串中的'\0'拷贝到目标空间
3.目标空间必须足够大，以确保能存放源字符串
4.目标空间必须可变*/

//模拟实现strcpy
char* my_strlen(char* best,const char* src) {
	assert(best != NULL);
	assert(src != NULL);
	char* ret = best;
	//拷贝src指向的字符串到贝斯特指向的空间，包含'\0'
	while (*src!='\0') {
		*best = *src;
		best++;
		src++;
	}
	*best = *src;
	//返回目的空间的起始位置
	return ret;
}
int main() {
	int arr1[] = "abcdefhig";
	int arr2[] = "bit";
	my_strlen(arr1, arr2);
	printf("%d\n", arr1);
	return 0;
}

//strcat函数 - 字符串追加
/*1.源字符串必须以'\0'结束
  2.目标空间必须有足够大，能够容纳下字符串的内容
  3.目标空间必须可修改*/
int main() {
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//模拟实现strcat
my_strcat(char* dest, const char* src) {
	char* ret = dest;
	//两种断言都对
	assert(dest!=NULL);
	assert(src);
	//1.找到目的字符串的'\0'
	while (*dest != '\0') {
		*dest++;
	}
	//2.追加
	while (*dest++ = *src++) {
		;
	}
	return ret;
}
int main() {
	char arr1[30] = "hello";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}