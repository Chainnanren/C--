//freeֻ�����ͷſռ䣬�����ָ�������ΪNULL
//32λϵͳ���κ�����ָ��ĳ��ȶ���4���ֽ�
//ָ�������������������ָ��ʵ��ָ�����ݵ���������
//Ұָ����ָδ��������Ѿ��ͷŵ��ڴ��ַ
//����ָ����һ��ָ�룬��һ��ָ�������ָ��
//ָ��������һ������

//����һ������ָ�룬ָ��ĺ���������int�ββ��ҷ���һ������ָ�룬���ص�ָ��
//ָ��һ����һ��int�β��ҷ���int�ĺ���   int(*(*F)(int,int))(int)
//һ������Ϊint*������ֵΪint�ĺ���ָ�룺int(*fun)( int*)
int main() {
	char str1[] = "hello bit";
	char str2[] = "hello bit";
	char* str3[] = "hello bit";
	char* str4[] = "hello bit";
	if (str1 ==str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4) 
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	//str1������str2  ��ַ�����
	//str3����str4    ȫ��ָ��hello bit����ĸ�ĵ�ַ
	return 0;
}


//ʵ��һ�����������������ַ����е�k���ַ�
/*���磺
		ABCD����һ���ַ��õ�BCDA
		ABCD���������ַ��õ�CDAB*/

//����1��
#include<stdio.h>
#include<string.h>
void left_move(char arr[],int k) {
	int letf = 0;
	int right = 0;
	int i = 0;
	int len = strlen(arr);
	k %= len;
	for (i = 0; i<k; i++) {
		//��תһ���ַ�
		char tmp = arr[0];
		//��ʣ�µ��ַ���ǰ�ƶ�
		int j = 0;
		for (j = 0; j < len; j++) {
			arr[j] = arr[j + 1];
		}
		//���ַ��ŵ����
		arr[len-1] = tmp; 
	}

}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr,k);
	printf("%s\n", arr);
	return 0;
}

//����2��
#include<assert.h>
void reverse(char* left, char* right) {
	assert(left && right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k) {
	int len = strlen(arr);
	k %= len;
	//Ҫ�������ַ�
	reverse(arr, arr + k - 1);
	//����Ҫ�������ַ�
	reverse(arr + k, arr + len - 1);
	//��������
	reverse(arr, arr + len - 1);
}
int main() {
	char arr[] = "ABCDEF";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}


//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ���d�ģ�
//���д�����������ľ����в���ĳ�������Ƿ����
//��ʱ�临�Ӷ�С��o(N)
//o(N)����������Ҫ��n�β����ҵ�������
struct Point {
	int x;
	int y;
};
struct Point find_num(int arr[3][3], int r, int c, int k) {
	int x = 0;
	int y = c - 1;
	struct Point p = { -1,-1 };
	while (x <= r - 1 && y >= 0) {
		if (k < arr[x][y]) {
			y--;
		}
		else if (k > arr[x][y]) {
			x++;
		}
		else {
			p.x = x;
			p.y = y;
			return p;
		}
	}
	return p;//�Ҳ���
}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;
	scanf("%d", &k);
	struct Point ret = find_num(arr, 3, 3, k);
	printf("%d %d\n", ret.x,ret.y);
	return 0;
}


//����2��
//�����Ͳ���
#include<stdio.h>
int find_num(int arr[3][3], int *px, int *py, int k) {
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0) {
		if (k < arr[x][y]) {
			y--;
		}
		else if (k > arr[x][y]) {
			x++;
		}
		else {
			*px = x;
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;//�Ҳ���
}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 0;;
	scanf("%d", &k);
	int a = 3;//��
	int b = 3;//��
	int ret = find_num(arr, &a, &b, k);
	if (ret == 1) {
		printf("%d %d\n", a, b);
	}
	else
		printf("�Ҳ���\n");
	return 0;
}