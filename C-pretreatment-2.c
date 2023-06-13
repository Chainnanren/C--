//预处理详解

//预定义符号

//__FILE__ - 代码所在文件的绝对路径
int main() {
	printf("%s\n", __FILE__);
	return 0;
}

//__LINE__ - 文件当前的行号
int main() {
	printf("%d\n", __LINE__);
	return 0;
}

//__DATE__ - 文件被编译的日期
int main() {
	printf("%s\n", __DATE__);
	return 0;
}

//__TIME__ - 时间
int main() {
	printf("%s\n", __TIME__);
	return 0;
}

/* 预处理指令：
   #define
   #include
   #pragrma
   #if
   #endif
   #ifdef
   #line*/
