struct student {
	int num;
	char name[32];
	float score;
}stu;
//1.struct�ǽṹ�����͵Ĺؼ���
//2.struct student���û�����Ľṹ������
//3.num��score���ǽṹ���Ա��
//4.stu���û�����Ľṹ�������


#include<stdio.h>
struct S {
	int a;
	int b;
};
int main() {
	struct S a, * p = &a;
	a.a = 99;//��һ��a�ǽṹ��������ڶ���a�ǽṹ���Աa
	//���a��ֵ
	//a.a p->a (*p).a
	//*p.a���ԣ���Ϊ.�����ȼ���*��
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
//�������� wang


//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
//�㷨1��
int main() {
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//���������ˮ�ȵ�
	total = money;
	empty = money;
	//����������ˮ
	while(empty>=2){
		total += empty / 2;
		empty=empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
}

//�㷨2��
int main() {
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//���ɣ��õ�����ˮ�����ڣ�
	if (money == 0) {
		total = 0;
	}
	else
		total = 2 * money - 1;
	return 0;
}

