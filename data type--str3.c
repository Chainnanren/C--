//�ṹ�崫�� 
#include<stdio.h>
struct S {
	int a;
	char c;
	double d;
};
void Init(struct S* ps) {
	ps->a = 100;
	ps->c = 'w';
	ps->d = 3.14;
}
//��ֵ
void Print1(struct S tmp) {
	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
}
//��ַ
void Print2(const struct S* ps) {
	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
}
int main() {
	struct S s;
	Init(&s);
	Print1(s);
	Print2(&s);
	return 0;
}
//���ۣ�
//	�ṹ�崫�ε�ʱ��Ҫ���ṹ��ĵ�ַ

/*ԭ��
	�������ε�ʱ�򣬲�������Ҫѹջ������ʱ��Ϳռ��ϵ�ϵͳ����
	�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ��ϵͳ�����Ƚϴ�����
	�ᵼ�����ܵ��½�*/