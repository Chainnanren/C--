//�ַ����ຯ��

/*����        ������Ĳ����������������ͷ�����

 iscntrl      �κο����ַ�

 isspace      �հ��ַ����ո�' '����ҳ'f',����'\n',�س�'\r',�Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'

 isdigit      ʮ��������0~9

 isxdigit     ʮ���������֣���������ʮ�������֣�Сдa~f����д��ĸA~F

 islower      Сд��ĸa~z

 isupper      ��д��ĸA~Z

 isalpha      ��ĸa~z��A~Z
 
 isalnum      ��ĸ�������֣�a~z��A~Z,0~9
 
 ispunct      �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
 
 isgraph      �κ�ͼ���ַ�
 
 isprint      �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳո��ַ�*/


#include<ctype.h>
//�ж��ǲ���Сд��ĸ
//��Сд��ĸ���ط�������  ����Сд��ĸ����0
int main() {
	char ch = 'w';
	int ret = islower(ch);
	printf("%d\n", ret);
	return 0;
}

//�ж��ǲ�������
int main() {
	char ch = '1';
	int ret = isdigit(ch);
	printf("%d\n", ret);
}




//�ַ�ת������ - ��дתСд��Сдת��д
/*int tolower(int c); - ��дתСд
  int toupper(int c); - Сдת��д*/

int main() {
	char ch = tolower('q');
	putchar(ch);
}

int main() {
	char arr[] = "I Am A Student";
	int i = 0;
	while (arr[i]) {
		if (isupper(arr[i])) {
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s\n", arr);
}