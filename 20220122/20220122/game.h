#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

//��ʼ�����̵�
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL],int row,int col);
//�������
void player_move(char board[ROW][COL], int row, int col);
//��������
void computer_move(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char isWinner(char board[ROW][COL], int row, int col);