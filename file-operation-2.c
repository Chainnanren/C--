//�ļ��Ĵ򿪺͹ر�
//�ļ��ڶ�д֮ǰӦ���ȴ��ļ�����ʹ�ý���֮��Ӧ�ùر��ļ�
//�涨fopen���������ļ���fclose���ر��ļ�


/*  �ļ�ʹ�÷�ʽ    ����                                       ���ָ���ļ�������
    "r" ��ֻ����    Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�   ����
	"w" ��ֻд��    Ϊ��������ݣ���һ���ı��ļ�			   ����һ���µ��ļ�
	"a" ��׷�ӣ�	���ı��ļ�β�������                       ����
	"rb"��ֻ����	Ϊ���������ݣ���һ���������ļ�           ����
	"wb"��ֻд��	Ϊ��������ݣ���һ���������ļ�           ����һ���µ��ļ�
	"ab"��׷�ӣ�	��һ���������ļ�β�������                 ����
	"r+"����д��    Ϊ�˶���д����һ���ı��ļ�			   ����
	"w+"����д��	Ϊ�˶���д������һ���ı��ļ�			   ����һ���µ��ļ�
	"a+"����д��	��һ���ļ������ļ�β���ж�д			   ����һ���µ��ļ�
	"rb+"����д��	Ϊ�˶���д��һ���������ļ�			   ����
	"wb+"����д��	Ϊ�˶���д���½�һ���µĶ������ļ�		   ����һ���µ��ļ�
	"ab+"����д��	��һ���������ļ������ļ�β���ж���д	   ����һ���µ��ļ�*/


#include<stdio.h>
#include<errno.h>
int main() {
	//���ļ�
	/*../../��ʾ���ϼ�·��
	  ..��ʾ��һ��·��
	  .��ʾ��ǰ·��*/
	fopen("../text.txt", "r");
	//����·��
	fopen("C:\\2020code\\84\\text.txt", "r");
	//���·��
	fopen("test.txt", "r");
	return 0;
}

int main() {
	FILE* pf=fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

//�ļ���˳���д

//д
int main() {
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//д�ļ�
	fputc('b', pf);
	fputc('u', pf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

//��
int main() {
	//���ļ�
	FILE* pfw = fopen("test.txt", "r");
	if (pfw == NULL) {
		printf("%s\n", strerror(errno));
		return 0;
	}
	//���ļ�
	printf("%c ", fgetc(pfw));
	printf("%c ", fgetc(pfw));
	//�ر��ļ�
	fclose(pfw);
	pfw = NULL;
	return 0;
}

/*���� - ��׼�����豸 - stdin
  ��� - ��׼����豸 - stdout
  ��һ������Ĭ�ϴ򿪵��������ļ�
  
  stdin  FILE*
  stdout FILE*
  stderr FILE*/

int main() {
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	return 0;
}