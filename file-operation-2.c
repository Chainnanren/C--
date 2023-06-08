//文件的打开和关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件
//规定fopen函数来打开文件，fclose来关闭文件


/*  文件使用方式    含义                                       如果指定文件不存在
    "r" （只读）    为了输入数据，打开一个已经存在的文本文件   出错
	"w" （只写）    为了输出数据，打开一个文本文件			   建立一个新的文件
	"a" （追加）	向文本文件尾添加数据                       出错
	"rb"（只读）	为了输入数据，打开一个二进制文件           出错
	"wb"（只写）	为了输出数据，打开一个二进制文件           建立一个新的文件
	"ab"（追加）	向一个二进制文件尾添加数据                 出错
	"r+"（读写）    为了读和写，打开一个文本文件			   出错
	"w+"（读写）	为了读和写，建立一个文本文件			   建立一个新的文件
	"a+"（读写）	打开一个文件，在文件尾进行读写			   建立一个新的文件
	"rb+"（读写）	为了读和写打开一个二进制文件			   出错
	"wb+"（读写）	为了读和写，新建一个新的二进制文件		   建立一个新的文件
	"ab+"（读写）	打开一个二进制文件，在文件尾进行读和写	   建立一个新的文件*/


#include<stdio.h>
#include<errno.h>
int main() {
	//打开文件
	/*../../表示上上级路径
	  ..表示上一级路径
	  .表示当前路径*/
	fopen("../text.txt", "r");
	//绝对路径
	fopen("C:\\2020code\\84\\text.txt", "r");
	//相对路径
	fopen("test.txt", "r");
	return 0;
}

int main() {
	FILE* pf=fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//文件的顺序读写

//写
int main() {
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//写文件
	fputc('b', pf);
	fputc('u', pf);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//读
int main() {
	//打开文件
	FILE* pfw = fopen("test.txt", "r");
	if (pfw == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//读文件
	printf("%c ", fgetc(pfw));
	printf("%c ", fgetc(pfw));
	//关闭文件
	fclose(pfw);
	pfw = NULL;
	return 0;
}

/*键盘 - 标准输入设备 - stdin
  鼠标 - 标准输出设备 - stdout
  是一个程序默认打开的两个流文件
  
  stdin  FILE*
  stdout FILE*
  stderr FILE*/

int main() {
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	return 0;
}