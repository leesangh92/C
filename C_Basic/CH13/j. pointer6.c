#include <stdio.h>

int main()
{
	int count[4][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int i, j;
	int (*ptr)[3]; // 배열 포인터 변수 선언

	printf("%d, %d, %d \n", sizeof(count), sizeof(count[0]), sizeof(count[0][0]));
	printf("%p, %p, %p, %d \n", count, count[0], &count[0][0], count[0][0]);
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%p, %3d, ", &count[i][j], count[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%p, %3d, ", *(count + i) + j, *(*(count+i)+j)); // 다중 배열인 경우 안쪽(i)부터 변경 // [ => +, ] => *()
		printf("\n");
	}
	printf("\n");

	ptr = count;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%p, %3d, ", *ptr, *((*ptr)+j));
		ptr++;

		printf("\n");
	}

	return 0;
}