#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��ʼ������
void init_arr(char arr[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			arr[i][j] = set;
		}
	}
}
//��ӡ����
void display_arr(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡһ���кš��кž��ǵ�����һ�С�
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		//��ӡһ���кš��кž��ǵ�����һ�С�
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

//��ը��
void set_mine(char arr[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while ( count < MINE)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0') {
			arr[x][y] = '1';
			count++;
		}	
	}
}
int howmuch_mine(char mine[ROWS][COLS],int x,int y)
{
	return mine[x][y + 1] + mine[x - 1][y + 1] + mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
//����
void set_coordinate(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//display_arr(mine, ROW, COL);
	int x = 0;
	int y = 0;
	int counts = 0;
	while (counts<(ROW*COL-MINE))
	{
		
		printf("��������>\n");
		scanf("%d %d", &x, &y);
		if (x >=1 || x<=col && y >>1 || y<=col)
		{
			if (show[x][y] == '*') {
				if (mine[x][y] == '1') {
					printf("���ź����㱻ը�ˣ�\n");
					display_arr(mine, ROW, COL);
					break;
				}
				else {
					//����ը����
					int count = howmuch_mine(mine, x, y);
					show[x][y] = count + '0';
					display_arr(show, ROW, COL);
					counts++;


				}
			}
			else {
				printf("�����ѱ�ռ�ã�����������\n");
			}
			
		}
		else {
			printf("����Ƿ�������������");
		}
		

	}
	if (counts == (ROW * COL - MINE)) {
		printf("��ϲ�㣬���׳ɹ�\n");
		display_arr(mine, ROW, COL);
	}
	
}