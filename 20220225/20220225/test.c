#define _CRT_SECURE_NO_WARNINGS 1



/*
˼·��
1. 20Ԫ���ȿ��Ժ�20ƿ����ʱ������20����ƿ��
2. ������ƿ�ӿ��Ժ�һƿ������֮�󣬿�ƿ��ʣ�ࣺempty/2(������ƿ�ӻ��ĺ���������ƿ��) + empty%2(��������ƿ��)
3. ���ƿ�Ӹ�������1�������Լ����������ظ�2
*/
#include<stdio.h>
//int main(){
//
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//����1
//	total = money;
//	empty = money;
//	while (empty > 1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//	return 0;
//}


// ������������������ˮ����ƿ�ӻ��Ĺ���Ļ������Է��֣���ʵ���Ǹ��Ȳ����У�money*2-1
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//����2
//	if (money <= 0)
//	{
//		total = 0;
//	}
//	else
//	{
//		total = money * 2 - 1;
//	}
//	printf("total = %d\n", total);
//
//
//	return 0;
//}

//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty > 1) {
//		total = total + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//	return 0;
//}


////��������������ż��λ�ã�ʹ����λ��ǰ��
//void order(int arr[],int sz) {
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left < right) {
//		//��ǰ������ż�����ҵ���ֹͣ
//		while (left < right && arr[left] % 2 == 1) {
//			left++;
//		}
//		//�Ӻ���ǰ���������ҵ���ֹͣ
//		while (left < right && arr[right] % 2 == 0) {
//			right--;
//		}
//		//����ż������λ��
//		if (left < right) {
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	order(arr,sz);
//	//��ӡ����
//	int i = 0;
//	
//	for (i = 0; i < sz; i++) {
//		printf("%d", arr[i]);
//	}
//}

//ָ�������д��ڵ�����
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	//00000000000000000000000000000000   //ԭ��
//	//01111111111111111111111111111111
//	//10000000000000000000000000000000
//
//	 /*
//	 * ˵����printf�ڴ��������ʱ����������λ�Ĭ�ϴ������ֽڣ�����a+b�Ľ������һ�����ֽڵ��������յģ�
//	 ����Խ�硣��c�Ѿ���c = a + b��һ���ж��������λ��1������ֻ����300-256�õ���44�ˡ�
//
//������printf�ǿɱ�����ĺ��������Ժ��������������δ֪�ģ����Ա¹��㴫�����ʲô���ͣ�
//printfֻ��������͵Ĳ�ͬ�������ֲ�ͬ�ĳ��ȴ洢������8�ֽڵ�ֻ��long long��float��double
//��ע��float�ᴦ���double�ٴ��룩���������Ͷ���4�ֽڡ�������Ȼa + b��������char��
//ʵ�ʽ���ʱ������һ�����ֽ��������յġ����⣬��ȡʱ��%lld��%llx�����ͷ�ʽ��%f��%lf�ȸ����ͷ�ʽ��8�ֽڣ�
//������4�ֽڡ�
//	 */
//
//	
//
//	return 0;
//}

//���С�������char�ķ���
//unsigned int a = 0x1234; 
//unsigned char b = *(unsigned char*)&a;

//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

#include<stdio.h>
int main()
{
    int killer = 0;
    //�ֱ����������a,b,c,d,��˭������ʱ����3����˵���滰��һ����˵�˼ٻ�
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
            printf("�����ǣ�%c", killer);
    }
    return 0;
}