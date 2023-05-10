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
//假设p的值为 0x100000。如下表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
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
	//ptr[-1] = *(ptr+(-1))  ptr[-1]其实表示的是ptr指针当前指向的上一个元素
	/*(int)a + 1是指地址啊的下一个地址
	* a是一个地址，而(int)a则是把a的地址值强制为一个int整数，给这个整数+1就是a的下一个地址单元
	* 如：a=0013FF6C   (int)a+1=0013FF6D*/ 
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}


int main() {
	//逗号表达式，以最后一个数为结果
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
//地址以补码的形式表露，数以原码的形式表露
//FFFFFFFC -4


int main() {
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));//*(aa+1) - 第二行首元素地址
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//10 5


int main() {
	//将元素的首字母的地址存放到a数组里面
	char* a[] = { "work","at","alibaba" };
	//数组名表示首元素的地址 

	//char** 存放的是char*的地址， char*存放的是元素首字母的地址
	//char** char*是类型 *pa是指针
	char** pa = a;
	pa++; 
	printf("%s\n", *pa);
	return 0;
}


int main() {
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	//C+3指向"FIRST" C+2指向"POINT" C+1指向"NEW" C指向"ENTER"
	char** cp[] = { c + 3,c + 2,c + 1,c };
	//**cpp存放c+3的地址
	char*** cpp = cp;

	//++cpp指向第二个元素   *cpp=c+2   **cpp=POINT
	printf("%s\n", **++cpp);//POINT

	//再++cpp指向第三个元素   *++cpp=c+1  *++cpp拿到空间的内容，所以--*++cpp=c *--*++cpp=ENTER
	printf("%s\n", *-- * ++cpp + 3);//ER
	
	//*cpp[-2] = **(cpp+(-2))   *(cpp[-2]) = c+3   **(cpp[-2]) = FIRST
	printf("%s\n", *cpp[-2] + 3);//FIRST

	//cpp[-1][-1] = *(*(cpp-1)-1)
	printf("%s\n", cpp[-1][-1] + 1);//EW
	return 0;
}