#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMPLOYEE 
{
	char name[20];
	int salary;
	float height;
	char comAddr[40];
	struct EMPLOYEE* next;
};

int main()
{
	struct EMPLOYEE *ptr, *prev;
	struct EMPLOYEE *head, *tail;

	head = tail = NULL;

	// 1. 노드 생성
	while (1)
	{
		ptr = (struct EMPLOYEE*)malloc(sizeof(struct EMPLOYEE));
		if (ptr == NULL)
		{
			perror("Error ");
			exit(1);
		}

		printf("성명 ? : (입력종료 : end) ");
		gets(ptr->name);

		if (!strcmp(ptr, "end"))
			break;

		printf("월급 ? : ");
		scanf("%d", &ptr->salary);

		printf("키(신장) ? : ");
		scanf("%f%*c", &ptr->height);

		printf("회사 주소 ? : ");
		gets(ptr->comAddr);

		ptr->next = NULL;

		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	} // while(1) End.

	// 2. 노드 출력
	ptr = head;
	while (ptr)
	{
		printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, ptr->height, ptr->comAddr);
		ptr = ptr->next;
	}

	// 3. 노드 해제
	ptr = head;

	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
		free(prev);
	}

	free(ptr);
	ptr = NULL;

	return 0;
}