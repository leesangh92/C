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

	// 1. ��� ����
	while (1)
	{
		ptr = (struct EMPLOYEE*)malloc(sizeof(struct EMPLOYEE));
		if (ptr == NULL)
		{
			perror("Error ");
			exit(1);
		}

		printf("���� ? : (�Է����� : end) ");
		gets(ptr->name);

		if (!strcmp(ptr, "end"))
			break;

		printf("���� ? : ");
		scanf("%d", &ptr->salary);

		printf("Ű(����) ? : ");
		scanf("%f%*c", &ptr->height);

		printf("ȸ�� �ּ� ? : ");
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

	// 2. ��� ���
	ptr = head;
	while (ptr)
	{
		printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, ptr->height, ptr->comAddr);
		ptr = ptr->next;
	}

	// 3. ��� ����
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