//内存函数
/*strcpy
  strcat
  strcmp
  strncat
  strncmp
  
  操作对象是：字符串
  比如：strcpy不能对整形进行拷贝*/


//C语言标准
/*memcpy 只要处理 不重叠的内存拷贝就可以（也可以拷贝重叠的内存）
  memmove 处理重叠内存的拷贝*/

//memcpy内存拷贝
/*函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
  这个函数在遇到'\0'的时候并不会停下来
  如果source和destination得到有任何的重叠，复制的结果都是未定义的*/
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//memcpy函数的实现
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num) {
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (num--) {
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	return 0;
}

//memmove函数 - 处理重叠拷贝的情况
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	memmove(arr + 2, arr, 20);
	return 0;
}

//memove函数的实现
void* my_memmove(void* dest, void* src, size_t count) {
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;
	if (dest < src) {
		//从前向后拷贝
		while (count--) {
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else {
		//从后向前拷贝
		while (count--) {
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main() {
	//dest > src && dest < src+count 从后向前拷贝 
	//dest < src && dest > src-count 从前向后后拷贝
	char arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, sizeof(arr1));
	return 0;
}


//memcmp函数 - 内存比较
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,4,5,6 };
	int ret = memcmp(arr1, arr2, 9);
	printf("%d\n", ret);
}

//memset函数 - 内存设置函数
int main() {
	char arr[] = "";
	//第一个参数 - 目的地，第二个参数 - 设置的字符，第三个参数（字节） - 设置多少个字符
	memset(arr, '#', 10);
	return 0;
}