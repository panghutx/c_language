#define _CRT_SECURE_NO_WARNINGS 1

/* memmove example */
#include <stdio.h>
#include <string.h>
void* My_memmove(void* des, void* src, size_t count) {
	//�ؼ����ж�des��src��λ�ã���des<srcʱ����ǰ��󿽱���des>scr,�Ӻ���ǰ����
	void* rst = des;
	if(des<src) {
		while (count--) {
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}
	}
	else {
		des = (char*)des + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)des = *(char*)src;
			des = (char*)des - 1;
			src = (char*)src - 1;
		}
	}
//		//��->ǰ
//		while (count--)
//		{
//			*((char*)dest+count) = *((char*)src + count);
//		}
}
int main()
{
	char str[] = "memmove can be very useful......";
	My_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}