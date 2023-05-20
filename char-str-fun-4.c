//strtok����
/*char* strtok(char* str,const char* sep)
1.sep�����Ǹ��ַ����������������ָ������ַ�����
2.��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı��
3.strtok�����ҵ�str�е���һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ��
��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ģ�
4.strrok�����ĵ�һ��������ΪNULL���������ҵ�str��һ����ǣ�strtok���������������ַ����е�λ��
5.strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ�����
6.����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ��*/
#include<string.h>
int main() {
	char arr[] = "zpw@bitdu.tech";
	char* p = "@.";
	char* ret = strtok(arr, p);
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);
	return 0;
}

#include<string.h>
int main() {
	char arr[] = "zpw@bitdu.tech";
	char* p = "@.";
	char* ret =NULL;
	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p)) {
		printf("%s\n", ret);
	}
	return 0;
}

//streror���� - ���󱨸溯��
//���ش����룬����Ӧ�Ĵ�����Ϣ
#include<errno.h>
int main() {
	//�����룬ÿ�������붼�ж�Ӧ�Ĵ�����Ϣ
	//1 - No error
	//2 - Operation not permitted
	//3 - No such file or directory
	//...
	//errno��һ��ȫ�ֵĴ�����ı���
	//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
	char* str = strerror(errno);
	printf("%s\n", str);
	return 0;
}

#include<errno.h>
#include<stdio.h>
int main() {
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		printf("%s\n", strerror(errno));
	}
	else {
		printf("open file success\n");
	}
	return 0;
}
