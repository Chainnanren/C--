//ö��

//ö������
enum Sex {
	//ö�ٵĿ���ȡֵ - ö�ٳ���
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

/*ö�ٵ��ŵ㣺
	1.���Ӵ���Ŀɶ��ԺͿ�ά����
	2.��#define����ı�ʶ���Ƚ�ö�������ͼ�飬��Ϊ�Ͻ�
	3.��ֹ������Ⱦ
	4.���ڵ���
	5.ʹ�÷��㣬һ�ο��Զ���������*/

//ö�ٵ�ʹ��
enum Color {
	RED = 1,
	GREEN = 2,
	BIUE = 4
};
int main() {
	enum Color clr = GREEN;
	return 0;
}