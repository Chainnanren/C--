// # �� ##

// # - �Ѻ�Ĳ������뵽�ַ�����
#define PRINT(X) printf("the value of"#X"is %d\n",X)//��X����Ӧ�����ݱ������Ӧ���ַ���
int main() {
	int a = 10;
	int b = 20;
	PRINT(a);// #X���"a"
	PRINT(b);// #X���"b"
	return 0;
}

// ## - ���԰�λ�������ߵķ��źϳ�һ�����š�������궨��ӷ�����ı�Ƭ�δ�����ʶ��
#define CAT(X,Y) X##Y
int main() {
	int Class84 = 2019;
	printf("%d\n", CAT(Class, 84));
	return 0;
}
//ע�����������ӱ������һ���Ϸ��ı�ʶ����������������δ����
