#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 80
#include "stdio.h"
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisplayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row,int col);
void FineMine(char board[ROWS][COLS],int row,int col);
void menu(){
	printf("*********************\n");
	printf("********1.play*******\n");
	printf("********0.exit*******\n");
	printf("*********************\n");
}
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set){
	int i=0;
	int j=0;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			board[i][j]=set;
		}
		}	
	
}
void DisplayBoard(char board[ROWS][COLS],int row,int col){
	int i=0;
	int j=0;
	for(i=0;i<=row;i++){
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++){
		printf("%d ",i);
		for(j=1;j<=col;j++){
			printf("%c ",board[i][j]);
			}
			 printf("\n");
	}
}
//������
void SetMine(char board[ROWS][COLS],int row,int col){
	int count= EASY_COUNT;
	while(count){
		int x=rand()%row+1;//1-9
		int y=rand()%col+1;//1-9
		if(board[x][y]=='0'){
			board[x][y]='1';
			count--;
			}
		}
	
}
int get_count(char mine[ROWS][COLS],int x,int y){
		return mine[x-1][y]+
		mine[x-1][y+1]+
		mine[x-1][y-1]+
		mine[x][y-1]+
		mine[x][y+1]+
		mine[x+1][y+1]+
		mine[x+1][y-1]+
		mine[x+1][y]-8*'0';
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){
	int x=0;
	int y=0;
	int win=0;
	while(win<row*col-EASY_COUNT){
		printf("�������Ų��׵�����");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 &&y<=col){
			if(mine[x][y]=='1'){
				printf("���Ѿ���ը����\n");
				DisplayBoard(mine,ROW,COL);
				break;
			}
			else 
			{
			//������x,y����Χ�м�����
			int count=get_count(mine,x,y);
			show[x][y]=count+'0';
			DisplayBoard(show,row,col);     
			win++;  
			}
		}
		else{
			  ("����Ƿ����꣬����������\n");
			}
	}
	if(win==row*col-EASY_COUNT){
		printf("��ϲ�����׳ɹ�\n");
		}
}
void game(){
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS]={0};
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS]={0};
	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//������
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
	//ɨ��
	FindMine(mine,show,ROW,COL);
	//�ж���Χ�˸�������û����
	}
void test(){
	int input=0;
		srand((unsigned int)time(NULL));
		do{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
			game();
			break;
			case 0:
			printf("�˳���Ϸ\n");
			break;
			default:
			printf("ѡ���������ѡ��\n");
			break;
			}
		}while(input);
	
	}
int main()
{
 test();
 return 0;   
}