/* Note:Your choice is C IDE */
//�Ӽ���
//�׶ˣ���ֵ���ܳ����������ֵ(���ܻ����)
#include "stdio.h"
void main()
{
    int a=3;
    int b=5;
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d,%d",a,b);
}
//���ķ���
#include<stdio.h>
int main(){
	  int a=3;
	  int b=5;
	  a=a^b;
	  b=a^b;
	  a=a^b;
	  printf("%d,%d",a,b);
}
//��һ�������洢���ڴ��еĶ�����1�ĸ���
#include "stdio.h"
void main()
{
     int num=0;
     int count=0;
     int i=0;
     scanf("%d",&num);
     for(i=0;i<32;i++){
     	if((num>>i)&1==1)
     	count++;
     }
     printf("%d\n",count);
 }