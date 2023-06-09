//fgets函数
#include<stdio.h>
int main() {
	char buf[1024] = { 0 };
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//读文件
	fgets(buf, 1024, pf);
	printf("%s", buf);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//fputs函数
#include<stdio.h>
int main() {
	char buf[1024] = { 0 };
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//写文件
	fputs("hello\n",pf);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);//从标准输入流读取
	fputs(buf, stdout);//输出到标准输出流
	return 0;
}

//fprintf函数
struct S {
	int n;
	float score;
	char arr[10];
};
int main() {
	struct S s = { 100,3.14,"bit" };
	FILE* pf = fopen("text,txt", "w");
	if (pf == NULL) {
		return 0;
	}
	//格式化的形式写
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}

//fscanf函数
int main() {
	struct S s = { 100,3.14,"bit" };
	FILE* pf = fopen("text,txt", "r");
	if (pf == NULL) {
		return 0;
	}
	//格式化的形式输入数据
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
	printf("%d %f %s\n", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}

int main() {
	struct S s = { 100,3.14,"bit" };
	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
	return 0;

}

//sprintf和sscanf
struct S s {
	int n;
	float score;
	char arr[10];
};
int main() {
	struct S s = { 100,3.14,"abcdef" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };
	//把格式化的数据转化成字符串存储到buf中
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
	printf("%s\n", buf);
	//从buf中读取格式化的数据到tmp中
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
	return 0;
}


/*scanf/printf 是针对标准输入流/标准输出流的格式化输入/输出
  fscanf/fprintf 是针对所有输入流/所有输出流的格式化输入/输出语句

  sscanf/sprintf  sscanf是从字符串中读取格式化的数据
				  sprintf是把格式化数据输出成字符串*/



//fread和fwrite函数
struct S {
	char name[20];
	int age;
	double score;
};
int main() {
	struct S s = { "张三",20,55.6 };
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL) {
		return 0;
	}
	//二进制的形式写文件
	fwrite(&s, sizeof(struct S), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}


struct S {
	char name[20];
	int age;
	double score;
};
int main() {
	struct S tmp = { 0 };
	FILE* pf = fopen("text.txt", "wb");
	if (pf == NULL) {
		return 0;
	}
	//二进制的形式读文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;
	return 0;
}