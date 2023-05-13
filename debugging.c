//C语言常见的错误分类不包括：栈溢出
//F5是开始调试
// ctrl+F5开始执行，不调试
//F10是逐过程调试，遇到函数不进入函数
//F11是逐语句调试，可以观察调试的每个细节
//F9是设置断点和取消断点
//Debug被称为调试版本，程序调试找bug的版本
// Debug版本包含调试信息，不做优化
//Release被称为发布版本，测试人员测试的就是Release版本
//Release0版本不可以调试，只是往往会优化，程序大小和运行速度上效果最优
//char* const p  p的值不可修改，但p指向的变量值可修改
//char const *p  p的值可以修改，但p指向的变量值不可修改
//const char* const p  p的值和p指向的变量值都不可修改



//调整数组使奇数全部位于偶数前面
void print(int arr[],int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d\n", arr[i]);
	}
	printf("\n");
}
void move(int arr[], int sz) {
	int left = 0;
	int right = sz - 1;
	while (left < right) {
		//从左边找偶数
		while ((left<right)&&(arr[left] % 2 == 1)) {
			left++;
		}
		//从右边找奇数
		while ((left<right)&&(arr[right] % 2 == 0)){
			right--;
		}
		//两边数交换
		if (left < right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr,sz);
	print(arr, sz);
	return 0;
}