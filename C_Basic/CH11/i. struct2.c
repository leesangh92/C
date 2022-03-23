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

	struct EMPLOYEE emps[EMP_SZ]; // ����ü �迭, ���ȣ�� �� �� : 1���� �迭, �� = ������

	int i, Cn = 0;

	for (i = 0; i < EMP_SZ; i++)
	{
		printf("���� ? (�Է� ���� : end))");
		gets(emps[i].name);
		//if(strcmp(emps[i].name, "end") == 0)
		if (!strcmp(emps[i].name, "end")) // ! = not
			// Cn = i; -> ������ end�� ���� �� ������ �ȴ�
			break;

		printf("���� ? ");
		scanf("%d%*c", &emps[i].salary);

		printf("Ű(����) ? ");
		scanf("%f%*c", &emps[i].height);

		printf("ȸ���ּ� ? ");
		gets(emps[i].comAddr);

		// Cn++; -> ���� �� �����͸� �����ϰ� �ȴ�
	}

	Cn = i; // -> �� ���� �����͸� �����Ѵ� 

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

	struct EMPLOYEE emps[EMP_SZ], *ptr; // ����ü �迭, ���ȣ�� �� �� : 1���� �迭, �� = ������

	int i, Cn = 0;

	for (i = 0; i < EMP_SZ; i++)
	{
		printf("���� ? (�Է� ���� : end))");
		gets(emps[i].name);
		if (!strcmp(emps[i].name, "end")) // ! = not
			// Cn = i; -> ������ end�� ���� �� ������ �ȴ�
			break;

		printf("���� ? ");
		scanf("%d%*c", &emps[i].salary);

		printf("Ű(����) ? ");
		scanf("%f%*c", &emps[i].height);

		printf("ȸ���ּ� ? ");
		gets(emps[i].comAddr);

	}

	Cn = i;

	ptr = emps;

	while (1)
	{
		if (!strcmp(ptr->name, "end"))
			break;

		printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, ptr->height, ptr->comAddr);

		ptr++; // ����ü �迭 ptr�� �ڷ����� struct�̱� ������ struct�� ũ�⸸ŭ ���� (80 ����)
	}

	return 0;
}