//ָ�����3
//����1
(*(void(*)())0)();
/*��0ǿ��ת���ɣ�void(*)() - ����ָ�����ͣ�����0��ַ����
�ú���*/
//����2
//signal��һ����������
/*signal�����Ĳ�������������һ����int��
�ڶ����Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int������
������void*/
//signal�����ķ�������Ҳ��һ������ָ�룺�ú���ָ��ָ���
// �����Ĳ�����int������������void
void(*signal(int, void(*)(int)))(int);
//��
typedef void(*pfun_t)(int);
pfun_t signal(int , pfun_t);

int add(int x, int y) {
	int z = 0;
	z = x + y;
	return z;
}
int main() {
	int a = 10;
	int b = 20;
	int(*pa)(int, int) = add;
	printf("%d\n", pa(2, 3));
	printf("%d\n", add(2, 3));
	printf("%d\n", (*pa)(2, 3)); 
	return 0;
} 

//����ָ������
int Add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int main() {
	int* arr[5];
	//��Ҫһ�����飬���������Դ��4�������ĵ�ַ - ����ָ�������
	int (*pa)(int, int) = Add;//sub/mul/div
	int (*pa[4])(int, int) = {Add,sub,mul.div};//����ָ�������
	int i = 0;
	for (i = 0; i < 4; i++) {
		printf("%d\n", pa[i](2, 3));
	}
	return 0;
}
my_strcpy(char* dest, const char* src) {
//дһ������ָ��pf���ܹ�ָ��my_strcpy
//дһ������ָ������pfArr���ܹ����4��my_strcpy�����ĵ�ַ
}
void menu() {
	printf("****************************\n");
	printf("*** 1.add ******** 2.sub ***\n");
	printf("*** 3.mul ******** 4.div ***\n");
	printf("****************************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", add(x, y));
			break;
		case 2:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", sub(x, y));
			break;
		case 3:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", mul(x, y));
			break;
		case 4:
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", div(x, y));
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

void menu() {
	printf("****************************\n");
	printf("*** 1.add ******** 2.sub ***\n");
	printf("*** 3.mul ******** 4.div ***\n");
	printf("****************************\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	//pfarr��һ������ָ������ - ת�Ʊ� 
	int(*pfaarr[5])(int, int) = { 0,add,sub,mul,div };
	do {

		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4) {
			printf("����������������\n");
			scanf("%d%d", &x, &y);
			int ret = pfarr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0) {
			printf("�˳�\n");
		}
		else
			printf("ѡ�����\n");

	} while (input);
}