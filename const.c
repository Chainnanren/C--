int main() {
	const int num = 0;
	const int* p = &num;
	/*const 放在指针变量的*左边时，修饰的是*p，也
	就是说：不能通过p来改变*p(num)的值*/
	*p = 20;
	printf("/d\n", num);
	return 0;
}

int main() {
	const int num = 0;
	int* const p = &num;
	/*const 放在指针变量的*右边时，修饰的是指针变量p，也
	就是说：p不能被改变*/
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;   
}

int main() {
	const int num = 0;
	const int* const p = &num;
	/*const 放在两边时，不能通过p来改变*p(num)的值
	也不能改变p */
	int n = 100;
	p = &n;
	printf("/d\n", p);
	return 0;
}