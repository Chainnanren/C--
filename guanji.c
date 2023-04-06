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
    printf("你的电脑将在一分钟后关机，如果想要取消关机，请输入woshizhu\n");
    if(strcmp(input,"woshizhu")==0){
    	system("shutdown -a");
    }
    else{
    	goto again;
    }
    return 0;
}