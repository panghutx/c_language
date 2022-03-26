#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//匿名结构体
struct {
	char name[40];
	int age;
} person, person_copy;

int main1()
{
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;
	/* using memcpy to copy structure: */
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	return 0;
}
void* My_memcpy(void* dest, void* src, size_t count) {
	void* rst = dest;
	while (count--) {
		*(char*)dest = *(char*)src;
		dest=(char*)dest+1;
		src = (char*)src + 1;
	}
	return rst;
}
int main() {
	int arr1[9] = { 1,2,3,4,5,6,7,8 };
	int arr2[9] = { 0 };
	My_memcpy(arr2, arr1, 32);
	
}