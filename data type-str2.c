/*�ṹ��Ķ������
  1.��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ��
  2.������Ա����Ҫ���뵽ĳ������(������)���������ĵ�ַ��
  �������� = ������Ĭ�ϵ�һ����������ó�Ա��С�Ľ�Сֵ��
  * VSĬ�ϵ�ֵΪ8
  3.�ṹ���ܴ�СΪ��������(ÿ����Ա��������һ��������)��������
  4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ����������������ṹ���
  �����С����������������(��Ƕ�׽ṹ��Ķ�����)��������*/
//�ṹ���ڴ����
struct S1 {
	char c1;
	int a;
	char c2;
};
struct S2 {
	char c1;
	char c2;
	int a;
};
int main() {
	struct S1 s1 = { 0 };
	printf("%d\n", sizeof(s1));
	struct S2 s2 = { 0 };
	printf("%d\n", sizeof(s2));
	return 0;
}
//12 8
struct S3 {
	double d;
	char c;
	int i;
};
int main() {
	printf("%d\n", sizeof(struct S3));
	return 0;
}
//16

//�ṹ��Ƕ������
struct S4 {
	char c1;
	struct S3 s3;
	double d;
};//32

int main() {

	return 0;
}

/*Ϊʲô�ڴ���룿
  1.ƽ̨ԭ�򣺲������е�Ӳ��ƽ̨���ܷ��������ַ�ϵ��������ݵģ�ĳЩӲ��ƽ̨
  ֻ����ĳЩ��ַ��ȡĳЩ�ض������ݣ������׳�Ӳ���쳣
  2.����ԭ�����ݽṹ��������ջ��Ӧ�þ����ܵ�����Ȼ�߽��϶��롣ԭ�����ڣ�
  Ϊ�˷���δ������ڴ棬��������Ҫ�����η��ʣ���������ڴ���ʽ���Ҫһ�η���*/
//������˵��
//		�ṹ����ڴ�������ÿռ�����ȡʱ�������

/*������ƽṹ���ʱ�����Ǽ�Ҫ������룬��Ҫ��ʡ�ռ䣬���������
		��ռ�ÿռ�С�ĳ�Ա�������е�һ��*/




//�޸�Ĭ�϶�����
//����Ĭ�϶�����Ϊ4
#pragma pack(4)
struct S{
	char c1;
	double d;
};

//ȡ�����õ�Ĭ�϶�����,��ԭΪĬ��
#pragma pack()

int main() {
	struct S s;
	printf("%d\n", sizeof(s));
	return 0;
}
//���ۣ�
	//�ṹ�ڶ��뷽ʽ�����ʵ�ʱ�����ǿ����Լ�����Ĭ�϶�����

//offsetof����ṹ���Ա����ڽṹ����ʼλ�õ�ƫ���������Ǻ���  �Ǻ꣩
#include<stddef.h>
struct S {
	char c;
	int i;
	double d;
};
int main() {
	//offsetof();
	printf("%d\n", offsetof(struct S, c));//0
	printf("%d\n", offsetof(struct S, i)); //4
	printf("%d\n", offsetof(struct S, d)); //8
	return 0;
}