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

		//free(ptr); // �޸� ��Ȱ��, �� ���׸�Ʈ�� �Ҵ���� ���� ����(�Ҵ�� �޸��� �Ϻθ� ���� �Ұ���), ���� �� ���� �Ұ���, �����Ⱚ���� ����
	}

	free(ptr);
	ptr = NULL;

	return 0;
}