int main() {
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(ptr - 1));
	return 0;
}
//2,5

struct Test {
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//����p��ֵΪ 0x100000�����±��ʽ��ֵ�ֱ�Ϊ���٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
int main() {
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0X1);//0x100000 + 20 = 0x00100014
	printf("%p\n", (unsigned long)p + 0X1);//1048576 + 1 = 0x00100001
	printf("%p\n", (unsigned int*)p + 0X1);//0x00100004
	return 0; 
}


int main() {
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	//ptr[-1] = *(ptr+(-1))  ptr[-1]��ʵ��ʾ����ptrָ�뵱ǰָ�����һ��Ԫ��
	/*(int)a + 1��ָ��ַ������һ����ַ
	* a��һ����ַ����(int)a���ǰ�a�ĵ�ֵַǿ��Ϊһ��int���������������+1����a����һ����ַ��Ԫ
	* �磺a=0013FF6C   (int)a+1=0013FF6D*/ 
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}


int main() {
	//���ű��ʽ�������һ����Ϊ���
	int a[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = a[0];
	printf("%d\n", p[0]);//p[0]=*(p+0)
	return 0;
}
//1


int main() {
	int a[5][5];
	int(*p)[4];
	p = a;
	//p[4][2] = *(*(p+4)+2)
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
} 
//��ַ�Բ������ʽ��¶������ԭ�����ʽ��¶
//FFFFFFFC -4


int main() {
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));//*(aa+1) - �ڶ�����Ԫ�ص�ַ
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//10 5


int main() {
	//��Ԫ�ص�����ĸ�ĵ�ַ��ŵ�a��������
	char* a[] = { "work","at","alibaba" };
	//��������ʾ��Ԫ�صĵ�ַ 

	//char** ��ŵ���char*�ĵ�ַ�� char*��ŵ���Ԫ������ĸ�ĵ�ַ
	//char** char*������ *pa��ָ��
	char** pa = a;
	pa++; 
	printf("%s\n", *pa);
	return 0;
}


int main() {
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	//C+3ָ��"FIRST" C+2ָ��"POINT" C+1ָ��"NEW" Cָ��"ENTER"
	char** cp[] = { c + 3,c + 2,c + 1,c };
	//**cpp���c+3�ĵ�ַ
	char*** cpp = cp;

	//++cppָ��ڶ���Ԫ��   *cpp=c+2   **cpp=POINT
	printf("%s\n", **++cpp);//POINT

	//��++cppָ�������Ԫ��   *++cpp=c+1  *++cpp�õ��ռ�����ݣ�����--*++cpp=c *--*++cpp=ENTER
	printf("%s\n", *-- * ++cpp + 3);//ER
	
	//*cpp[-2] = **(cpp+(-2))   *(cpp[-2]) = c+3   **(cpp[-2]) = FIRST
	printf("%s\n", *cpp[-2] + 3);//FIRST

	//cpp[-1][-1] = *(*(cpp-1)-1)
	printf("%s\n", cpp[-1][-1] + 1);//EW
	return 0;
}