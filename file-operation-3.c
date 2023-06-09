//fgets����
#include<stdio.h>
int main() {
	char buf[1024] = { 0 };
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//���ļ�
	fgets(buf, 1024, pf);
	printf("%s", buf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

//fputs����
#include<stdio.h>
int main() {
	char buf[1024] = { 0 };
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//д�ļ�
	fputs("hello\n",pf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
	fputs(buf, stdout);//�������׼�����
	return 0;
}

//fprintf����
struct S {
	int n;
	float score;
	char arr[10];
};
int main() {
	struct S s = { 100,3.14,"bit" };
	FILE* pf = fopen("text,txt", "w");
	if (pf == NULL) {
		return 0;
	}
	//��ʽ������ʽд
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}

//fscanf����
int main() {
	struct S s = { 100,3.14,"bit" };
	FILE* pf = fopen("text,txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//��ʽ������ʽ��������
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
	printf("%d %f %s\n", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	struct S s = { 100,3.14,"bit" };
	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
	return 0;

}

//sprintf��sscanf
struct S s {
	int n;
	float score;
	char arr[10];
};
int main() {
	struct S s = { 100,3.14,"abcdef" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//�Ѹ�ʽ��������ת�����ַ����洢��buf��
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
	printf("%s\n", buf);
	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
	return 0;
}


/*scanf/printf ����Ա�׼������/��׼������ĸ�ʽ������/���
  fscanf/fprintf ���������������/����������ĸ�ʽ������/������

  sscanf/sprintf  sscanf�Ǵ��ַ����ж�ȡ��ʽ��������
				  sprintf�ǰѸ�ʽ������������ַ���*/



//fread��fwrite����
struct S {
	char name[20];
	int age;
	double score;
};
int main() {
	struct S s = { "����",20,55.6 };
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL) {
		return 0;
	}
	//�����Ƶ���ʽд�ļ�
	fwrite(&s, sizeof(struct S), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}


struct S {
	char name[20];
	int age;
	double score;
};
int main() {
	struct S tmp = { 0 };
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL) {
		return 0;
	}
	//�����Ƶ���ʽ���ļ�
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;
	return 0;
}