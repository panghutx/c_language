#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
menu()
{
	printf("--------------------\n");
	printf("-----1.��ʼ��Ϸ-----\n");
	printf("-----2.�˳���Ϸ-----\n");
	printf("--------------------\n");
}

game()
{
	//���̡�����̨
	char mine[ROWS][COLS] = { 0 };
	//���̡������
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	init_arr(mine, ROWS, COLS,'0');
	init_arr(show, ROWS, COLS, '*');
	//��ӡ����
	display_arr(show, ROW, COL);
	//display_arr(mine, ROW, COL);
	//��ը��
	set_mine(mine, ROW, COL);
	//����
	set_coordinate(mine, show, ROW, COL);
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("������ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (1);
}