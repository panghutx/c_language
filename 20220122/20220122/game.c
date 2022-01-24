#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//初始化棋盘的
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++)
			{

				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
}
//玩家下棋
void player_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	
	while (1) {
		printf("玩家下棋>\n");
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col) {
			printf("坐标非法\n");
		}
		else {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
		}

	}
	
}

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑下棋\n");
	while(1)
	{
		x = rand() % row;
		y = rand() % col;
		if(board[x][y] == ' ') {

			board[x][y] = '#';
			break;
	}
	}
}
int isPeace(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
		return 1;
	}
}
//判断输赢
char isWinner(char board[ROW][COL], int row, int col)
{

	//判断行
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//判断列
	int j = 0;
	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
		return board[1][1];
	}
	//判断平局
	if (isPeace(board, row, col) == 1) {
		return 'Q';
	}
	else {
		return 'C';
	}
}
