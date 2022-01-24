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
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1) {
		//玩家下棋
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		rst = isWinner(board,ROW,COL);
		if (rst != 'C') {
			break;
		}
		//电脑下棋
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		rst = isWinner(board, ROW, COL);
		if (rst != 'C') {
			break;
		}

	}
	if (rst == '*') {
		printf("恭喜你，赢得了胜利！\n");
	}
	else if (rst == '#') {
		printf("很遗憾，你输了！\n");
	}
	else {
		printf("平局了\n");
	}

//返回*  玩家赢
//返回#  电脑赢
//返回Q  平局
//返回C  继续
	
}
int main()
{
	menu();
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		printf("请输入选项\n");
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