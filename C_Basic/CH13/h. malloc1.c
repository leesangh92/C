#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* ptr;

	while (1)
	{
		ptr = (char*)malloc(100);
		//ptr = calloc(sizeof(double), 20);
		//ptr = realloc(ptr, 2000);

		if (ptr == NULL)
		{
			perror("Error ");
			exit(1);
		}

		printf("input string ? ");
		gets(ptr);
		if (strcmp(ptr, "end") == 0)
			break;
		printf("%p, %s \n", ptr, ptr);

		//free(ptr); // 메모리 재활용, 힙 세그먼트에 할당받은 영역 해제(할당된 메모리의 일부만 해제 불가능), 여러 번 해제 불가능, 쓰레기값으로 해제
	}

	free(ptr);
	ptr = NULL;

	return 0;
}