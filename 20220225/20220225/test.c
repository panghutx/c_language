#define _CRT_SECURE_NO_WARNINGS 1



/*
思路：
1. 20元首先可以喝20瓶，此时手中有20个空瓶子
2. 两个空瓶子可以喝一瓶，喝完之后，空瓶子剩余：empty/2(两个空瓶子换的喝完后产生的瓶子) + empty%2(不够换的瓶子)
3. 如果瓶子个数超过1个，可以继续换，即重复2
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
//	//方法1
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


// 方法二：按照上述喝水和用瓶子换的规则的话，可以发现，其实就是个等差数列：money*2-1
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//方法2
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


////调整数组中奇数偶数位置，使奇数位于前面
//void order(int arr[],int sz) {
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left < right) {
//		//从前往后找偶数，找到后停止
//		while (left < right && arr[left] % 2 == 1) {
//			left++;
//		}
//		//从后往前找奇数，找到后停止
//		while (left < right && arr[right] % 2 == 0) {
//			right--;
//		}
//		//奇数偶数互换位置
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
//	//打印数组
//	int i = 0;
//	
//	for (i = 0; i < sz; i++) {
//		printf("%d", arr[i]);
//	}
//}

//指出代码中存在的问题
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
//	//00000000000000000000000000000000   //原码
//	//01111111111111111111111111111111
//	//10000000000000000000000000000000
//
//	 /*
//	 * 说明：printf在传入参数的时候如果是整形会默认传入四字节，所以a+b的结果是用一个四字节的整数接收的，
//	 不会越界。而c已经在c = a + b这一步中丢弃了最高位的1，所以只能是300-256得到的44了。
//
//※由于printf是可变参数的函数，所以后面参数的类型是未知的，所以甭管你传入的是什么类型，
//printf只会根据类型的不同将用两种不同的长度存储。其中8字节的只有long long、float和double
//（注意float会处理成double再传入），其他类型都是4字节。所以虽然a + b的类型是char，
//实际接收时还是用一个四字节整数接收的。另外，读取时，%lld、%llx等整型方式和%f、%lf等浮点型方式读8字节，
//其他读4字节。
//	 */
//
//	
//
//	return 0;
//}

//大端小端问题和char的访问
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
    //分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
    for (killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
            printf("凶手是：%c", killer);
    }
    return 0;
}