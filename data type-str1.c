/*�������ͣ�C�����Լ�����������
  �磺char��short��int*/
/*�Զ������ͣ��ṹ�壬ö��������*/

//�ṹ��
//�ṹ�������
/*�ṹ��Ļ���֪ʶ
	�ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı���*/

struct stu {
	//��Ա����
	char name[20];//����
	char tele[20];//�绰
	char sex[10];//�Ա�
	int age;
}s4,s5,s6;
//s3 s4 s5 s6����ȫ�ֱ���
struct stu s3;
int main() {
	//struct stu������ s1�Ǳ���
	//s1�ֲ�����
	struct stu s1;
	return 0;
}

//��������
//�����ṹ������
//ֻ�ܴ���ȫ�ֱ���
struct {
	int a;
	char b;
	float c;
}x;
//�����ṹ��ָ������
struct {
	int a;
	char;
}*psa;
int main() {
	//����������������������������ȫ��ͬ���������ͣ������ǷǷ���
	psa = &x;
	return 0;
}

//�ṹ���������
//�ڽṹ���в��ܰ���һ������Ϊ�ýṹ����ĳ�Ա

//��ȷ�������÷�ʽ
struct Node {
	int data;
	struct Node* next;
};


//typedef������
typedef struct Node {
	int data;
	struct Node* next;
}Node;//NodeΪ������


//�ṹ������Ķ���ͳ�ʼ��
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

