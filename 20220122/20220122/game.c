#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//��ʼ�����̵�
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
//��ӡ����
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
//�������
void player_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	
	while (1) {
		printf("�������>\n");
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col) {
			printf("����Ƿ�\n");
		}
		else {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
		}

	}
	
}

//��������
void computer_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("��������\n");
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
//�ж���Ӯ
char isWinner(char board[ROW][COL], int row, int col)
{

	//�ж���
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//�ж���
	int j = 0;
	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
		return board[1][1];
	}
	//�ж�ƽ��
	if (isPeace(board, row, col) == 1) {
		return 'Q';
	}
	else {
		return 'C';
	}
}
