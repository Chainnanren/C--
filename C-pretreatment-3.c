//#define - 定义标识符

/* #define reg register         //为register这个关键字，创建一个简短的名字
   #define do_forever for(;;)   //用更形象的符号来替换一种实现
   #dedfine CASE break; case    //在写case语句的时候自动把break写上*/


#define MAX 100
#define STR "hehe"

int main() {
	int max = MAX;
	printf("%d\n", max);
	printf("%s\n", STR);
	return 0;
}


//define定义宏
//define机制包括了一个规定，允许把参数替换到文本中，这种实现通常成为宏或者定义宏

/*如：
	#define SQUARE(x) x*x
	这个宏接受一个参数x；如果上述声明后，你把
	SQUARE(5);
	置于程序中，预处理器就会用下面这个表达式替换上面的表达式
	5 * 5 */

/*提示：
  所以用于对数值表达式进行求值的宏定义都应该用这种方式加上括号，避免在使用宏时由于参数中的操作
  符或邻近操作符之间不可预料的相互作用*/

#define SQUARE(X) (X)*(X)
int main() {
	int a = 5;
	printf("%d\n", SQUARE(a + 1));//11
}

//define替换规则
/*在程序中扩展#define定义符号和宏时，需要涉及几个步骤：
	1.在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，他们首先被替换
	2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换
	3.最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程*/

/*注意：
	1.宏参数和#define定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归
	2.当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索*/
