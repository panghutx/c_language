#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//ˮ�ɻ���  153 = 1^3+5^3+3^3
int main1()
{
	
	int i = 0;
	for (i = 1; i < 1000000; i++) {
		//1.�ж�λ��
		int tmp = i;
		int count = 0;
		while (tmp) {
			count++;
			tmp = tmp / 10;
		}
		//2.����ݴ�֮��
		tmp = i;
		int sum = 0;
		while (tmp) {
			sum += (int)pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3.�ж��Ƿ����
		if (sum == i) {
			printf("%d ", i);
		}
		
	}

}

int main2()
{
	//����һ���ַ����ж��Ƿ�Ϊ��ĸ
	char n = 0;
	scanf("%c", &n);
	if (n >= 'a' && n <= 'z' || n>='A' && n <= 'Z') {
		printf("Yes");
	}
	else {
		printf("No");
	}
}

int main4()
{
	//�����ַ���
	//1.һ��һ���ƶ�
	//2.���η�ת
	char arr[] = "abcdef";
	int len = strlen(arr);
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		char tmp = arr[0];
		for (j = 0; j < len-1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[j] = tmp;
		
	}
	printf("%s", arr);

}
//��η�ת--�������ַ���
//abcdef   3
//cba
//fed
//defabc
void reverse(char* left,char* right) {
	
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
int main5()
{
	char arr[] = "abcdefg";
	int n = 0;
	scanf("%d", &n);
	int len = strlen(arr);
	reverse(arr,arr+n-1);
	reverse(arr + n, arr + len - 1);
	reverse(arr, arr + len - 1);
	printf("%s", arr);

}
//��������ϲ�
//#include<stdio.h>
//int main()
//{
//	int m, n = 0;
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int arr1[n];
//	int arr2[m];
//	int arr3[m + n];
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++) {
//		scanf("%d", &arr2[i]);
//	}
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (a < n && b < m) {
//		if (arr1[a] < arr2[b]) {
//			arr3[c++] = arr1[a++];
//		}
//		else {
//			arr3[c++] = arr2[b++];
//		}
//	}
//	while (a < n) {
//		arr3[c++] = arr1[a++];
//	}
//	while (b < m) {
//		arr3[c++] = arr2[b++];
//	}
//	for (i = 0; i < m + n; i++) {
//		printf("%d ", arr3[i]);
//	}
//
//}
void search(int arr[3][3], int r, int c,int k) {
	//�����Ͻǿ�ʼ��
	int x = 0;
	int y = c - 1;
	while (x<r&&y>=0)
	{

		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k) {
			x++;
		}
		else {
			printf("�ҵ��ˣ��±���%d %d", x, y);
			return;
		}
	}
	printf("û�ҵ�");
}
int main7()
{
	//���Ͼ��󣬲���ĳ�������Ƿ����
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	search(arr, 3, 3, 7);
}

//ԭ��ɾ�������е�Ԫ��
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++) {
		if (arr[i] == n) {
			break;
		}
	}
	while (i < len - 1) {
		int* j = &arr[i + 1];
		*(arr + i) = *j;
		i++;
		j++;
	}
	i = 0;
	for (i = 0; i < len-1; i++) {
		printf("%d ", arr[i]);
	}

}