#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
menu()
{
	printf("--------------------\n");
	printf("-----1.开始游戏-----\n");
	printf("-----2.退出游戏-----\n");
	printf("--------------------\n");
}

game()
{
	//棋盘——后台
	char mine[ROWS][COLS] = { 0 };
	//棋盘——玩家
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	init_arr(mine, ROWS, COLS,'0');
	init_arr(show, ROWS, COLS, '*');
	//打印棋盘
	display_arr(show, ROW, COL);
	//display_arr(mine, ROW, COL);
	//放炸弹
	set_mine(mine, ROW, COL);
	//排雷
	set_coordinate(mine, show, ROW, COL);
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请输入选项>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (1);
}