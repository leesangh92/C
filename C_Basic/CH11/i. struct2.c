/*
#include <stdio.h>

#define EMP_SZ 3

int main()
{
	typedef struct EMPLOYEE
	{
		char name[20];
		int salary;
		float height;
		char comAddr[50];
	} EMP;

	struct EMPLOYEE emps[EMP_SZ]; // 구조체 배열, 대괄호가 한 쌍 : 1차원 배열, 열 = 데이터

	int i, Cn = 0;

	for (i = 0; i < EMP_SZ; i++)
	{
		printf("성명 ? (입력 종료 : end))");
		gets(emps[i].name);
		//if(strcmp(emps[i].name, "end") == 0)
		if (!strcmp(emps[i].name, "end")) // ! = not
			// Cn = i; -> 끝까지 end를 안할 때 문제가 된다
			break;

		printf("월급 ? ");
		scanf("%d%*c", &emps[i].salary);

		printf("키(신장) ? ");
		scanf("%f%*c", &emps[i].height);

		printf("회사주소 ? ");
		gets(emps[i].comAddr);

		// Cn++; -> 여러 번 데이터를 연산하게 된다
	}

	Cn = i; // -> 한 번에 데이터를 연산한다 

	for(i = 0; i < Cn;i++)
		printf("%s, %d, %.2f, %s \n", emps[i].name, emps[i].salary, emps[i].height, emps[i].comAddr);

	return 0;
}
*/

#include <stdio.h>
#include <string.h>

#define EMP_SZ 100

int main()
{
	typedef struct EMPLOYEE
	{
		char name[20];
		int salary;
		float height;
		char comAddr[50];
	} EMP;

	struct EMPLOYEE emps[EMP_SZ], *ptr; // 구조체 배열, 대괄호가 한 쌍 : 1차원 배열, 열 = 데이터

	int i, Cn = 0;

	for (i = 0; i < EMP_SZ; i++)
	{
		printf("성명 ? (입력 종료 : end))");
		gets(emps[i].name);
		if (!strcmp(emps[i].name, "end")) // ! = not
			// Cn = i; -> 끝까지 end를 안할 때 문제가 된다
			break;

		printf("월급 ? ");
		scanf("%d%*c", &emps[i].salary);

		printf("키(신장) ? ");
		scanf("%f%*c", &emps[i].height);

		printf("회사주소 ? ");
		gets(emps[i].comAddr);

	}

	Cn = i;

	ptr = emps;

	while (1)
	{
		if (!strcmp(ptr->name, "end"))
			break;

		printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, ptr->height, ptr->comAddr);

		ptr++; // 구조체 배열 ptr의 자료형이 struct이기 때문에 struct의 크기만큼 증가 (80 증가)
	}

	return 0;
}