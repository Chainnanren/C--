/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    
    int a=10;
    int* p=&a;//p是指针变量，&a是地址
    //指针就是地址，地址就是指针
    //指针是个变量，存放内存单元的地址 
    return 0;
}
/*指针类型决定了指针进行解引用操作的时候，能够访问
空间的大小
int* p：*p能够访问4个字节
char* p：*p能够访问1个字节
double* p：*p能够访问8个字节*/
int main(){
	int a=0x11223344;
	//int* pa=&a;
	//*pa=0;
	char* pc=&a;
	pa=0;
	return 0;
}
//指针类型决定了：指针走一步走多远（指针的步长）
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
//野指针
int main(){
	//指针未初始化
	int a=0;//局部变量不初始化，默认是随机值
	int *p;//局部的指针变量，就被初始化随机值
	*p=20;
	
	//指针越界访问
	int arr[10]={0};
	int *p=arr;
	int i=0;
	for(i=0;i<12;i++){
		p++;
		}
	return 0;	
}
//指针指向的空间释放
int* test(){
	int a=0;
	return &a;
	}
int main(){
	int *p=test();
	*p=20;
	return 0;
}
/*如何避免野指针
1.指针初始化(不知道给赋什么值时，给空指针（NULL）)
2.小心指针越界
3.指针指向空间释放
4.指针使用之前检查有效性*/
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
//指针运算
//指针+-整数
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
//指针-指针
int main(){
	char ch[5]={0};
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",&arr[9]-arr[0]);//9
	printf("%d\n",&arr[9]-arr[0]);//-9
	printf("%d\n",&arr[9]-&ch[0]);//err
	return 0;
}
//strlen-字符串长度
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
//指针的关系运算
#define N_VALUES 5
int main(){
	float values[N_VALUES];
	float *vp;
	for(vp=&values[N_VALUES];vp.&values[0];){
		*--vp=0;
	return 0;
	}
}
//指针和数组
int main(){
	int arr[10]={0};
	printf("%p\n",arr);//8E0
	printf("%p\n",arr+1);//首元素的地址-8E4
	
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
		//结果相同
		printf("%p ====== %p\n",p+i,&arr[i]);
		}
	return 0;
}
//二级指针
int main(){
	int a=10;
	int* pa=&a;//一级指针
	int** ppa=&pa;//二级指针
	//ppa是指针，ppa指向的指针类型是int*
	printf("%d\n",**ppa);
	return 0;
}
//指针数组-数组
//数组指针-指针
int main(){
	/*int a=10;
	int b=20;
	int c=30;
	int* pa=&a;
	int* pb=&b;
	int* pc=&c;
	*/
	//int arr[10];
	int* arr2[3]={&a,&b,&c};//指针数组
	int i=0;
	for(i=0;i<3;i++){
		printf("%d \n",*(arr2[i]));
		}
	return 0;
	}

	
	
	
	
	
	
	
	
	





