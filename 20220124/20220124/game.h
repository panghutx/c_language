#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9
#define MINE 10

//��ʼ������
void init_arr(char arr[ROWS][COLS], int rows, int cols,char set);
//��ӡ����
void display_arr(char arr[ROWS][COLS], int row, int col);
//��ը��
void set_mine(char arr[ROWS][COLS], int row, int col);
//����
void set_coordinate(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
