//���� - ������ - ������
//������Ķ���
//����Ҳ��һ������Ķ������� �������Ͷ���ı���Ҳ����һϵ�еĳ�Ա����������Щ��Ա
//����ͬһ��ռ䣨��������Ҳ�й����壩
/*���ϵ��ص㣺
	���ϵĳ�Ա�ǹ���ͬһ���ڴ�ռ�ģ�����һ�����ϱ����Ĵ�С������������Ա��
	��С����Ϊ�������ٵ����������������Ǹ���Ա��*/
union Un {
	char c;
	int i;
};
int main() {
	union Un u;
	printf("%d\n", sizeof(u));//4
	printf("%p\n", &u);
	printf("%p\n", &(u.c));
	printf("%p\n", &(u.i));
	return 0;
}

//�жϵ�ǰ������Ĵ�С�洢
//����һ�����ݣ������ڴ��еĴ�ŵ��ֽ�˳��
//��С���ֽ�������
int main() {
	int a = 1;
	if (*(char*)&a == 1) {
		printf("С��\n");
	}
	else {
		printf("���\n");
	}
	return 0;
}


int check_sys() {
	union Un {
		char c;
		int a;
	}u;
	u.a = 1;
	return u.c;
}
int main() {
	int ret = check_sys();
	if (ret == 1) {
		printf("С��\n");
	}
	else {
		printf("���\n");
	}
	return 0;
}

/*���ϴ�С�ļ���
	1.���ϴ��С����������Ա�Ĵ�С
	2.������Ա��С�������������������ʱ�򣬾�Ҫ���뵽����������������*/
union Un {
	int a;
	char arr[5];
};
int main() {
	union Un u;
	printf("%d\n", sizeof(u));//8
	return 0;
}