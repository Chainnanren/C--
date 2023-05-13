//C���Գ����Ĵ�����಻������ջ���
//F5�ǿ�ʼ����
// ctrl+F5��ʼִ�У�������
//F10������̵��ԣ��������������뺯��
//F11���������ԣ����Թ۲���Ե�ÿ��ϸ��
//F9�����öϵ��ȡ���ϵ�
//Debug����Ϊ���԰汾�����������bug�İ汾
// Debug�汾����������Ϣ�������Ż�
//Release����Ϊ�����汾��������Ա���Եľ���Release�汾
//Release0�汾�����Ե��ԣ�ֻ���������Ż��������С�������ٶ���Ч������
//char* const p  p��ֵ�����޸ģ���pָ��ı���ֵ���޸�
//char const *p  p��ֵ�����޸ģ���pָ��ı���ֵ�����޸�
//const char* const p  p��ֵ��pָ��ı���ֵ�������޸�



//��������ʹ����ȫ��λ��ż��ǰ��
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
		//�������ż��
		while ((left<right)&&(arr[left] % 2 == 1)) {
			left++;
		}
		//���ұ�������
		while ((left<right)&&(arr[right] % 2 == 0)){
			right--;
		}
		//����������
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