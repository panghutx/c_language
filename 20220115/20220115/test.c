#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int main()
{
    //����Ļ�����9*9�˷��ھ���
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
    //��10�����������ֵ
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
    //����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
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
    //��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
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
    //��ӡ100-200֮�������
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
    //��ӡ����
    int i = 0;
    for (i = 1000; i <= 2000; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            printf("%d ", i);
        }
    }
}

int main6()
{
    //�������������Լ��
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
    //��ӡ1 - 100֮������3�ı���������
    int i = 0;
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            printf("%d ",i);
        }
    }
}
int main3()
{
    //���������������Ӵ�С�����
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
    //���������
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
    //elseƥ�����
    /*int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            printf("hello\n");
    else
        printf("panghu\n");
    return 0;*/
    //���1-100��������
    //int i = 0;
    //for (i = 0; i <= 100; i++) {
    //    if (i % 2 != 0) {
    //        printf("%d\n", i);
    //    }
    //}
    // //����2
    //int i = 1;
    //while ( i < 100) {
    //    
    //    printf("%d ", i);
    //    i = i + 2;
    //}
    //swithc-case���
    //int i = 0;
    //scanf("%d" , &i);
    //switch (i) {
    //case 1:
    //case 2:
    //case 3:
    //case 4:
    //case 5:
    //    printf("������\n");
    //    break;
    //case 6:
    //case 7:
    //    printf("��Ϣ��\n");
    //    break;
    //default:
    //    printf("�������");
    //    break;
    //}
    // ��ѭ��
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
    //����������
    //char arr[20] = { 0 };
    //printf("����������\n");
    //scanf("%s" , arr);
    //int tmp = 0;
    //while ((tmp = getchar()) != '\n') {
    //    ;
    //}
    //printf("��ȷ������ Y/N\n");
    //int ch = getchar();
    //
    //if ('Y' == ch) {
    //    printf("ȷ�ϳɹ�\n");
    //}
    //else {
    //    printf("ȷ��ʧ��\n");
    //}
    //��ӡ�����ַ�
    //int ch = 0;
    //while ((ch = getchar()) != EOF)
    //{
    //    if (ch < '0' || ch > '9')
    //        continue;
    //    putchar(ch);
    //}
    //
    //break ����ѭ�� continue
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
