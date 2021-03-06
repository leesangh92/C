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
	char tmp[200]; // 임시 메모리 주소

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
		do
		{
			printf("성명 ? : (입력종료 : end) ");
			gets(tmp);
		} while (strlen(tmp) >= sizeof(ptr->name));

		strcpy(ptr->name, tmp);

		if (!strcmp(ptr->name, "end"))
			break;
		/*
		printf("월급 ? : ");
		scanf("%d", &ptr->salary);

		printf("키(신장) ? : ");
		scanf("%f%*c", &ptr->height);
		*/
		printf("회사 주소 ? : ");
		gets(tmp);
		
		ptr->comAddr = (char*)malloc(strlen(tmp) + 1); // 메모리 할당 및 주소 입력, NULL 때문에 길이 1 추가
		strcpy(ptr->comAddr, tmp);

		// 문자 배열을 본래 크기보다 큰 문자를 받으면 뒤 주소에 있는 데이터에 영향을 미친다.(덮어지고 지워진다)
		// 임시 메모리에서 조건을 제한하여 입력받는다.

		ptr->next = NULL;

		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	} // while(1) End.

	free(ptr); // end 노드 삭제

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
		free(prev->comAddr);
		free(prev);
	}

	free(ptr);
	ptr = NULL;

	return 0;
}