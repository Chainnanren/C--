/* Note:Your choice is C IDE */
#include "stdio.h"
#include<string.h>
#include<stdlib.h>
void main()
{
    char input[20]={0};
    system("shutdown -s -t 60");
	again:
    scanf("%s",&input);
    printf("��ĵ��Խ���һ���Ӻ�ػ��������Ҫȡ���ػ���������woshizhu\n");
    if(strcmp(input,"woshizhu")==0){
    	system("shutdown -a");
    }
    else{
    	goto again;
    }
    return 0;
}