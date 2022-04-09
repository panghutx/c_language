#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	char arr[100] = { 0 };
//	FILE* pFile;
//	//打开文件
//	pFile = fopen("myfile.txt", "r");
//	//文件操作
//	fgets(arr, 30, pFile);
//	printf("%s", arr);
//	//fputs("fopen example", pFile);
//	//关闭文件
//	fclose(pFile);
//	
//	return 0;
//}

/* fgetc example: % counter */
//#include <stdio.h>
//int main()
//{
//	FILE* pFile;
//	int c;
//	int n = 0;
//	pFile = fopen("myfile.txt", "r");
//	if (pFile == NULL) perror("Error opening file");
//	else
//	{
//		do {  //读取文件中%符号的个数
//			c = fgetc(pFile);
//			if (c == '%') n++;
//		} while (c != EOF);
//		fclose(pFile);
//		printf("The file contains %d dollar sign characters (%).\n", n);
//	}
//	return 0;
//}

int main()
{
	FILE* pf = fopen("myfile.txt", "r");
	if (pf == NULL) perror("Error opening file");
	int c = 0;

	do 
	{
		c = fgetc(pf);
		printf("%c", c);
	} while (c!=EOF);
}