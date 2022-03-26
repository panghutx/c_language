#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

//对接口进行测试

int main(void)
{
    SqList newList;
    ElemType e;

    InitList(&newList);

    ListInsert(&newList, 1, 5);
    ListInsert(&newList, 2, 10);
    ListInsert(&newList, 3, 1);
    ListInsert(&newList, 4, 90);
    ListInsert(&newList, 5, 15);
    ListInsert(&newList, 6, 123);
    
    printSqList(&newList);
    printf("===========\n");

    ListDelet(&newList, 4, &e);
    printSqList(&newList);
    printf("===========\n");

    ListInsert(&newList, 6, 1111);
    printSqList(&newList);
    printf("===========\n");


    ListChange(&newList, 1, 0);
    printSqList(&newList);
    printf("===========\n");


    return 0;
}


