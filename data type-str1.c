/*内置类型：C语言自己的数据类型
  如：char，short，int*/
/*自定义类型：结构体，枚举联合体*/

//结构体
//结构体的声明
/*结构体的基础知识
	结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量*/

struct stu {
	//成员变量
	char name[20];//名字
	char tele[20];//电话
	char sex[10];//性别
	int age;
}s4,s5,s6;
//s3 s4 s5 s6都是全局变量
struct stu s3;
int main() {
	//struct stu是类型 s1是变量
	//s1局部变量
	struct stu s1;
	return 0;
}

//特殊声明
//匿名结构体类型
//只能创建全局变量
struct {
	int a;
	char b;
	float c;
}x;
//匿名结构体指针类型
struct {
	int a;
	char;
}*psa;
int main() {
	//编译器会把上面的两个声明当成完全不同的两个类型，所以是非法的
	psa = &x;
	return 0;
}

//结构体的自引用
//在结构体中不能包含一个类型为该结构本身的成员

//正确的自引用方式
struct Node {
	int data;
	struct Node* next;
};


//typedef重命名
typedef struct Node {
	int data;
	struct Node* next;
}Node;//Node为类型名


//结构体变量的定义和初始化
struct T {
	double weight;
	short age;
};
struct S {
	char c;
	int a;
	struct T st;
	double d;
	char arr[20];
};
int main() {
	struct S s = { 'c',100,{55.6,30},3.14,"helloworld" };
	printf("%c %d %lf %s\n", s.c, s.a, s.d, s.d, s.arr);
	printf("%lf\n", s.st.weight);
	return 0;
}

