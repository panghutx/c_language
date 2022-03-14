#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//打印空*
int main1()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    for (i = 1; i <= n; i++) {
        int j = 1;
        for (j = 1; j <= i; j++) {
            if (i >= 2 && i < n && j>1 && j < i) {
                printf("  ");
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }
    
}

//合并有序序列
int main()
{
    int m, n = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    int arr1[100] = { 0 };
    int arr2[100] = { 0 };
    int arr3[100] = { 0 };
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    int a = 0;
    int b = 0;
    int c = 0;
    for (c = 0; c < m+n ; c++) {
        if (arr1[a] < arr2[b]) {
            arr3[c] = arr1[a];
            a++;
        }
        else {
            arr3[c] = arr2[b];
            b++;
        }
    }
    for (c = c; c < m + n; c++) {
        if (a > b) {
            arr3[c] = arr1[a];
            a++;
        }
        else {
            arr3[c] = arr2[b];
            b++;
        }

    }
    for (i = 0; i < m + n; i++) {
        printf("%d ", arr3[i]);
    }

}