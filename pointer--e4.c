//ָ����ָ�������ָ��
int main() {
	int arr[10] = { 0 };
	int (*p)[10]= &arr;//ȡ������ĵ�ַ

	int (*pf)(int, int);//����ָ��
	int (*pfarr[4])(int, int);//pfarr��һ������ - ����ָ�������
	//ppfaarr��һ��ָ����ָ�������ָ��
	int (*(*ppfarr)[4])(int, int) = &ppfarr;
	//pfarr��һ������ָ�룬ָ��ָ���������4��Ԫ��
	//ָ��������ÿ��Ԫ�ص�������һ������ָ��int(*)(int,int)
	return 0;
}
//�ص�����
void print(char* str) {
	printf("hehe:%s", str);
}
void test(void(*p)(char*)) {
	printf("test\n");
	p("bit");
}
int main() {
	test(print);
	return 0;
}

void Bubblesort(int arr[], int sz) {
	//......
}
//qsort - ���������������͵�����
int main() {
	//ð��������
	//ð��������ֻ��������������
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, sz);
	return 0;
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
int calc(int (*pa)(int,int)){
	int x = 0;
	int y = 0;
	printf("����������������\n");
	scanf("%d%d", &x, &y);
	printf("%d\n", pa(x, y));
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
			cale(add);
			break;
		case 2:
			cale(sub);
			break;
		case 3:
			cale(mul);
			break;
		case 4:
			cale(div);
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
