/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    
    int a=10;
    int* p=&a;//p��ָ�������&a�ǵ�ַ
    //ָ����ǵ�ַ����ַ����ָ��
    //ָ���Ǹ�����������ڴ浥Ԫ�ĵ�ַ 
    return 0;
}
/*ָ�����;�����ָ����н����ò�����ʱ���ܹ�����
�ռ�Ĵ�С
int* p��*p�ܹ�����4���ֽ�
char* p��*p�ܹ�����1���ֽ�
double* p��*p�ܹ�����8���ֽ�*/
int main(){
	int a=0x11223344;
	//int* pa=&a;
	//*pa=0;
	char* pc=&a;
	pa=0;
	return 0;
}
//ָ�����;����ˣ�ָ����һ���߶�Զ��ָ��Ĳ�����
int main(){
	int a=0x11223344;
	int* pa=&a
	char* pc=&a;
	printf("%p\n",pa);
	printf("%p\n",pa+1);
	
	printf("%p\n",pc);
	printf("%p\n",pc+1);
	return 0;
}
//Ұָ��
int main(){
	//ָ��δ��ʼ��
	int a=0;//�ֲ���������ʼ����Ĭ�������ֵ
	int *p;//�ֲ���ָ��������ͱ���ʼ�����ֵ
	*p=20;
	
	//ָ��Խ�����
	int arr[10]={0};
	int *p=arr;
	int i=0;
	for(i=0;i<12;i++){
		p++;
		}
	return 0;	
}
//ָ��ָ��Ŀռ��ͷ�
int* test(){
	int a=0;
	return &a;
	}
int main(){
	int *p=test();
	*p=20;
	return 0;
}
/*��α���Ұָ��
1.ָ���ʼ��(��֪������ʲôֵʱ������ָ�루NULL��)
2.С��ָ��Խ��
3.ָ��ָ��ռ��ͷ�
4.ָ��ʹ��֮ǰ�����Ч��*/
1.
	int main(){
		int a=10;
		int* pa=&a;
		int* p=NULL;
		return 0;
	}
3.
	 int main(){
		int a=10;
		int *pa=&a;
		*pa=20;
		pa=NULL;
		return 0;
	 }
//ָ������
//ָ��+-����
int main(){
	int arr[10]={0};
	int i=0;
	int sz=sizeof(arr)/sizeof(arr[0]);
	int* p=arr;
	/*for(i=0;i<se;i++){
		printf("%d",*p);
		p=p+1;
		return 0;
		} */
	for(i=0;i<5;i++){
		printf("%d",*p);
		p+=2;
		}
	return 0;
}
int main(){
	int arr[10]={0};
	int i=0;
	int sz=sizeof(arr)/sizeof(arr[0]);
	int* p=&arr[9];
	/*for(i=0;i<se;i++){
		printf("%d",*p);
		p=p+1;
		return 0;
		} */
	for(i=0;i<5;i++){
		printf("%d",*p);
		p-=2;
		}
	return 0;
}
#define N_VALUES 5
int main(){
	float values[N_VALUES];
	float *vp;
	for(vp=&values[0];vp<&values[N_VALUES];){
		*vp++=0;
		}
	}
//ָ��-ָ��
int main(){
	char ch[5]={0};
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",&arr[9]-arr[0]);//9
	printf("%d\n",&arr[9]-arr[0]);//-9
	printf("%d\n",&arr[9]-&ch[0]);//err
	return 0;
}
//strlen-�ַ�������
	int my_strlen(char* str){
	char* star=str;
	char* end=str;
	while(*end!='\0'){
		end++;
	}
	return end-star;
}
int main()
{
    char arr[]="bit";
	int len=my_strlen(arr);
	printf("%d\n",len);
	return 0;
}
//ָ��Ĺ�ϵ����
#define N_VALUES 5
int main(){
	float values[N_VALUES];
	float *vp;
	for(vp=&values[N_VALUES];vp.&values[0];){
		*--vp=0;
	return 0;
	}
}
//ָ�������
int main(){
	int arr[10]={0};
	printf("%p\n",arr);//8E0
	printf("%p\n",arr+1);//��Ԫ�صĵ�ַ-8E4
	
	printf("%p\n",&arr[0]);//8E0
	printf("%p\n",&arr[0]+1);//8E4
	
	printf("%p\n",&arr);//8E0
	printf("%p\n",&arr+1);//908
	return 0;
}
int main(){
	int arr[10]={0};
	int* p=arr;
	int i=0;
	for(i=0;i<10;i++){
		//�����ͬ
		printf("%p ====== %p\n",p+i,&arr[i]);
		}
	return 0;
}
//����ָ��
int main(){
	int a=10;
	int* pa=&a;//һ��ָ��
	int** ppa=&pa;//����ָ��
	//ppa��ָ�룬ppaָ���ָ��������int*
	printf("%d\n",**ppa);
	return 0;
}
//ָ������-����
//����ָ��-ָ��
int main(){
	/*int a=10;
	int b=20;
	int c=30;
	int* pa=&a;
	int* pb=&b;
	int* pc=&c;
	*/
	//int arr[10];
	int* arr2[3]={&a,&b,&c};//ָ������
	int i=0;
	for(i=0;i<3;i++){
		printf("%d \n",*(arr2[i]));
		}
	return 0;
	}

	
	
	
	
	
	
	
	
	





