//����ָ�����������һ��ָ���ַ��
//����ָ���С��32λƽ̨��4���ֽ� 64λƽ̨��8���ֽ�
//����ָ��+1���ƫ��һ������
//ָ�� - ָ��õ�����ָ���ָ��֮���Ԫ�ظ���
//ָ������Ҫ������������С
int main() {
	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	unsigned long* pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
	return 0;
}
//6 12


//дһ����������������һ���ַ���������
#include<stdio.h>
#include<string.h>
#include<assert.h>
void BackWard(char* str) {
	assert(str);
	char* left = str;
	int len = strlen(str);
	char* right = str + len - 1;
	while (left<right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
int main() {
	char arr[256] = { 0 };
	scanf("%s", &arr);//���ܶ�ȡ�ո�
	gets(arr);//��ȡһ�У�����ע�ո�
	//������
	BackWard(arr);
	printf(" % s\n", arr);
	return 0;
}




//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ����֮�ͣ�����a��һ������
int main() {
	int a = 0;
	int n = 0;
	int sum = 0;
	int i = 0;
	int ret = 0;
	scanf("%d%d", &a, &n);
	for (i = 0; i < n; i++) {
		ret = ret * 10 + a;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}



//�ж�ˮ�ɻ���
#include<math.h>
int main() {
	int i = 0;
	for (i = 0; i <= 100000; i++) {
		//�ж�i�Ƿ�Ϊˮ�ɻ���(������)
		//1.����i��λ��
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp /= 10) {
			n++;
		}
		//2.����i��ÿһλ��n�η�֮��
		tmp = i;
		while (tmp) {
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//3.�Ƚ�i��sum
		if (i == sum) {
			printf("%d ", i);
		}


	}
	return 0;
}



//��C��������Ļ�����һ�����ε�ͼ��
#include<stdio.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++) {
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j < line - 1 - i; j++) {
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");

	}
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++) {
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}



