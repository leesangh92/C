#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMPLOYEE
{
	char name[20];
	int salary;
	float height;
	char *comAddr; // 4byte
	struct EMPLOYEE* next;
};

int main()
{
	struct EMPLOYEE* ptr, * prev;
	struct EMPLOYEE* head, * tail;
	char tmp[200]; // �ӽ� �޸� �ּ�

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
		do
		{
			printf("���� ? : (�Է����� : end) ");
			gets(tmp);
		} while (strlen(tmp) >= sizeof(ptr->name));

		strcpy(ptr->name, tmp);

		if (!strcmp(ptr->name, "end"))
			break;
		/*
		printf("���� ? : ");
		scanf("%d", &ptr->salary);

		printf("Ű(����) ? : ");
		scanf("%f%*c", &ptr->height);
		*/
		printf("ȸ�� �ּ� ? : ");
		gets(tmp);
		
		ptr->comAddr = (char*)malloc(strlen(tmp) + 1); // �޸� �Ҵ� �� �ּ� �Է�, NULL ������ ���� 1 �߰�
		strcpy(ptr->comAddr, tmp);

		// ���� �迭�� ���� ũ�⺸�� ū ���ڸ� ������ �� �ּҿ� �ִ� �����Ϳ� ������ ��ģ��.(�������� ��������)
		// �ӽ� �޸𸮿��� ������ �����Ͽ� �Է¹޴´�.

		ptr->next = NULL;

		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	} // while(1) End.

	free(ptr); // end ��� ����

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
		free(prev->comAddr);
		free(prev);
	}

	free(ptr);
	ptr = NULL;

	return 0;
}