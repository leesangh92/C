#include <stdio.h>

int main()
{
	char ch = 'A';
	int num = 100;
	double dnum = 1.5;

	void* ptr; // void ?? ??????

	ptr = &ch;
	printf("%c \n", *(char*)ptr);

	ptr = &num;
	printf("%d \n", *(int*)ptr);

	ptr = &dnum;
	printf("%lf \n", *(double*)ptr);


	return 0;
}