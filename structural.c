struct student {
	int num;
	char name[32];
	float score;
}stu;
//1.struct是结构体类型的关键字
//2.struct student是用户定义的结构体类型
//3.num，score都是结构体成员名
//4.stu是用户定义的结构体变量名


#include<stdio.h>
struct S {
	int a;
	int b;
};
int main() {
	struct S a, * p = &a;
	a.a = 99;//第一个a是结构体变量，第二个a是结构体成员a
	//输出a的值
	//a.a p->a (*p).a
	//*p.a不对，因为.的优先级比*高
	printf("%d\n",a.a);
	return 0;
}


struct stu {
	int num;
	char name[10];
	int age;
};
void fun(struct stu* p) {
	printf("%s\n", (*p).name);
	return;
}
int main() {
	struct stu students[3] = { {9801,"zhang",20},{9802,"wang",19},{9803,"zhao",18} };
	fun(students + 1);
	return 0;
}
//输出结果是 wang


//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
//算法1：
int main() {
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//买回来的汽水喝掉
	total = money;
	empty = money;
	//换回来的汽水
	while(empty>=2){
		total += empty / 2;
		empty=empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
}

//算法2：
int main() {
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//规律：得到的汽水数等于：
	if (money == 0) {
		total = 0;
	}
	else
		total = 2 * money - 1;
	return 0;
}

