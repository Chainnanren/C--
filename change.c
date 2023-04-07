/* Note:Your choice is C IDE */
//加减法
//弊端：数值可能超过整形最大值(可能会溢出)
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
//异或的方法
#include<stdio.h>
int main(){
	  int a=3;
	  int b=5;
	  a=a^b;
	  b=a^b;
	  a=a^b;
	  printf("%d,%d",a,b);
}
//求一个整数存储在内存中的二进制1的个数
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