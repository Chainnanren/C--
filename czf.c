/* Note:Your choice is C IDE */
//��Ŀ������
#include "stdio.h"
void main()
{
    int a=10;
    //!���߼������������ٱ��棬����
    printf("%d\n",!a);
    //ȡ��ַ������
    int* p=&a;
    //�����ò�����
    //ͨ��p�д�ŵ�ֵ�ҵ�����ָ��Ķ���
    *p=20;
    //sizeof���������ռ�ڴ�ռ�Ĵ�С����λ���ֽ�
    /*sizeof�����Ǳ�������ʡ������
    		���������Ͳ���ʡ��*/
    int a=10;
    char c='r';
    char* p=&c;
    int arr[10]={0};
    printf("%d\n",sizeof(a));//4
     printf("%d\n",sizeof(int));//4
     
    printf("%d\n",sizeof(c));//1
     printf("%d\n",sizeof(char));//1
     
    printf("%d\n",sizeof(p));//4��8
     printf("%d\n",sizeof(char*));//4��8
     
     //����������˵ȥ���������������������
    printf("%d\n",sizeof(arr));//40
     printf("%d\n",sizeof(int [10]));//40
    return 0;
}
int main(){
	//~���������ƣ�λȡ��
	int a=0;
	printf("%d\n",~a);
	int a=11;
	a=a|(1<<2);
	printf("%d\n",a);//15
	a=a&(~1<<2);
	printf("%d\n",a);//11
}
int main(){
	int a=10;
	printf("%d",++a);//ǰ��++����++����ʹ��
	printf("%d",a++);//����++����ʹ�ã���++
}
int main(){
	int a=(int)3.14;//ǿ��ת����int����
}
//��Ŀ��������������������
//exp1?exp2:exp3
int main(){
	int a=0;
	int b=0;
	if(a>5)
	b=3;
	else
	b=-3;
	b=(a>5?3:-3);
	
	int a=10;
	int b=20;
	int max=0;
	if(a>b)
	max=a;
	else
	max=b;
	max=a>b?a:b;
	
	return 0;
}
//���ű��ʽ
//exp1,exp2,exp3,exp4......expN;
int main(){
	//����1
	int a=1;
	int b=2;
	int c=(a>b,a=b+10,a,b=a+1);
	printf("%d\n",c);
	//c����13
	//����2
	if(a=b+1,c=a/2,d>0);
	//����3
	a=get_val();
	count_val(a);
	while(a>0){
		a=get_val();
		count_val(a);
	}
	//ʹ�ö��ű��ʽ����д:
	while(a=get_val(),count_val(a),a>0){
		//ҵ����
		}
	return
	 0;
}
//�������ò�����
int get_max(int x,int y){
	return x>y?x:y;
	}
int main(){
	int a=0;
	int b=0;
	//���ú�����ʱ��()���Ǻ������ò�����
	int max=get_max(a,b);
	printf("max=%d\n",max);	
	return 0;
}
//����һ���ṹ������ ������-struct stu 
//ѧ��
struct stu{
	char name[20];
	int age;
	char id[20];
	}
int main(){
	int a=10;
	//ʹ��struct stu������ʹ�����һ��ѧ������s1������ʼ��
	struct stu s1={"����",20,"22219010234"};
	struct stu* ps=&s1;
	//�ṹ��ָ��->��Ա��
	printf("%s\n",ps->name);
	printf("%s\n",(*ps).name);
	/*printf("%s\n",s1.name);
	printf("%d\n",s1.age);
	printf("%s\n",s1.id);*/
	//�ṹ�����.��Ա��
	return 0;
}
//���ʽ��ֵ
//����ת�� ��������
int main(){
	char a=3;
	//000000000000000000000011
	//00000011-a
	char b=127;
	//000000000000000001111111
	//01111111-b
	
	//a��b������
	//000000000000000000000011
	//000000000000000001111111
	//000000000000000010000010
	char c=a+b;
	//10000010
	//111111111111111110000010-����
	//111111111111111110000001-����
	//100000000000000001111110-ԭ��
	printf("%d\n",c);
	return 0;
}
