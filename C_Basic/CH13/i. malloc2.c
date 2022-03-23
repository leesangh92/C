#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMPLOYEE {
	char name[20];
	int salary;
	float height;
	char comAddr[40];
};

int main()
{
	struct EMPLOYEE* ptr; // 구조체 포인터 변수

	ptr = (struct EMPLOYEE*)malloc(sizeof(struct EMPLOYEE));
	if (ptr == NULL)
	{
		perror("Error ");
		exit(1);
	}

	printf("성명 ? : ");
	gets(ptr -> name);
	printf("월급 ? : ");
	scanf("%d", &ptr -> salary);
	printf("키(신장) ? : ");
	scanf("%f%*c", &ptr -> height);
	printf("회사 주소 ? : ");
	gets(ptr -> comAddr);

	printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, ptr->height, ptr->comAddr);

	//free(ptr); // malloc으로 메모리 할당 후에는 메모리 사용 후 free()함수로 메모리를 해제해준다.
	ptr = NULL;

	return 0;
}