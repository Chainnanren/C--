//联合 - 联合体 - 共用体
//联合体的定义
//联合也是一种特殊的定义类型 这种类型定义的变量也包含一系列的成员，特征是这些成员
//共用同一块空间（所以联合也叫共用体）
/*联合的特点：
	联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的
	大小（因为联合至少得有能力保存最大的那个成员）*/
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

//判断当前计算机的大小存储
//讨论一个数据，放在内存中的存放的字节顺序
//大小端字节序问题
int main() {
	int a = 1;
	if (*(char*)&a == 1) {
		printf("小端\n");
	}
	else {
		printf("大端\n");
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
		printf("小端\n");
	}
	else {
		printf("大端\n");
	}
	return 0;
}

/*联合大小的计算
	1.联合大大小至少是最大成员的大小
	2.当最大成员大小不是最大对齐的整数倍的时候，就要对齐到最大对齐数的整数倍*/
union Un {
	int a;
	char arr[5];
};
int main() {
	union Un u;
	printf("%d\n", sizeof(u));//8
	return 0;
}