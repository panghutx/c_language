#include<stdio.h>
int main()
{
	int i = 1;
	int x = 0;
	for (i = 1; i <= 5; i++) {
		int j = 1;
		for (j = 1; j <= i; j++) {
			int k = 1;
			for (k = 1; k <= j; k++) {
				x += 5;
				printf("123\n");//35
			}
		}
	}
}
