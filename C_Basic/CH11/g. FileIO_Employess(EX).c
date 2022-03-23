//employess.c
#include <stdio.h>
#include <string.h>
#define EMP_SZ 30

char names[EMP_SZ][20], comAddr[EMP_SZ][50];
int salary[EMP_SZ], Cn=0;

int main()
{
	int choice, stop = 1;

	emp_load(); //사원정보 메모리 적재

	while (stop)
	{
		printf("\n1. 사원정보 입력 \n");
		printf("2. 사원정보 출력 \n");
		printf("3. 사원정보 검색 \n");
		printf("4. 사원정보 저장 \n");
		printf("5. 프로그램 종료 \n");
		printf("Select ? (1~5) ");
		scanf("%d%*c", &choice);  //1, 3, 7,.. 4, 

		switch (choice)
		{
		case 1: emp_input();
			break;
		case 2: emp_output();
			break;
		case 3: emp_find();
			break;
		case 4: emp_save();
			break;
		case 5: stop = 0;
			break;
		}

		//while (getchar() != '\n');

	} //while(stop) end

	printf("End.\n");
	
	return 0;
} //main() end

emp_input() //데이터 입력
{
	int i;

	for (i = Cn; i < EMP_SZ; i++)
	{
		printf("\n성명 ? (입력종료:end) ");
		gets(names[i]); //kim['\0], lee, han

		if (strcmp(names[i], "end") == 0)
			break;
		printf("월급 ? ");
		scanf("%d%*c", &salary[i]); //1000[enter], 2000, 3000
		printf("회사주소 ? ");
		gets(comAddr[i]);  //seoul, busan, incheon
	}

	Cn = i;

} //emp_input() end

emp_output() //데이터 출력
{
	int i, salTot = 0;

	printf("\n");
	for (i = 0; i < Cn; i++)
	{
		printf("%s, %d, %s \n", names[i], salary[i], comAddr[i]);
		salTot += salary[i];
	}
	if (Cn)
	{
		printf("====================\n");
		printf("월급평균: %d \n", salTot / Cn);
		printf("====================\n");
	}

} //emp_output() end

emp_find() //검색 알고리즘
{
	int i, found;
	char s_name[20];
	
	while (1)
	{
		printf("\n검색할 성명 ? (검색종료:end) ");
		gets(s_name);   //lee,kim, sun ... end
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1;
		for (i = 0; i < Cn; i++)
		{
			if (strcmp(names[i], s_name) == 0)
			{
				found = 0;
				printf("%s, %d, %s \n", names[i], salary[i], comAddr[i]);
				//break; 
			}
		}

		if (found)
			printf("%s, Not found!!! \n", s_name);

	} //while (1) end

} //emp_find() end


emp_save()
{
	FILE* fp;

	fp = fopen("emps.dat", "wb");
	if (fp == NULL)
	{
		perror("Error : ");
		exit(1);
	}

	fwrite(&Cn, sizeof(Cn), 1, fp);
	fwrite(names, sizeof(names[0]) , Cn , fp);
	fwrite(salary, sizeof(salary[0]), Cn, fp);
	fwrite(comAddr, sizeof(comAddr[0]), Cn,fp);
	fclose(fp);

	printf("emps.dat 저장. \n");

} //emp_save() end

emp_load()
{
	FILE* fp;

	fp = fopen("emps.dat", "rb");
	if (fp == NULL)
	{
		perror("Error : ");
		return;
	}

	fread(&Cn, sizeof(int), 1, fp);
	fread(names, sizeof(names[0]), Cn, fp);
	fread(salary, sizeof(int), Cn, fp);
	fread(comAddr, sizeof(comAddr[0]), Cn, fp);

	fclose(fp);

	printf("emps.dat load. \n");

} //emp_load() end