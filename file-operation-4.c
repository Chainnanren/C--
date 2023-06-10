#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�ļ��������д

//fseek���� - �����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��
//int fseek(FILE* stream,long offset,int origin)  
				//�ļ�ָ��  ƫ����  �ļ�ָ��ĵ�ǰλ��
/*SEEK_CUR  �ļ�ָ��ĵ�ǰλ��
  SEEK_END  �ļ���ĩβλ��
  SEEK_SET  �ļ�����ʼλ��*/
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//1.��λ�ļ�ָ��
	fseek(pf, 2, SEEK_CUR);
	//2.��ȡ�ļ�
	int ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}

//ftell���� - �����ļ�ָ���������ʼλ�õ�ƫ����
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//1.��λ�ļ�ָ��
	fseek(pf, 2, SEEK_CUR);
	//2.��ȡ�ļ�
	int pos = ftell(pf);
	printf("%d\n", pos);
	fclose(pf);
	pf = NULL;
	return 0;
}

//rewind���� - ���ļ�ָ���λ�ûص��ļ���ʼλ��
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	int ch = fgetc(pf);
	printf("%c\n", ch);
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}


//�ļ������ж�

//EOF�ļ�������־
int main() {
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	int ch = fgetc(pf);
	printf("%d\n", ch);//-1
	fclose(pf);
	pf = NULL;
	return 0;
}

/*feof����
  �μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ��Ƿ����������Ӧ����
  �ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�β����*/

/*1.�ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF������NULL
	���磺
		1.fgetc�ж��Ƿ�ΪEOF
		2.fgets�жϷ���ֵ�Ƿ�ΪNULL
  2.�������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
    ���磺
		1.fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���*/

int main() {
	/*strerror - �Ѵ������Ӧ�Ĵ�����Ϣ���ַ�����ַ����*/

	//perror
	FILE* pf = fopen("test2.txt", "r");
	if (pf == NULL) {
		perror("hehe");
		return 0;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	int c;
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("FILE opening failed");
		return -1;
	}
	//fgetc����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	while ((c = fgetc(fp) != EOF)) //��׼C I/O��ȡ�ļ�ѭ��
	{
		putchar(c);
	}
	//�ж���ʲôԭ�������
	if (ferror(fp)){
		puts("I/O error when reading");
	}
	else if (feof(fp)) {
		puts("End od file reached successfully");
	}
	fclose(fp);
	fp = NULL;
}