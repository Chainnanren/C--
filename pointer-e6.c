//ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ��������������� - ��֪��
//�ǳ���ԱҲ��֪�������Ƚϵ�����Ԫ�ص����� 
void Swap(char* buf1, char* buf2, int width) {
	int i = 0;
	for (i = 0; i < width; i++) {
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}

}
void bubble_sort(void* base, int sz, int width, int (*cmp)(void*e1, void*e2)) {
	 int i = 0;
	 //����
	 for (i = 0; i < sz - 1; i++) {
		 //ÿһ�˱ȽϵĶ���
		 int j = 0;
		 for (j = 0; j < sz - 1 - i; j++) {
			 //����Ԫ�صıȽ�
			 if ((cmp((char*)base + j * width, (char*)base + (j + 1) * width))>0);
			  //����
			 Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
		 }
	 } 
}
int cmp_int(const void* e1,const void* e2) {
	//�Ƚ���������ֵ
	return *(int*)e1 - *(int*)e2;
}
void test4() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô����
	//��Ӧ��֪����αȽϴ����������е�Ԫ��
	bubble_sort(arr, sz, sizeof(arr[0]),cmp_int);
}

int cmp_stu_by_age(const void* e1,const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2) {
	return ((struct stu*)e1)->name - ((struct stu*)e2)->name;

}
struct stu {
	char name[20];
	int age;
};
void test5() {
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]); 
	bubble_sort(s, sz, sizeof(s[0]),cmp_stu_by_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main() {
	test4();
	test5();
	return 0;
}