//枚举

//枚举类型
enum Sex {
	//枚举的可能取值 - 枚举常量
	MALE=2,
	FEMALE=4,
	SECRET=8
};
enum Color {
	RED,
	BLUE,
	GREEN
};
int main() {
	enum Sex s = MALE;
	enum Color c = BLUE;
	enum Color c = 2;//error
	printf("%d %d %d\n", RED, BLUE, GREEN);//0 1 2
	printf("%d %d %d\n", MALE, FEMALE, SECRET);//2 4 8
	return 0;
}

/*枚举的优点：
	1.增加代码的可读性和可维护性
	2.和#define定义的标识符比较枚举有类型检查，更为严谨
	3.防止命名污染
	4.便于调试
	5.使用方便，一次可以定义多个常量*/

//枚举的使用
enum Color {
	RED = 1,
	GREEN = 2,
	BIUE = 4
};
int main() {
	enum Color clr = GREEN;
	return 0;
}