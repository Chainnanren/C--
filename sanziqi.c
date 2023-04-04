   /* Note:Your choice is C IDE */
#define ROW 3
#define COL 3
#define _CRT_SECURE_NO_WARNINGS 1
//测试三子棋
#include "stdio.h"
#include<time.h>
#include<stdlib.h>
//函数声明
void InitBoard(int board[ROW][COL],int row,int col);
void DisplayBoard(int board[ROW][COL],int row,int col);
void PlayMove(int board[ROW][COL],int row,int col);
void ComputerMove(int board[ROW][COL],int row,int col);
/*四种形态
玩家赢—'*'
电脑赢—'#'
继续—'Q'
平局—'C'
*/
char IsWin(char board[ROW][COL],int row,int col);
void menu(){
	printf("***************\n");
	printf("********1.play 0.exit*****\n");
	printf("*******************\n");
}
//游戏的整个实现
void InitBoard(int board[ROW][COL],int row,int col){
	int i=0;
	int j=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			board[i][j]=' ';
			}	
		}
}
void DisplayBoard(int board[ROW][COL],int row,int col){
	int i=0;
	for(i=0;i<row;i++){
		int j=0;
		for(j=0;j<col;j++){
			printf(" %c ",board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if(i<row-1)
		printf("---|---|---\n");
	}
}
//玩家走
void PlayMove(int board[ROW][COL],int row,int col){
	int x=0;
	int y=0;
	printf("玩家走\n");
	while(1){
	scanf("%d%d",&x,&y);
	if(x>=1&&x<=row&&y>=1&&y<=col){
		if(board[x-1][y-1]==' '){
			board[x-1][y-1]='*';
			break;	
		}
		else{
			printf("该位置已被占用\n");
			}
	
	}
	else
	{
		printf("请重新输入\n");
		}
	}
}
//电脑走
void ComputerMove(int board[ROW][COL],int row,int col){
	int x=0;
	int y=0;
	printf("电脑走\n");
	while(1){
		x=rand()%row;
		y=rand()%col;
		if(board[x][y]=' '){
			board[x][y]='#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL],int row,int col){
	int i=0;
	int j=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
		{
			if(board[i][j]=' ')
			return 0;
			} 
	}
	return 1;
	}
//判断结果
char IsWin(char board[ROW][COL],int row,int col){
	int i=0;
	//横三
	for(i=0;i<row;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' '){
			return board[i][1];
			}
	}
	//竖三
	for(i=0;i<col;i++){
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' '){
			return board[1][i];
			}
	}
	//对角线
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
		return board[1][1];
	if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[1][1]!=' ')
		return board[1][1];

	//判断是否平局
	if(1==IsFull(board,ROW,COL)){
	return 'Q';
	}
	return 'C';
}
void game(){
	char ret=0;
	int board[ROW][COL]={0};
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while(1){
		//玩家下棋
		PlayMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断玩家是否赢
  		ret=IsWin(board,ROW,COL);
		if(ret!='C'){
			break;
			}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断电脑是否赢
		ret=IsWin(board,ROW,COL);
		if(ret!='C'){
			break;
		}
	}
		 if(ret=='*')
		{
			printf("玩家赢\n");
		}
		else if(ret=='#'){
			printf("电脑赢\n");
			}
	else{
		printf("平局\n");
	}
	}
void test(){
	int input=0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择\n");
		scanf("%d",&input);
		switch(input){
			case 1:
			game();
			break;
			case 0:
			printf("游戏结束\n");
			break;
			default:
			printf("选择错误，请继续选择\n");
			break;
			}
			
		}while(input);
	}
int main()
{
 test();
 return 0;   
}