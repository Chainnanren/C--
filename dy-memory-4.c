//��������ı�����

//1.
#include<stdio.h>
void GetMemory(char* p) {
	p = (char*)malloc(100);
}
void test(void) {
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");//�������
	printf(str);
}
int main() {
	test();
	return 0;
}
/*1.���д���������ֱ��������� 
  2.��������ڴ�й©������
  ��str��ֵ���ݵ���ʽ��p��p��GetMemory�������βΣ�ֻ�ܺ����ڲ���Ч
   ��GetMemory��������֮�󣬶�̬�����ڴ���δ�ͷŲ����޷��ҵ������Ի�����ڴ�й©��*/

//���� 1.
#include<stdio.h>
void GetMemory(char** p) {
	*p = (char*)malloc(100);
}
void test(void) {
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");//�������
	printf(str);
	free(str);
	str = NULL;
}
int main() {
	test();
	return 0;
}

//���� 2.
#include<stdio.h>
char* GetMemory(char* p) {
	p = (char*)malloc(100);
	return p;
}
void test(void) {
	char* str = NULL;
	str = GetMemory(str);
	strcpy(str, "hello world");//�������
	printf(str);
	free(str);
	str = NULL;
}
int main() {
	test();
	return 0;
}

//2. - ����ջ�ռ�ĵ�ַ������
char* GetMemory(void) {
	char p[] = "helloworld";
	return p;
}
void test(void) {
	char* str = NULL;
	str = GetMemory();//����ʱp�Ŀռ�����٣���������ֵ
	printf(str);
}
int main() {
	test();
	return 0;
}

int* test() {
	static int a = 10;//staticʹ�ռ����������ӳ� - ��̬��
	return &a;
}
int main() {
	int* p = test();
	*p = 20;
	return 0;
}

int* test() {
	//���� - ����������ptr�����٣���malloc���ٵĿռ䲻�����٣������˿ռ䴫����ָ�����p
	int* ptr = malloc(100);
	return ptr;
}
int main() {
	int* p = test();
	return 0;
}

//3.
void GestMemory(char** p, int num) {
	*p = (char*)malloc(num);
}
void test(void) {
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);//�����ͷŶ�̬���ٵ��ڴ棬�����ڴ�й¶
}
int main() {
	test();
	return 0;
}

//4.
void test(void) {
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	//����
	str = NULL;
	/*free�ͷ��˶�̬���ٵ��ڴ棬��û�н�str��ΪNULL������str��Ȼָ��
	��̬���ٵ��׵�ַ���Ӷ����·Ƿ������ڴ�*/
	if (str != NULL) {
		strcpy(str, "world");
		printf(str);//������������ world
	}
}
int main() {
	test();
	return 0;
}

int main() {

	return 0;
}