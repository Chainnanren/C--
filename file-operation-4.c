#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//文件的随机读写

//fseek函数 - 根据文件指针的位置和偏移量来定位文件指针
//int fseek(FILE* stream,long offset,int origin)  
				//文件指针  偏移量  文件指针的当前位置
/*SEEK_CUR  文件指针的当前位置
  SEEK_END  文件的末尾位置
  SEEK_SET  文件的起始位置*/
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//1.定位文件指针
	fseek(pf, 2, SEEK_CUR);
	//2.读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}

//ftell函数 - 返回文件指针相对于起始位置的偏移量
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//1.定位文件指针
	fseek(pf, 2, SEEK_CUR);
	//2.读取文件
	int pos = ftell(pf);
	printf("%d\n", pos);
	fclose(pf);
	pf = NULL;
	return 0;
}

//rewind函数 - 让文件指针的位置回到文件起始位置
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	int ch = fgetc(pf);
	printf("%c\n", ch);
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}


//文件结束判断

//EOF文件结束标志
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	int ch = fgetc(pf);
	printf("%d\n", ch);//-1
	fclose(pf);
	pf = NULL;
	return 0;
}

/*feof函数
  牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件是否结束。而是应用于
  文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束*/

/*1.文本文件读取是否结束，判断返回值是否为EOF，或者NULL
	例如：
		1.fgetc判断是否为EOF
		2.fgets判断返回值是否为NULL
  2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
    例如：
		1.fread判断返回值是否小于实际要读的个数*/

int main() {
	/*strerror - 把错误码对应的错误信息的字符串地址返回*/

	//perror
	FILE* pf = fopen("test2.txt", "r");
	if (pf == NULL) {
		perror("hehe");
		return 0;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	int c;
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("FILE opening failed");
		return -1;
	}
	//fgetc当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	while ((c = fgetc(fp) != EOF)) //标准C I/O读取文件循环
	{
		putchar(c);
	}
	//判断是什么原因结束的
	if (ferror(fp)){
		puts("I/O error when reading");
	}
	else if (feof(fp)) {
		puts("End od file reached successfully");
	}
	fclose(fp);
	fp = NULL;
}