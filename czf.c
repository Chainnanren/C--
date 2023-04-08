/* Note:Your choice is C IDE */
//单目操作符
#include "stdio.h"
void main()
{
    int a=10;
    //!（逻辑反操作符）假变真，真变假
    printf("%d\n",!a);
    //取地址操作符
    int* p=&a;
    //解引用操作符
    //通过p中存放的值找到它所指向的对象
    *p=20;
    //sizeof计算变量所占内存空间的大小，单位是字节
    /*sizeof后面是变量可以省略括号
    		后面是类型不能省略*/
    int a=10;
    char c='r';
    char* p=&c;
    int arr[10]={0};
    printf("%d\n",sizeof(a));//4
     printf("%d\n",sizeof(int));//4
     
    printf("%d\n",sizeof(c));//1
     printf("%d\n",sizeof(char));//1
     
    printf("%d\n",sizeof(p));//4或8
     printf("%d\n",sizeof(char*));//4或8
     
     //对于数组来说去掉数组名就是数组的类型
    printf("%d\n",sizeof(arr));//40
     printf("%d\n",sizeof(int [10]));//40
    return 0;
}
int main(){
	//~按（二进制）位取反
	int a=0;
	printf("%d\n",~a);
	int a=11;
	a=a|(1<<2);
	printf("%d\n",a);//15
	a=a&(~1<<2);
	printf("%d\n",a);//11
}
int main(){
	int a=10;
	printf("%d",++a);//前置++，先++，后使用
	printf("%d",a++);//后置++，先使用，再++
}
int main(){
	int a=(int)3.14;//强制转化成int类型
}
//三目操作符（条件操作符）
//exp1?exp2:exp3
int main(){
	int a=0;
	int b=0;
	if(a>5)
	b=3;
	else
	b=-3;
	b=(a>5?3:-3);
	
	int a=10;
	int b=20;
	int max=0;
	if(a>b)
	max=a;
	else
	max=b;
	max=a>b?a:b;
	
	return 0;
}
//逗号表达式
//exp1,exp2,exp3,exp4......expN;
int main(){
	//代码1
	int a=1;
	int b=2;
	int c=(a>b,a=b+10,a,b=a+1);
	printf("%d\n",c);
	//c等于13
	//代码2
	if(a=b+1,c=a/2,d>0);
	//代码3
	a=get_val();
	count_val(a);
	while(a>0){
		a=get_val();
		count_val(a);
	}
	//使用逗号表达式，改写:
	while(a=get_val(),count_val(a),a>0){
		//业务处理
		}
	return
	 0;
}
//函数调用操作符
int get_max(int x,int y){
	return x>y?x:y;
	}
int main(){
	int a=0;
	int b=0;
	//调用函数的时候()就是函数调用操作符
	int max=get_max(a,b);
	printf("max=%d\n",max);	
	return 0;
}
//创建一个结构体类型 类型名-struct stu 
//学生
struct stu{
	char name[20];
	int age;
	char id[20];
	}
int main(){
	int a=10;
	//使用struct stu这个类型创建了一个学生对象s1，并初始化
	struct stu s1={"张三",20,"22219010234"};
	struct stu* ps=&s1;
	//结构体指针->成员名
	printf("%s\n",ps->name);
	printf("%s\n",(*ps).name);
	/*printf("%s\n",s1.name);
	printf("%d\n",s1.age);
	printf("%s\n",s1.id);*/
	//结构体变量.成员名
	return 0;
}
//表达式求值
//隐形转换 整形提升
int main(){
	char a=3;
	//000000000000000000000011
	//00000011-a
	char b=127;
	//000000000000000001111111
	//01111111-b
	
	//a和b如何相加
	//000000000000000000000011
	//000000000000000001111111
	//000000000000000010000010
	char c=a+b;
	//10000010
	//111111111111111110000010-补码
	//111111111111111110000001-反码
	//100000000000000001111110-原码
	printf("%d\n",c);
	return 0;
}
