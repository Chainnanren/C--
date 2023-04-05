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
//布置雷
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
		printf("请输入排查雷的坐标");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 &&y<=col){
			if(mine[x][y]=='1'){
				printf("你已经被炸死了\n");
				DisplayBoard(mine,ROW,COL);
				break;
			}
			else 
			{
			//计算下x,y轴周围有几课雷
			int count=get_count(mine,x,y);
			show[x][y]=count+'0';
			DisplayBoard(show,row,col);     
			win++;  
			}
		}
		else{
			  ("输入非法坐标，请重新输入\n");
			}
	}
	if(win==row*col-EASY_COUNT){
		printf("恭喜你排雷成功\n");
		}
}
void game(){
	//布置好的雷的信息
	char mine[ROWS][COLS]={0};
	//排查出的雷的信息
	char show[ROWS][COLS]={0};
	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
	//扫雷
	FindMine(mine,show,ROW,COL);
	//判断周围八个棋子有没有雷
	}
void test(){
	int input=0;
		srand((unsigned int)time(NULL));
		do{
		menu();
		printf("请选择\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
			game();
			break;
			case 0:
			printf("退出游戏\n");
			break;
			default:
			printf("选择错误，重新选择\n");
			break;
			}
		}while(input);
	
	}
int main()
{
 test();
 return 0;   
}