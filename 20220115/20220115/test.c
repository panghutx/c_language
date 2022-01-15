#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int main()
{
    //在屏幕上输出9*9乘法口诀表
    int i = 0;
    int j = 0;
    for (i = 1; i < 10; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%d ", j, i, i * j);
        }
        printf("\n");
    }
}
int main11()
{
    //求10个整数的最大值
    int arr[10] = { 0 };
    int i = 0;
    
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (i = 1; i < 10; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    printf("%d", max);
}
int main10()
{
    //计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
    int i = 0;
    double sum = 0;
    int flg = 1;
    for (i = 1; i <= 100; i++) {
        
        sum += flg * 1.0 / i;
        flg = -flg;
    }
    printf("%lf", sum);
}
int main9()
{
    //编写程序数一下 1到 100 的所有整数中出现多少个数字9
    int i = 0;
    int count = 0;
    for (i = 1; i <= 100; i++) {
        if (i % 10 == 9 || i / 10 % 10 == 9) {
            count++;
        }
    }
    printf("%d", count);
}
int main8()
{
    //打印100-200之间的素数
    int i,j = 0;
    for (i = 100; i <= 200; i++) {
        for (j = 2; j <=sqrt(i);j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > sqrt(i)) {
            printf("%d ", i);
        }
        
    }
}
int main7()
{
    //打印闰年
    int i = 0;
    for (i = 1000; i <= 2000; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            printf("%d ", i);
        }
    }
}

int main6()
{
    //求两个数的最大公约数
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int tmp = a;
    while (tmp != 0) {
        tmp = a % b; //10
        a = b;  
        b = tmp;
    }
    printf("%d", a);

}
int main4() {
    //打印1 - 100之间所有3的倍数的数字
    int i = 0;
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            printf("%d ",i);
        }
    }
}
int main3()
{
    //将三个整数数按从大到小输出。
    int x, y, z = 0;
    scanf("%d %d %d", &x, &y, &z);
    if (x < y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    if (x < z) {
        int tmp = x;
        x = z;
        z = tmp;
    }
    if (y < z) {
        int tmp = y;
        y = z;
        z = tmp;
    }
    printf("%d %d %d", x, y, z);
  

}

int MAX(int a, int b) {
    return a > b ? a : b;
}

int main2()
{
    //求出最大的数
    int x = 0;
    int y = 0;
    int z = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    int rst = MAX(MAX(x, y), z);
    printf("%d", rst);
}
int main1()
{
    //else匹配规则
    /*int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            printf("hello\n");
    else
        printf("panghu\n");
    return 0;*/
    //输出1-100所有奇数
    //int i = 0;
    //for (i = 0; i <= 100; i++) {
    //    if (i % 2 != 0) {
    //        printf("%d\n", i);
    //    }
    //}
    // //方法2
    //int i = 1;
    //while ( i < 100) {
    //    
    //    printf("%d ", i);
    //    i = i + 2;
    //}
    //swithc-case语句
    //int i = 0;
    //scanf("%d" , &i);
    //switch (i) {
    //case 1:
    //case 2:
    //case 3:
    //case 4:
    //case 5:
    //    printf("工作日\n");
    //    break;
    //case 6:
    //case 7:
    //    printf("休息日\n");
    //    break;
    //default:
    //    printf("输入错误");
    //    break;
    //}
    // 死循环
    //int i = 1;
    //while (i < 10) {
    //    if (i == 5)
    //        continue;
    //    printf("%d", i);
    //    i++;
    //}
    //putchar getchar
    //int ch=0;
    ////EOF  end of file
    //while (ch != EOF) {
    //    ch = getchar();
    //    putchar(ch);
        
   //}
    //缓存区问题
    //char arr[20] = { 0 };
    //printf("请输入密码\n");
    //scanf("%s" , arr);
    //int tmp = 0;
    //while ((tmp = getchar()) != '\n') {
    //    ;
    //}
    //printf("请确认密码 Y/N\n");
    //int ch = getchar();
    //
    //if ('Y' == ch) {
    //    printf("确认成功\n");
    //}
    //else {
    //    printf("确认失败\n");
    //}
    //打印数字字符
    //int ch = 0;
    //while ((ch = getchar()) != EOF)
    //{
    //    if (ch < '0' || ch > '9')
    //        continue;
    //    putchar(ch);
    //}
    //
    //break 跳出循环 continue
    //int i = 0;
    //for (i = 1; i < 10; i++) {
    //    if (i == 5)
    //        continue;
    //    printf("%d", i);
    //
    //}
    // 


    return 0;
}
