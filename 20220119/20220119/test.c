#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
int pow(int n,int k)
{
	
	if (k == 0)
		return 1;
	else {
		return n*pow(n,k-1);
	}
}
int main()
{
	printf("%d",pow(2,4));
}
//쳲�������
//�ݹ�
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}//�ǵݹ�
int fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
	
}
int main6()
{
	printf("%d %d",fib(7),fib1(7));
	return 0;
}
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
int DigitSum(int n)
{
	if (n > 9)
		return DigitSum(n / 10) +n% 10;
	else 
		return n;	
}
int main5()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",DigitSum(n));

}
//�������ַ����ַ���������
void reverse_string(char* string)
{
	//char *left = arr;
	//char* right = strlen(arr) - 1;
	int left = 0;
	int right = 4;
	while (left <= right) {
		char tmp = string[left];
		string[left] = string[right];
		string[right] = tmp;
		left++;
		right--;
	}
	
}
int main4()
{
	char arr[] = "abcde";
	reverse_string(arr);
	int i = 0;
	for (i = 0; i < 5;i++)
		printf("%c ", arr[i]);
}


//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ǵݹ�
my_Strlen(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;		
}
//�ݹ�
int my_Strlen1(char* arr) 
{
	if (*arr != '\0')
		return 1 + my_Strlen1(arr+1);
	else
		return 0;
}
int main3() {
	char arr[] = "abcde";
	printf("%d\n",my_Strlen(arr)); //�ǵݹ�
	printf("%d\n",my_Strlen1(arr));//�ݹ�
}
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//�ݹ�
int factor(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factor(n - 1);
}
//�ǵݹ�
int factor1(int n)
{
	int i = 0;
	int rst = 1;
	for (i = 1; i <= n; i++) {
		rst = rst * i;
	}
	return rst;
}
int main2()
{
	int n = 0;
	scanf("%d", &n);
	int rst=factor(n);
	int rst1 = factor1(n);
	printf("%d %d", rst, rst1);
	return 0;
}
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void func(int n)
{
	if (n > 9)
		func(n / 10);
	printf("%d ", n % 10);
}
int main1()
{
	int a = 0;
	scanf("%d", &a);
	func(a);
	return 0;
}