int main() {
	const int num = 0;
	const int* p = &num;
	/*const ����ָ�������*���ʱ�����ε���*p��Ҳ
	����˵������ͨ��p���ı�*p(num)��ֵ*/
	*p = 20;
	printf("/d\n", num);
	return 0;
}

int main() {
	const int num = 0;
	int* const p = &num;
	/*const ����ָ�������*�ұ�ʱ�����ε���ָ�����p��Ҳ
	����˵��p���ܱ��ı�*/
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;   
}

int main() {
	const int num = 0;
	const int* const p = &num;
	/*const ��������ʱ������ͨ��p���ı�*p(num)��ֵ
	Ҳ���ܸı�p */
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;
}