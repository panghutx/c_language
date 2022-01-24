#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("-----------------------\n");
	printf("--------1.Start--------\n");
	printf("---------2.End---------\n");
	printf("-----------------------\n");
}
void game()
{
	char rst = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1) {
		//�������
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		rst = isWinner(board,ROW,COL);
		if (rst != 'C') {
			break;
		}
		//��������
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		rst = isWinner(board, ROW, COL);
		if (rst != 'C') {
			break;
		}

	}
	if (rst == '*') {
		printf("��ϲ�㣬Ӯ����ʤ����\n");
	}
	else if (rst == '#') {
		printf("���ź��������ˣ�\n");
	}
	else {
		printf("ƽ����\n");
	}

//����*  ���Ӯ
//����#  ����Ӯ
//����Q  ƽ��
//����C  ����
	
}
int main()
{
	menu();
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		printf("������ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			break;
		default:
			break;
		}

	} while (input);
}