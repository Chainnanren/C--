   /* Note:Your choice is C IDE */
#define ROW 3
#define COL 3
#define _CRT_SECURE_NO_WARNINGS 1
//����������
#include "stdio.h"
#include<time.h>
#include<stdlib.h>
//��������
void InitBoard(int board[ROW][COL],int row,int col);
void DisplayBoard(int board[ROW][COL],int row,int col);
void PlayMove(int board[ROW][COL],int row,int col);
void ComputerMove(int board[ROW][COL],int row,int col);
/*������̬
���Ӯ��'*'
����Ӯ��'#'
������'Q'
ƽ�֡�'C'
*/
char IsWin(char board[ROW][COL],int row,int col);
void menu(){
	printf("***************\n");
	printf("********1.play 0.exit*****\n");
	printf("*******************\n");
}
//��Ϸ������ʵ��
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
//�����
void PlayMove(int board[ROW][COL],int row,int col){
	int x=0;
	int y=0;
	printf("�����\n");
	while(1){
	scanf("%d%d",&x,&y);
	if(x>=1&&x<=row&&y>=1&&y<=col){
		if(board[x-1][y-1]==' '){
			board[x-1][y-1]='*';
			break;	
		}
		else{
			printf("��λ���ѱ�ռ��\n");
			}
	
	}
	else
	{
		printf("����������\n");
		}
	}
}
//������
void ComputerMove(int board[ROW][COL],int row,int col){
	int x=0;
	int y=0;
	printf("������\n");
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
//�жϽ��
char IsWin(char board[ROW][COL],int row,int col){
	int i=0;
	//����
	for(i=0;i<row;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' '){
			return board[i][1];
			}
	}
	//����
	for(i=0;i<col;i++){
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' '){
			return board[1][i];
			}
	}
	//�Խ���
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
		return board[1][1];
	if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[1][1]!=' ')
		return board[1][1];

	//�ж��Ƿ�ƽ��
	if(1==IsFull(board,ROW,COL)){
	return 'Q';
	}
	return 'C';
}
void game(){
	char ret=0;
	int board[ROW][COL]={0};
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while(1){
		//�������
		PlayMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//�ж�����Ƿ�Ӯ
  		ret=IsWin(board,ROW,COL);
		if(ret!='C'){
			break;
			}
		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//�жϵ����Ƿ�Ӯ
		ret=IsWin(board,ROW,COL);
		if(ret!='C'){
			break;
		}
	}
		 if(ret=='*')
		{
			printf("���Ӯ\n");
		}
		else if(ret=='#'){
			printf("����Ӯ\n");
			}
	else{
		printf("ƽ��\n");
	}
	}
void test(){
	int input=0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch(input){
			case 1:
			game();
			break;
			case 0:
			printf("��Ϸ����\n");
			break;
			default:
			printf("ѡ����������ѡ��\n");
			break;
			}
			
		}while(input);
	}
int main()
{
 test();
 return 0;   
}